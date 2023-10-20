#include "shell.h"
#include <stdio.h>

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
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
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
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
