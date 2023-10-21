#include "shell.h"
#include <stdio.h>


/**
 * starts_with - entry
 * @haystack: const char haystack
 * @needle: const char needle
 * Return: address of haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest:char dest
 * @src: character src
 * Return: ret
 */
char *_strcat(char *dest, char *src)
{
	char *ret;

	ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
