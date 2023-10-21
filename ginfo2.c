#include "shell.h"
#include <stdio.h>

/**
 * clear_info - pointer info initializes
 * @info: info_t pointer info
 * Return: no return
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - sets info_t pointer
 * @info: info pointer
 * @av: pointer to a pointer argument value
 * Return: no return
 */
void set_info(info_t *info, char **av)
{
	int vero;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = custom_strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		vero = 0;
		while (info->argv && info->argv[vero])
		{
			vero++;
		}
		info->argc = vero;

		replace_alias(info);
		replace_vars(info);
	}
}
