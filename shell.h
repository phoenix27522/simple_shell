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

/* Structures */


/* Prototypes*/
unsigned int _strlen(const char *);
void _puts(char *);
char * _strn(char *);
void display_prompt(void);
void execute_command(char **, char *);
char *_strdup(const char *str);
char *_strcpy(char *, char *);
char **parse_input(const char *input, char *);


#endif