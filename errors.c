#include "shell.h"
#include <stdio.h>

/**
 *_eputs - function prints input string
 * @str: character pointer
 *
 * Return: PRINT NOTHING
 */
void _eputs(char *str)
{
	int aba;

	aba = 0;

	if (!str)
		return;

	for (; str[aba] != '\0'; aba++)
	{
		_eputchar(str[aba]);
	}

}

/**
 * _eputchar - copies character c to stderr
 * @c: character c
 * Return:  1
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - inputs c to specified filedescriptor
 * @c: character c
 * @fd: int fd
 * Return: 1
 */
int _putfd(char c, int fd)
{

	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - writes an input
 * @str: character pointer str
 * @fd: int fd
 * Return:  number of chars
 */
int _putsfd(char *str, int fd)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
