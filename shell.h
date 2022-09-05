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
#define READ_BUF 1024/* allocating a constant for the buffer */

#define DELIMETER " \a\t\r\n"

/* command type */
#define INTERNAL_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

/* declaring global environ variable */
extern char **environ;

/**
 * struct internal_func - structure madee for internal functions
 * @cmd_name: name of command
 * @func: function of command
 *
 */
typedef struct internal_func
{
	char *cmd_name;
	void (*func)(char **command);
} map_func;

/*
typedef struct path_hist
{
	char *oldpath;
} path_hist;
*/

void env(char **);
void ch_dir(char **);
void quit(char **);


void ctrl_C(int);
char *get_line(void);
char **tokenization(char *, const char *);
void execute_shell(char **, int);
int check_command(char *);
void execute(char **, int);
int a_delimeter(const char *, char);


int print(char *, int);
void (*_getfunc(char *))(char **);


int _strlen(char *);
int _strcmp(char *, char *);


void *_realloc(void *, int, int);


char *_getenv(char *);

#endif /* SHELL_H */
