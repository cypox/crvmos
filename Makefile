RISCVPATH=../gnu-toolchain/riscv64-elf/bin
CC = $(RISCVPATH)/riscv64-unknown-elf-gcc
CFLAGS = -Wall -nostdlib -fno-builtin -mcmodel=medany -march=rv32ima -mabi=ilp32

OBJDUMP = riscv64-unknown-elf-objdump

SRC_DIR = src
INC_DIR = -Iinclude/
BIN_DIR = build

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none
QFLAGS += -drive if=none,format=raw,file=$(BIN_DIR)/hdd.dsk,id=x0
QFLAGS += -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0

OBJ = \
$(SRC_DIR)/boot.s \
$(SRC_DIR)/crvmos.c \

all: clean crvmos.elf hdd.dsk qemu

test: clean crvmos.elf qemu

crvmos.elf: $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -T crvmos.ld $(INC_DIR) -o $(BIN_DIR)/crvmos.elf $^

qemu: $(TARGET) hdd.dsk
	@qemu-system-riscv32 -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	$(QEMU) $(QFLAGS) -kernel $(BIN_DIR)/crvmos.elf

clean:
	rm -f build

hdd.dsk:
	dd if=/dev/urandom of=$(BIN_DIR)/hdd.dsk bs=1048576 count=32

.PHONY : debug
debug: clean crvmos.elf hdd.dsk
	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel os.elf -s -S &
	@${GDB} crvmos.elf -q -x ./gdbinit
