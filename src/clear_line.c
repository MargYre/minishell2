/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** clear_line.c
*/

#include "mysh.h"

char *clear_line(char *str)
{
    char *line = NULL;
    int size = (my_strlen(str) + 1);
    int i = 0;

    line = malloc(sizeof(char) * size);
    for (int j = 0; str[j]; j++) {
        if (str[j] >= 7 && str[j] <= 31 && str[j] == '\n')
                line[i] = ' ';
        else {
            line[i] = str[j];
            if (line[i -1] && line[i -1] == ' ' && line[i] == ' ');
            else
                i++;
        }
    }
    line[i] = '\0';
    return (line);
}
