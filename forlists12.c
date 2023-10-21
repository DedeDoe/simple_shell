#include "shell.h"
#include <stdio.h>

/**
 * list_to_strings - ret string array
 * @head: list_t pointer
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
	char **strs;
	char *str;
	list_t *node = head;
	unsigned int i = list_len(head), j;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(custom_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * node_starts_with - ret node of strings that start with a prefix
 * @node: list_t  pointer node
 * @prefix: characer pointer prefix
 * @c: the next character after prefix to match
 * Return: NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
