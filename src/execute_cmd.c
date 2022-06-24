/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** execute_cmd
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

int execute_error(pid_t w, pid_t cpid, int wstatus)
{
    w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
    if (wstatus == 139)
        write(2, "Segmentation fault (core dumped)\n", 33);
    if (wstatus == 136)
        write(2, "Floating exception (core dumped)\n", 33);
    if (w == -1) {
        perror("waitpid");
        return (84);
    }
    return (0);
}

int execute_cmd(char *filename, char *argv, char **const envp)
{
    char **tab;
    char str[] = "ls -md";
    pid_t cpid;
    pid_t w;
    int wstatus;

    argv = rm_return_line(argv);
    tab = str_to_word_tab(argv, ' ', 1);
    if ((cpid = fork()) == -1) {
        perror("waitpid");
        return (84);
    }
    if (cpid == 0) {
        if (execve(filename, tab, envp) == -1)
            return (-1);
    }
    else
        return (execute_error(w, cpid, wstatus));
    return (0);
}
