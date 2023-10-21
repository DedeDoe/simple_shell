#include "shell.h"
#include <stdio.h>

/**
 * _myenv- prints environment variables
 * @info: info_t info
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv- value of env variable
 * @info : info_t info
 * @name : Constant character name
 * Return: name of env variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *peter;

	while (node)
	{
		peter = starts_with(node->str, name);
		if (peter && *peter)
			return (peter);
		node = node->next;
	}
	return (NULL);
}

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
