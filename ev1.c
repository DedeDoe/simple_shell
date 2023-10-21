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

