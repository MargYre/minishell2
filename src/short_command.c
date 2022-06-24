/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** short_command, short_cmd_len
*/

#include "mysh.h"

int short_cmd_len(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] == ' ' && str[i])
        i++;
    for (; str[i] && str[i] >= 97 && str[i] <= 122; i++, count++);
    return (count);
}

char *short_command(char *str)
{
    char *str2;
    int len = short_cmd_len(str);
    int i = 0;
    int c = 0;

    str2 = malloc(sizeof(char) * len + 1);
    if (!str2)
        return (NULL);
    while (str[i] == ' ')
        i++;
    for (; str[i] != ' ' && str[i]; c++, i++)
        str2[c] = str[i];
    str2[c] = '\0';
    return (str2);
}

char *short_exec(char *str)
{
    int len = my_strlen(str) + 1;
    char *short_str;
    int i = 0;

    short_str = malloc(sizeof(char) * len);
    if (!short_str)
        return (NULL);
    for (int j = 0; str[j]; j++) {
        if (j >= 2) {
            short_str[i] = str[j];
            i++;
        }
    }
    short_str[i] = '\0';
    return (short_str);
}
