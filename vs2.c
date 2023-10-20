#include "shell.h"
#include <stdio.h>

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t jj = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			jj = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			jj = len;
		}
	}

	*p = jj;
}


/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!custom_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				custom_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!custom_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				custom_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				custom_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], custom_strdup(""));

	}
	return (0);
}
