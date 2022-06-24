/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env.c
*/

#include "mysh.h"

int count_elem_env(char **env)
{
    int j = 0;

    for (; env[j]; j++);
    return (j + 1);
}

void fill_env_copy(char *dest, char *src)
{
    int j = 0;

    for (int i = 0; src[i]; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
}

char **copy_environement(char **env_copy, char **env)
{
    int env_s = (count_elem_env(env) + 1);
    int j = 0;
    int string_s = 0;

    env_copy = malloc(sizeof(char*) * env_s);
    for (int i = 0; i < (env_s - 2); i++, j++) {
        string_s = my_strlen(env[j]);
        env_copy[j] = malloc(sizeof(char) * (string_s + 1));
        fill_env_copy(env_copy[j], env[j]);
    }
    env_copy[j] = NULL;
    return (env_copy);
}
