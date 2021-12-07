#include "main.h"

/**
 * executeLine - Execute the command entered in the child process
 * @buffer: n
 * @tokens: n
 * @fullPath: n
 * Return: (int) status
 */
int executeLine(char **buffer, char ***tokens, char *fullPath)
{
int p_child, exec, status;

if (*tokens == NULL)
{
return (1);
}
if (**buffer == '\n' || fullPath == NULL)
{
free(*tokens);
return (1);
}
p_child =  fork();
if (p_child == -1)
{
perror("Failed to fork");
return (-1);
}
if (p_child == 0)
{
exec = execve(fullPath, *tokens, environ);
if (exec == -1)
{
printf("Exec -1 \n");
perror((*tokens)[0]);
free(*tokens);
free(*buffer);
exit(99);
}
}
else
{
wait(&status);
}

free(*tokens);
free(fullPath);
return (1);
}

/**
 * isPath - some
 * @tokens: n
 * @path: n
 * @av: n
 * @count: n
 * @errShowed: n
 */
void isPath(char ***tokens, char **path, char **av, int *count, int *errShowed)
{
char *firstOne = NULL;

if (*path != NULL || *tokens == NULL)
return;

firstOne = *(tokens)[0];

if (access(firstOne, F_OK | X_OK) == 0)
{
*path = _strdup(firstOne);
}
else
{
if (access(firstOne, F_OK) != 0)
{
dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", av[0], *count, firstOne);
*errShowed = 1;
}
else if (access(firstOne, X_OK) != 0)
{
printf("NO TIENE PERM DE EJECUCION\n");
}
}
}
