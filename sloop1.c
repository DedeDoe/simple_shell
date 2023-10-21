#include "shell.h"
#include <stdio.h>
/**
 * hsh - main shell
 * @info: info_t
 * @av: argument value
 * Return: 0
 */
int hsh(info_t *info, char **av)
{
	ssize_t rabo = 0;
	int z_ret = 0;

	while (rabo != -1 && z_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rabo = get_input(info);
		if (rabo != -1)
		{
			set_info(info, av);
			z_ret = find_builtin(info);
			if (z_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (z_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (z_ret);
}

/**
 * find_builtin - check for builtin command
 * @info: info_t
 * Return:
 */
int find_builtin(info_t *info)
{
	int indomie, zuilt_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	indomie = 0;
	while (builtintbl[indomie].type)
	{
		if (custom_strcmp(info->argv[0], builtintbl[indomie].type) == 0)
		{
			info->line_count++;
			zuilt_in_ret = builtintbl[indomie].func(info);
			break;
		}
		indomie++;
	}
	return (zuilt_in_ret);
}
