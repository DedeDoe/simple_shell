#include "shell.h"
#include <stdio.h>

/**
 * add_node_end - adds node
 * @head: list_t pointer to a pointer head
 * @str: character pointer str
 * @num: int num
 * Return: size
 */
list_t *add_node_end(list_t **head, char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = custom_strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}


/**
 * delete_node_at_index - deletes nodex
 * @head: list_t pointer to a pointer head
 * @index: unsigned int index
 * Return: 1
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	size_t i = 0;
	list_t *node, *prev_node;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
