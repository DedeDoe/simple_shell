#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - has pseudo-arguements to pass into a function,
 *@arg: string generated from getline containing arguements
 *@argv: array of strings generated from arg
 *@path: string path for the current command
 *@argc: argument count
 *@line_count: the number of error count
 *@err_num: error code for exit()s
 *@linecount_flag: line of input
 *@fname: program filename
 *@env: the linked list copy of environ
 *@environ: the custom modified copy of environ from LL env
 *@history: history node
 *@alias: alias node
 *@env_changed: only on if environ was changed
 *@status: return status of the last exec'd command
 *@cmd_buf:the address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: has CMD_type ||, &&, ;
 *@readfd: fd from which to read line input
 *@histcount: history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


char *_getenv(info_t *, const char *);
char *_memset(char *, char, unsigned int);
char *_strcat(char *, char *);
char *_strchr(char *, char);
char *_strcpy(char *, char *);
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char **get_environ(info_t *);
char **list_to_strings(list_t *);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *convert_number(long int, int, int);
char *custom_strdup(char *original);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
char *get_history_file(info_t *info);
char *starts_with(const char *, const char *);
int _atoi(char *);
int _eputchar(char);
int _erratoi(char *);
int _getline(info_t *, char **, size_t *);
int _isalpha(int);
int _myalias(info_t *);
int _mycd(info_t *);
int _myenv(info_t *);
int _myexit(info_t *);
int _myhelp(info_t *);
int _myhistory(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int _putchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);
int bfree(void **);
int build_history_list(info_t *info, char *buf, int linecount);
int custom_strcmp(char *stra, char *strb);
int delete_node_at_index(list_t **, unsigned int);
int find_builtin(info_t *);
int hsh(info_t *, char **);
int interactive(info_t *);
int is_chain(info_t *, char *, size_t *);
int is_cmd(info_t *, char *);
int is_delim(char, char *);
int loophsh(char **);
int populate_env_list(info_t *);
int print_d(int, int);
int read_history(info_t *info);
int renumber_history(info_t *info);
int replace_alias(info_t *);
int replace_string(char **, char *);
int replace_vars(info_t *);
int write_history(info_t *info);
list_t *add_node_end(list_t **, char *, int);
list_t *add_node(list_t **, char *, int);
list_t *node_starts_with(list_t *, char *, char);
size_t custom_strlen(char *str);
size_t list_len(const list_t *);
size_t print_list_str(const list_t *);
size_t print_list(const list_t *);
ssize_t get_input(info_t *);
ssize_t get_node_index(list_t *, list_t *);
void _eputs(char *);
void _puts(char *);
void *_realloc(void *, unsigned int, unsigned int);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
void clear_info(info_t *);
void ffree(char **);
void find_cmd(info_t *);
void fork_cmd(info_t *);
void free_info(info_t *, int);
void free_list(list_t **);
void print_error(info_t *, char *);
void remove_comments(char *);
void set_info(info_t *, char **);
void sigintHandler(int);

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define USE_GETLINE 0
#define USE_STRTOK 0

#define H_F	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

#endif
