#include "shell.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument value
 * Return: 0
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int lapi;

	lapi = 2;


	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (lapi)
			: "r" (lapi));


	if (ac == 2)
	{
		lapi = open(av[1], O_RDONLY);
		if (lapi == -1)
		{
			if (errno == EACCES)
				exit(1);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(1);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = lapi;
	}

	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
