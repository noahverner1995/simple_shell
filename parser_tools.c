#include "main.h"

/**
 * addPath - Get and check if the command is available
 * @tokens: n
 * @path: n
 * Return: Pointer to the filename where the path to use is located
 */
char *addPath(char ***tokens, Node *path)
{
struct stat st;
Node *pathDirs;
char *firstOne, *copyPath = NULL;
int lenOne, lenTwo;

if (*tokens == NULL)
{
return (NULL);
}

pathDirs = path;
if (pathDirs == NULL)
return (NULL);

firstOne = *(tokens)[0];
lenOne = _strlen(firstOne);

while (pathDirs != NULL)
{
lenTwo = _strlen(pathDirs->str);
copyPath = malloc((lenTwo + lenOne + 2) * sizeof(char));
if (copyPath == NULL)
return (NULL);
*copyPath = '\0';
strcat(copyPath, pathDirs->str);
strcat(copyPath, "/");
strcat(copyPath, firstOne);
if (stat(copyPath, &st) == 0)
break;

free(copyPath);
copyPath = NULL;
pathDirs = pathDirs->next;
}
return (copyPath);

}

/**
 * processTokens - Put all of the strings separated by 
 * a delimiter in an array of strings
 * @tokens: n
 * @buffer: n
 * @countToken: n
 *
 * Return: nothing
 */
void processTokens(char ***tokens, char **buffer, int countToken)
{
char *token = NULL;
int i;
char *delim = " \n\t";

*tokens = malloc(sizeof(char *) * countToken);
token = strtok(*buffer, delim);
for (i = 0; token != NULL; i++)
{
(*tokens)[i] = token;

token = strtok(NULL, delim);
}
(*tokens)[i] = token;
}

/**
 * lenTokens - Get the number of words separated by a delimiter
 * @lenReaded: n
 * @buffer: n
 * Return: (int) of words in the buffer
 */
int lenTokens(ssize_t lenReaded, char **buffer)
{
char *tempToken = NULL, *copyBuffer = NULL;
int i;
char *delim = " \n\t";

copyBuffer = malloc(sizeof(char) * lenReaded);
_strcpy(copyBuffer, *buffer);
tempToken = strtok(copyBuffer, delim);
for (i = 0; tempToken != NULL; i++)
tempToken = strtok(NULL, delim);
i++;
free(copyBuffer);
return (i);
}

/**
 * replaceNewLine - Replace the new line in the buffer
 * by a null character
 * @buffer: n
 * Return: nothing
 */
void replaceNewLine(char **buffer)
{
int i;

for (i = 0; (*buffer)[i] != '\0'; i++)
continue;
(*buffer)[i - 1] = '\0';
}

/**
 * readLine - Get and process the data in the stdin
 * @buffer: n
 * @tokens: n
 * Return: (ssize_t) The number of chars readed in stdin
 */
ssize_t readLine(char **buffer, char ***tokens)
{
size_t bufferSize = 0;
ssize_t gl;
int countToken;

*tokens = NULL;
gl = _getline(buffer, &bufferSize, stdin);
if (gl > 0 && **buffer != '\n')
{
replaceNewLine(buffer);
countToken = lenTokens(gl, buffer);
processTokens(tokens, buffer, countToken);
isBasicExit(tokens, countToken, &gl);
isEnv(tokens, countToken);
}
return (gl);
}
