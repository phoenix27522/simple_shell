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
#include <stdarg.h>

#define BUFF_SIZE 1024


/* Structures */
/**
 * struct builtin - struct for the builtins
 * @built: the name of the builtin
 * @func: the associated function to be called for each builtin
 */
typedef struct builtin
{
	char *built;
	int (*func)(char **);
} built;

/* Prototypes*/
unsigned int _strlen(const char *);
void display_prompt(void);
void execute_command(char **, char *);
char **parse_input(const char *input, char *);
char *find_command(char *, char *);
char *_getenv(const char *path);
int execute_builtin(char **);
int shell_exit(char **);
int shell_env(char **);

/* utils */
void _puts(char *);
char *_strn(char *);
char *_strdup(const char *str);
char *_strcpy(char *, char *);
char *str_concat(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
unsigned int _strlen(const char *);
void mem_free(unsigned int, ...);
int _strcmp(const char *, const char *);
extern char **environ;
void free_commands(char **);

#endif
