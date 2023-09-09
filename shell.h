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
unsigned int _strlen(char *);
void _puts(char *);
char * _strn(char *);
void display_prompt(void);

#endif
