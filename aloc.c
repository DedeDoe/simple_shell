#include "shell.h"

/**
 * _memset- This function puts a constant byte in memory
 * @s: Character pointer s
 * @b: Character b
 * @n: Unsigned int n
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	size_t u = 0;

	for (; u < n; u++)
		s[u] = b;
	return (s);
}

/**
 * _realloc- This function reallocates memory
 * @ptr: void pointer
 * @old_size: Unsigned int old_size
 * @new_size: Unsigned int new_size
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *bobo;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	bobo = malloc(new_size);
	if (!bobo)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		bobo[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (bobo);
}
