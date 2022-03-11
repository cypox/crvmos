#pragma once

#include <stdint.h>

#include "io.h"
#include "string.h"


void print_banner()
{
  puts("   ___                               \n\r");
	puts("  / __\\ _   _  _ __    ___  __  __   \n\r");
	puts(" / /   | | | || '_ \\  / _ \\ \\ \\/ /   \n\r");
	puts("/ /___ | |_| || |_) || (_) | >  <    \n\r");
	puts("\\____/  \\__, || .__/  \\___/ /_/\\_\\   \n\r");
	puts("   __   ____/ |_|                    \n\r");
	puts("  /__\\ (_) ___   ___         /\\   /\\ \n\r");
	puts(" / \\// | |/ __| / __| _____  \\ \\ / / \n\r");
	puts("/ _  \\ | |\\__ \\| (__ |_____|  \\ V /  \n\r");
	puts("\\/ \\_/ |_|____/ \\____    ___  ___/   \n\r");
	puts("   /\\/\\  (_) _ __  (_)  /___\\/ _\\    \n\r");
	puts("  /    \\ | || '_ \\ | | //  //\\ \\     \n\r");
	puts(" / /\\/\\ \\| || | | || |/ \\_// _\\ \\    \n\r");
	puts(" \\/    \\/|_||_| |_||_|\\___/  \\__/    \n\r");
	puts("                                     \n\r");
}

void process_command()
{
  puts("crvmos# ");
	char cmd[64];
	gets(cmd);
  puts("\r\n");
  execute(cmd);
}

void execute(const char* cmd)
{
  if(!strcmp(cmd, "help"))
  {
    print_banner();
  }
}
