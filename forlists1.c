#include "shell.h"
#include <stdio.h>

/**
 * get_node_index - get node index
 * @head: list_t pointer h
 * @node: list_t pointer node
 * Return: index or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	unsigned int tapo;

	tapo = 0;
	while (head)
	{
		if (head == node)
			return (tapo);
		head = head->next;
		tapo++;
	}
	return (-1);
}


/**
 * list_len - counts length of list
 * @h: constant list_t pointer h
 * Return: size
 */
size_t list_len(const list_t *h)
{
	unsigned int mali;

	mali = 0;
	while (h)
	{
		h = h->next;
		mali++;
	}
	return (mali);
}
