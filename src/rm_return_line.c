/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** rm_return_line
*/

#include "mysh.h"

char *rm_return_line(char *str)
{
    char *new_str;
    int len = my_strlen(str);
    int i = 0;

    new_str = malloc(sizeof(char) * len);
    if (!new_str)
        return (NULL);
    for (; str[i] && str[i] != '\n'; i++) {
        new_str[i] = str[i];
    }
    new_str[i] = '\0';
    return (new_str);
}
