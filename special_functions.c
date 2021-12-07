#include "main.h"

/**
 * isBasicExit - Check if the command passed 
 * by the user was "exit", if so, kill the
 * the interactive mode of the Shell
 * @tokens: n
 * @countToken: n
 * @gl: n
 * Return: nothing
 */
void isBasicExit(char ***tokens, int countToken, ssize_t *gl)
{
char *firstOne = NULL;

if (countToken != 2 || *tokens == NULL)
return;

firstOne = (*tokens)[0];

if (strcmp(firstOne, "exit") == 0)
{
*gl = -1;
free(*tokens);
}
}

/**
 * isEnv - Check if the command passed
 * by the user was "env", if so, print
 * the current environment
 * @tokens: n
 * @countToken: n
 * return: nothing
 */
void isEnv(char ***tokens, int countToken)
{
char *firstOne = NULL;
int i;

if (countToken != 2 || *tokens == NULL)
return;

firstOne = (*tokens)[0];

if (strcmp(firstOne, "env") == 0)
{
i = 0;
while (environ[i])
{
printf("%s\n", environ[i++]);
}
free(*tokens);
*tokens = NULL;
}
}
