#include "shell.h"

/**
 * find_cmd - finds command
 * @info: info_t
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *top = NULL;
	int ama = 0;
	int kko = 0;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (; info->arg[ama]; ama++)
		if (!is_delim(info->arg[ama], " \t\n"))
			kko++;
	if (!kko)
		return;

	top = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (top)
	{
		info->path = top;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "cannot be found\n");
		}
	}
}
