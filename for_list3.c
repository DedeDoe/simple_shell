#include "shell.h"
#include <stdio.h>

/**
 * print_list_str - prints string element
 * @h: list_t pointer h
 * Return: size
 */
size_t print_list_str(const list_t *h)
{
	unsigned int item;

	item = 0;
	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		item++;
	}
	return (item);
}
