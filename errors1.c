#include "shell.h"

/**
 * _erratoi - change string to int
 * @s: character pointer s
 * Return: 0
 */

int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints error
 * @info: info_t info
 * @estr: character pointer estr
 * Return: 0
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints base 10
 * @input: int input
 * @fd: int fd
 * Return: total of printed numbers
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i = 1000000000;
	unsigned int _abs_, current;
	int count = 0;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - function clone of itoa
 * @num: long int num
 * @base: int base
 * @flags: int flags
 * Return: ptr
 */
char *convert_number(long int num, int base, int flags)
{

	char sign = 0;
	char *ptr;
	static char *array;
	static char buffer[50];
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function skips #
 * @buf: character pointer buf
 * Return: 0
 */
void remove_comments(char *buf)
{
	int ino = 0;

	for (; buf[ino] != '\0'; ino++)
		if (buf[ino] == '#' && (!ino || buf[ino - 1] == ' '))
		{
			buf[ino] = '\0';
			break;
		}
}
