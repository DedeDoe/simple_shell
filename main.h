#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

int _putchar(char c);
int my_print(char *str);
char *address(char *path, char *arg);
char *getpath(char *arg);
void exit_cmd(void);
void execute_env(void);
size_t custom_strlen(char *str);
char *custom_strdup(char *original);
char *custom_strcat(char *destination, char *source);
int custom_strcmp(char *stra, char *strb);
char *custom_strcpy(char *destination, char *source);
void custom_print(char *string);
void child(void);

#endif
