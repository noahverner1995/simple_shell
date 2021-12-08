#include "main.h"

/**
 * shellLoop - Run the shell "forever"
 * @argv: command passed by the user
 * Return: nothing
 */
void shellLoop(char **argv)
{
ssize_t getLine = 1;
char **tokens = NULL, *buffer = NULL, *fullPath = NULL;
Node *path = NULL;
char *pathCopy = NULL;
int errorShowed = 0, counter = 1;

path = listpath(&pathCopy);
while (TRUE)
{
fflush(stdout);
getLine = readLine(&buffer, &tokens);
if (getLine == EOF)
break;
fullPath = addPath(&tokens, path);
isPath(&tokens, &fullPath, argv, &counter, &errorShowed);
executeLine(&buffer, &tokens, fullPath);
counter++;
}
free_list(path);
free(pathCopy);
free(buffer);
}
