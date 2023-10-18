#include "main.h"
#include <stdio.h>


/**
 * execute_env- exceutes a process in a shell
 *
 * Return: Nothing
 */

void execute_env(void)
{
	char *equal_sign = "=";
	char *new_line = "\n";

	/* List of environment variables to display */
	char *env_vars[] = {"USER", "LANGUAGE", "SESSION",
		"COMPIZ_CONFIG_PROFILE", "SHLVL", "HOME", "C_IS",
		"DESKTOP_SESSION", "LOGNAME", "TERM", "PATH", "DISPLAY", NULL};

	/*Iterate through the specified environment variables and print their values*/
	for (int i = 0; env_vars[i] != NULL; i++)
	{
		char *env_value = getenv(env_vars[i]);

		if (env_value != NULL)
		{
			custom_print(env_vars[i]);
			write(STDOUT_FILENO, equal_sign, 1);
			custom_print(env_value);
			write(STDOUT_FILENO, new_line, 1);
		}
	}
}
