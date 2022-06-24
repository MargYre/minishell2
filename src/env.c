/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** check_env
*/

#include "mysh.h"

int check_env(char *line, char **env)
{
    int check = 0;
    char str[] = "env\n";

    for (int i = 0; line[i]; i++) {
        if (line[i] == str[i])
            check++;
    }
    if (check == my_strlen(line)) {
        for (int i = 0; env[i]; i++) {
            my_putstr(env[i]);
            my_putstr("\n");
        }
        return (1);
    }
    return (0);
}
