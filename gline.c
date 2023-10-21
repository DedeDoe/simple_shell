#include "shell.h"
#include <stdio.h>

/**
 * input_buf - function inputs buffers
 * @info: info_t
 * @buf: character pointer to a pointer of buffer
 * @len: size t pointer
 * Return: bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t rat;
	size_t lampado = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rat = 0;
		rat = getline(buf, &lampado, stdin);
#else
		rat = _getline(info, buf, &lampado);
#endif
		if (rat > 0)
		{
			if ((*buf)[rat - 1] == '\n')
			{
				(*buf)[rat - 1] = '\0';
				rat--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* check info->cmd_buf */
			{
				*len = rat;
				info->cmd_buf = buf;
			}
		}
	}
	return (rat);
}

/**
 * get_input - input receipt
 * @info: info_t
 * Return: bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t i, j, len;/*int i, j, len declared*/
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buffer, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i; /* assign i to j*/
		p = buffer + i;

		check_chain(info, buffer, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buffer, &j))
				break;/*break statement*/
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (custom_strlen(p));
	}

	*buf_p = buffer;
	return (r);
}

/**
 * read_buf -  read
 * @info: info_t
 * @buf: buffer character
 * @i: size
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline- receives input from STDIN
 * @info: info_t
 * @ptr: character pointer to a pointer
 * @length: size t length
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	size_t k;
	ssize_t red = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;
	static size_t i, leno;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == leno)
		i = leno = 0;

	red = read_buf(info, buf, &leno);
	if (red == -1 || (red == 0 && leno == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : leno;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - block
 * @sig_num: int sig_num
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
