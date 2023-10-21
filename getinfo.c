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

/**
 * free_info - frees fields
 * @info: info_t
 * @all: int all
 * Return: no return
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
