#include "main.h"

/**
 * _getenv - searches for the environment string
 * pointed to by name 
 * @name:  This is the C string containing the name
 * of the requested variable
 * Return: the associated value to the string.
 */
char *_getenv(const char *name)
{
int i, j;
int status;

for (i = 0; environ[i] != NULL; i++)
{
status = 1;
for (j = 0; environ[i][j] != '='; j++)
{
if (name[j] != environ[i][j])
{
status = 0;
break;
}
}

if (status)
{
return (&environ[i][j + 1]);
}
}
return (NULL);
}

/**
 * _getpathdir - creates a linked list for
 * any environment string
 * @path: the selected environment string
 * @pathCopy: a duplicate of @path
 * Return: a linked list of @path
 */
Node *_getpathdir(char *path, char **pathCopy)
{
char *token = NULL;
Node *head;
Node *pathNode;


if (path == NULL)
return (NULL);

*pathCopy = _strdup(path);

head = NULL;
pathNode = malloc(sizeof(Node));
if (pathNode == NULL)
return (NULL);

token = strtok(*pathCopy,  ":");
pathNode->str = token;
pathNode->next = head;
head = pathNode;
while (token != NULL)
{
token = strtok(NULL, ":");
if (token == NULL)
break;
pathNode = malloc(sizeof(Node));
if (pathNode == NULL)
return (NULL);
pathNode->str = token;
pathNode->next = head;
head = pathNode;
}
return (head);
}

/**
 * listpath - Creates linked list of PATH directories
 * @pathCopy: A variable that will store a duplication
 * of the "PATH" parameter
 * Return: A linked list of PATH directories
 */
Node *listpath(char **pathCopy)
{
char *getEnv;
Node *pathDirs;

getEnv = _getenv("PATH");
pathDirs = _getpathdir(getEnv, pathCopy);

return (pathDirs);
}
