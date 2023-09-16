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

#define MAX_SIZE 1024


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
char *_strtok(char *line, char *delim);
int shell_setenv(char **commands);
int shell_unsetenv(char **commands);
int _setenv(char *name, char *value, char **env);
int _unsetenv(char *name, char **env);
int shell_cd(char **commands);

/* utils */
void _puts(char *);
char *_strn(char *);
char *_strdup(const char *str);
char *str_concat(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
unsigned int _strlen(const char *);
void mem_free(unsigned int, ...);
int _strcmp(const char *, const char *);
void free_commands(char **);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strchr(char *s, char c);
int _atoi(char *s);
char *_memset(char *s, char b, unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _isdigit(int c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memcpy(void *dest, const void *src, unsigned int n);

extern char **environ;

#endif
