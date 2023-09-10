#ifndef _SHELL_H
#define _SHELL_H

/* libaries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024

/* Structures */


/* Prototypes*/
unsigned int _strlen(const char *);
void _puts(char *);
char *_strn(char *);
void display_prompt(void);
void execute_command(char **, char *);
char *_strdup(const char *str);
char *_strcpy(char *, char *);
char **parse_input(const char *input, char *);
char *find_command(char *, char *);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *path);
int _strncmp(const char *s1, const char *s2, size_t n);

extern char **environ;

#endif
