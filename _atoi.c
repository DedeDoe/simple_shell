#include "shell.h"
#include <stdio.h>

/**
 * interactive- Makes shll interactive
 * @info: info_t info
 * Return: 1
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim- Function checks for delimiters
 * @c: Character c
 * @delim: Character delim
 * Return: 1
 */
int is_delim(char c, char *delim)
{
	for (; *delim; delim++)
	{
		if (*delim == c)
		{
			return (1);
		}
	}
	return (0);

}

/**
 * _isalpha- This function checks for alphabets
 * @c: Int c
 * Return: 1
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - This function changes alphabets to integers
 * @s: Character pointer s
 * Return: 0
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	size_t result = 0;

	i = 0;
	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
