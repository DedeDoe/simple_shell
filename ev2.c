#include "shell.h"
#include <stdio.h>

/**
 * _mysetenv - Function modifies or initializes env var
 * @info: info_t info
 * Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Number of arguments incorrect\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * populate_env_list - funtion populates the env list.
 * @info: info_t info
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	unsigned int i = 0;

	for (; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _myunsetenv - deletes an env var
 * @info: info_t info
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int anto;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	anto = 1;
	while (anto <= info->argc)
	{
		_unsetenv(info, info->argv[anto]);
		anto++;
	}

	return (0);
}
