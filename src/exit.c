/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** check_exit.c
*/

#include "mysh.h"

int check_exit(char *line)
{
    int check = 0;
    char str[] = "exit\n";

    for (int i = 0; line[i]; i++) {
        if (line[i] == str[i])
            check++;
    }
    if (check == my_strlen(line))
        return (1);
    return (0);
}
