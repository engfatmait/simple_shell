#ifndef _MAIN_
#define _MAIN_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*points to an array of strings called "environment"*/
extern char **environ;

/**
 * struct my_builtins - contains the command and its function
 * @name: command name
 * @fun: pointer to fun
*/

typedef struct my_builtins
{
	char *name;
	void (*fun)(void);
} builtin;


int print_str(char *str);
char **read_tok_input(void);
char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void f_exit(void);
void f_env(void);
int exec_command(char **argv);
int implement_exec(char *command, char **argv);
int env_com(char *name, char *nenv);
char *_getenviron(char *name);
char *get_path_com(char *command);
void _strcat(char *dest, char *src);
char *_strdup(char *str);



#endif
