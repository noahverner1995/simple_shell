#include "main.h"

/**
 * controlC - write to the stdout "\n($) "
 * @var: n
 */
void controlC(int var)
{
/*write(1, "\n($) ", 5);*/
(void) var;
}

/**
 * main - Execute shellLoop function with the
 * output of controlC function passed as argv
 * @argc: number of arguments
 * @argv: characters of the argument
 * Return: nothing
 */
int main(int argc, char **argv)
{
(void) argc;
signal(SIGINT, controlC);
shellLoop(argv);

return (0);
}
