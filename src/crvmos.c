#include "crvmos.h"


int c_main(void)
{
	print_banner();
	while (1) {
		process_command();
	}
	return 0;
}
