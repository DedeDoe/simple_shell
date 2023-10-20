#include "shell.h"

/**
 * custom_strdup- This function duplicates a string
 * @original : Character original
 * Return: new_dup
 */
char *custom_strdup(char *original)
{
	size_t length; 
	char *new_dup;

	if (original == NULL)
	{
	return (NULL);
	}

	length = custom_strlen(original) + 1;
	new_dup = (char *)malloc(length);

	if (new_dup != NULL)
	{
	_strcpy(new_dup, original);
	}

	return (new_dup);
}
