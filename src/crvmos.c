#include "crvmos.h"


int os_main(void)
{
	lib_puts("type something:");
	char str[100];
	lib_gets(str);
	lib_puts("\r\nyou type:");
	lib_puts(str);
	lib_puts("\r\n");
	while (1) {}
	return 0;
}
