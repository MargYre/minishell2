/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_strcat, fill_path
*/

#include "mysh.h"

char *fill_path(char *str, char *str_bis, char *path)
{
    int i = 0;

    for (; str[i] && str[i] != '\n'; i++)
        path[i] = str[i];
    for (int j = 0; str_bis[j] && str_bis[j] != '\n'; j++, i++)
        path[i] = str_bis[j];
    path[i] = '\0';
    return (path);
}

char *my_strcat(char *str, char *str_bis)
{
    int len = my_strlen(str) + my_strlen(str_bis);
    char *path;

    path = malloc(sizeof(char) * len + 1);
    if (!path)
        return (NULL);
    path = fill_path(str, str_bis, path);
    return (path);
}
