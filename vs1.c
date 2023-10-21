#include "shell.h"

/**
 * is_chain - check if char in buffer is a chain delimeter
 * @info: info_t
 * @buf: characer pointer buf
 * @p: size t pointer p
 * Return: 1
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t jago = *p;

	if (buf[jago] == '|' && buf[jago + 1] == '|')
	{
		buf[jago] = 0;
		jago++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[jago] == '&' && buf[jago + 1] == '&')
	{
		buf[jago] = 0;
		jago++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[jago] == ';')
	{
		buf[jago] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = jago;
	return (1);
}


/**
 * replace_string - replaces
 * @old: pointer to a pointer
 * @new: pointer to new
 * Return: 1
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * replace_alias - replaces aliases
 * @info: info t
 * Return: 1
 */
int replace_alias(info_t *info)
{
	int musa;
	list_t *node;
	char *p;

	musa = 0;
	for (; musa < 10; musa++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = custom_strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
