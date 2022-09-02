#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <stdint.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#define READ_BUF 1024 /* allocating a constant for the buffer */ 

/* innitial size of buffer for user input */
#define READ_BUF 1000

#define DELIM " \a\t\r\n"

/* command type */
#define INTERNAL_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

/* declaring global environ variable */
extern char **environ;

typedef struct internal_func
{
	char *cmd_name;
	void (*func)(char **command);
} map_func;


void env(char **);
void ch_dir(char **);
void quit(char **);


void ctrl_C(int);
char *get_line(void);
char **tokenize(char *, const char *);
void shell_execute(char **, int);
int check_command(char *);
void execute(char **, int);


int print(char *, int);
void (*get_func(char *))(char **);


int _strlen(char *);
int _strcmp(char*, char *);


void *_realloc(void *, int, int);


char *_getenv(char *);

#endif /* SHELL_H */
