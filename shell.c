#include "main.h"
#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	/* Initialization of variables */
	char *prompt = "ds$ ", *user_input = NULL, *new_line = "\n";
	char *av[30], *path, *missing_command = "command does not exist";
	char delimeter = ' ';
	size_t input_size = 0;
	ssize_t getline_value;
	char *childp_fail = "child process failed to start";
	pid_t child_pid;
	int status, execve_return;

	while (1)
	{
	if (isatty(0))
	custom_print(prompt);
	getline_value = getline(&user_input, &input_size, stdin);

	/* condition for "ctrl + D" to exit - if getline returns -1. */
		if (getline_value == -1)
		{
			free(user_input);
			exit(0);
		}

	int i = 0;

	while (user_input[i])
	{
		if (user_input[i] == *new_line)
			user_input[i] = 0;
		i++;
	}

	/* Tokenize user input */
	int index = 0;

	av[index] = strtok(user_input, &delimeter);
	while (av[index])
	{
		av[++index] = strtok(NULL, &delimeter);
	}

	av[index] = NULL;
	path = getpath(av[0]);
	if (path == NULL)
	{
		custom_print(missing_command);
		write(STDOUT_FILENO, new_line, 1);
		continue;
	}
	else if (custom_strcmp(av[0], "exit") == 0)
	{
		exit_cmd();
		exit(0);
	}
	else if (custom_strcmp(av[0], "env") == 0)
	{
		execute_env();
	}

	child_pid = fork();
                if (child_pid < 0)
                {
                        custom_print(childp_fail);
                        free(user_input);
                        exit(0);
                }
                else if (child_pid == 0)
                {
                        execve_return = (execve(path, av, env));
                        if (execve_return == -1)
                                custom_print(missing_command);
                                write(STDOUT_FILENO, new_line, 1);

                }
	else
		{
			wait(&status);
		}
	}

	free(user_input);
	free(path);
	return (0);
}
