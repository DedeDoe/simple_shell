#include "main.h"
#include <stdio.h>

/**
 * address- finds the address
 * @path: the path
 * @arg: the argument passed
 * Return: a pointer
 */

char *address(char *path, char *arg)
{
	char *copy_path;
	char *path_token;
	char delimeter = ':';
	char *_filepath;
	/* char *buffer; */

	copy_path = custom_strdup(path);
	path_token = strtok(copy_path, &delimeter);

	_filepath = malloc(strlen(arg) + strlen(path_token) + 2);
	while (path_token != NULL)
	{
		custom_strcpy(_filepath, path_token);
		custom_strcat(_filepath, "/");
		custom_strcat(_filepath, arg);
		custom_strcat(_filepath, "\0");

		if (access(_filepath, X_OK) == 0)
		{
			free(copy_path);
			return (_filepath);
		}
		path_token = strtok(NULL, &delimeter);
	}

	free(_filepath);
	free(copy_path);

		return (arg);
	return (NULL);
}

/**
 * getpath- finds the path of a command
 * @arg : the command entered
 * Return: NULL
 */

char *getpath(char *arg)
{
	char *path;

	path = getenv("PATH");
		if (path)
		{
			path = address(path, arg);
			return (path);
		}
	return (NULL);
}
