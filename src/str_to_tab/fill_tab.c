/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** fill_line_tab
*/

#include "mysh.h"

char *fill_line_tab(char *line, char *str, char sep, int init)
{
    static int i = 0;

    if (init == 1)
        i = 0;
    if (str[i] == sep)
        i = ignore_sep(str, sep, i);
    for (int k = 0; str[i] != sep && str[i]; i++, k++) {
        line[k] = str[i];
        line[k + 1] = '\0';
    }
    return (line);
}
