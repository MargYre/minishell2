/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** check_cd
*/

#include "mysh.h"

int check_cd(char *line)
{
    int check = 0;
    char str[] = "cd ";
    char **tab;

    for (int i = 0; i < 3 && line[i]; i++) {
        if (line[i] == str[i])
            check++;
    }
    if (check == 3) {
        tab = str_to_word_tab(line, ' ', 1);
        if (tab[2] != NULL)
            return (1);
        chdir(rm_return_line(tab[1]));
    }
    return (0);
}
