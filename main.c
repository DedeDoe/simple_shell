#include "shell.h"

/**
 * main - entry point of the shell
 * @agc: argument count
 * @agv: argument vector
 *
 * Return: 0 on success, and 1 on error
 */
int main(int agc, char **agv)
{
	int eg = 2;
	info_in data[] = { INFO_INIT };

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (eg)
		: "r" (eg));

	if (agc == 2)
	{
		eg = open(argv[1], O_RDONLY);
		if (eg == -1)
		{
			if (errno == EACCES)
				exit(101);
			if (errno == ENOENT)
			{
				_eputs(agv[0]);
				_eputs(": 0: Can't open ");
				_eputs(agv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(102);
			}
			return (1);
		}
		data.readeg = eg;
	}
	populate_env_list(data);
	read_history(data);
	hsh(data, agv);
	return (0);
}
