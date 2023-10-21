#include "shell.h"

/**
 * print_list - function prints every elements of a linked list
 * @h: constant list_t pointer h
 * Return: size
 */
size_t print_list(const list_t *h)
{
	unsigned int wapi;

	wapi = 0;
	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		wapi++;
	}
	return (wapi);
}
