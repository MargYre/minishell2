/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** get_path, cut_path, find_path
*/

#include "mysh.h"

int find_path(char *str)
{
    int check = 0;
    char str_path[] = "PATH";

    for (int i = 0; i != 3; i++) {
        if (str[i] == str_path[i])
            check++;
    }
    return (check);
}

char *cut_path(char *path, char *line_env)
{
    int len = my_strlen(line_env) - 4;
    int i = 0;

    path = malloc(sizeof(char) * len);
    if (!path)
        return (NULL);
    for (int k = 5; line_env[k]; i++, k++)
        path[i] = line_env[k];
    path[i] = '\0';
    return (path);
}

char *get_path(char **env)
{
    int j = 0;
    char *path;

    for (int test = 0; test != 3 && env[j]; j++)
        test = find_path(env[j]);
    j--;
    path = cut_path(path, env[j]);
    return (path);
}
