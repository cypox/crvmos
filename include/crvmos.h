#pragma once

#include <stdint.h>

#define UART        0x10000000
#define UART_THR    (uint8_t*)(UART+0x00)
#define UART_RHR    (uint8_t*)(UART+0x00)
#define UART_LSR    (uint8_t*)(UART+0x05)
#define UART_LSR_RX_READY 0x01
#define UART_LSR_EMPTY_MASK 0x40


void lib_putc(char ch) {
	while ((*UART_LSR & UART_LSR_EMPTY_MASK) == 0);
	*UART_THR = ch;
}

void lib_puts(char *s) {
	while (*s) lib_putc(*s++);
}

char lib_getc() {
	while ((*UART_LSR & UART_LSR_RX_READY) == 0);
	return *UART_RHR;
}

int lib_gets(char *s) {
	char *p = s;
	while (1) {
		char ch = lib_getc();
		lib_putc(ch);
		if (ch == '\n' || ch == '\r') break;
		*p++ = ch;
	}
	*p = '\0';
	return p-s;
}
