#ifndef PID_H
#define PID_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0

extern char **environ;

/**
 * struct Node - singly linked list
 * @str: string  
 * @next: points to the next node
 *
 * Description: This singly linked list
 * will store the PATH dirs
 */
typedef struct Node
{
	char *str;
	struct Node *next;
} Node;

/* Main function */
void shellLoop(char **argv);

/* Special functions */
void isBasicExit(char ***tokens, int countToken, ssize_t *gl);
void isEnv(char ***tokens, int countToken);

/* Parser */
ssize_t readLine(char **buffer, char ***tokens);
void replaceNewLine(char **buffer);
int lenTokens(ssize_t lenReaded, char **buffer);
void processTokens(char ***tokens, char **buffer, int countToken);

/* Executer */
void isPath(char ***tokns, char **path, char **av, int *count, int *errShowed);
int executeLine(char **buffer, char ***tokens, char *fullPath);

/* String tools */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);

/* List tools - To free memory */
void free_list(Node *head);

/* Functions to get the data in the interactive shell */
int _getchar(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* Get the value of a entorn variable */
char *_getenv(const char *name);

/* Creates a linked list of the passed environment variable */
Node *_getpathdir(char *path, char **pathCopy);

/* Put the PATH into a linked list */
Node *listpath(char **pathCopy); 

/* Return the path if found an executable file */
char *addPath(char ***tokens, Node *path);

#endif
