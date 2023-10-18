#include "main.h"
#include <stdio.h>

/**
 * exit_cmd- implements exit
 * Return: Nothing
 */

void exit_cmd(void)
{
	write(STDOUT_FILENO, "clossing session ..... \n", 24);
	exit(0);
}
