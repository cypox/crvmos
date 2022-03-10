#include "crvmos.h"


int c_main(void)
{
	puts("type something:");
	char str[100];
	gets(str);
	puts("\r\nyou type:");
	puts(str);
	puts("\r\n");
	while (1) {}
	return 0;
}
