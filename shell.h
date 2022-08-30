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


void ctrl_C(int);
int print(char *, int);
int _strlen(char *str);
char *get_line(void);
void *_realloc(void *ptr, int oldsize, int newsize);

#endif /* SHELL_H */
