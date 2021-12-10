![This is an image](https://getlogovector.com/wp-content/uploads/2020/11/holberton-school-logo-vector.png)

# Simple shell #
In this project, we must write a simple UNIX command interpreter using C language, similar to the UNIX shell. This will be our final project of the first trimestrer at Holberton School"

For Holberton School.
Cohort 16.
Is a README.md for the repository 0X16.C - Simple Shell.

## Article: What happens when you type `ls -l *.c` in the shell ##

[Read it here 👀](https://medium.com/@3857/what-happens-when-you-type-ls-l-c-and-hit-enter-in-a-shell-da497f5c4720)

### General ###

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options ``` -Wall -Werror -Wextra -pedantic -std=gnu89 ```
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

## Authorized functions and macros ##
- ``` access ``` (man 2 access)
- ``` chdir ``` (man 2 chdir)
- ``` close ``` (man 2 close)
- ``` closedir ``` (man 3 closedir)
- ``` execve ``` (man 2 execve)
- ``` exit ``` (man 3 exit)
- ``` _exit ``` (man 2 _exit)
- ``` fflush ``` (man 3 fflush)
- ``` fork ``` (man 2 fork)
- ``` free ``` (man 3 free)
- ``` getcwd ``` (man 3 getcwd)
- ``` getline ``` (man 3 getline)
- ``` isatty ``` (man 3 isatty)
- ``` kill ``` (man 2 kill)
- ``` malloc ``` (man 3 malloc)
- ``` open ```  (man 2 open)
- ``` opendir ``` (man 3 opendir)
- ``` perror ``` (man 3 perror)
- ``` read ``` (man 2 read)
- ``` readdir ``` (man 3 readdir)
- ``` signal ``` (man 2 signal)
- ``` stat ``` (__xstat) (man 2 stat)
- ``` lstat ``` (__lxstat) (man 2 lstat)
- ``` fstat ``` (__fxstat) (man 2 fstat)
- ``` strtok ``` (man 3 strtok)
- ``` wait ``` (man 2 wait)
- ``` waitpid ``` (man 2 waitpid)
- ``` wait3 ``` (man 2 wait3)
- ``` wait4 ``` (man 2 wait4)
- ``` write``` (man 2 write)
## Compilation ##

``` gcc -Wall -Werror -Wextra -pedantic *.c -o hsh ```

### Testing ###
Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Included files
The following files contain different functions that where used:
- allowed_library.c
- built-in_func.c
- environ.c
- executer_tools.c
- holberton.h
- list_tools.c
- main.c
- parser_tools.c
- prints.c
- shell_loop.c
- string-tools-adv.c
- string-tools.c

## Authors :black_nib:
* __Luis Ernesto Perafán Chacón__  <[noahverner1995](https://github.com/noahverner1995)>
* __Kevin Ramirez__ <[xARKEINx](https://github.com/xARKEINx)>

