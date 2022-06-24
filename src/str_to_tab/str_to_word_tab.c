/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** str_to_word_tab, count_char, count_str, ignore_sep
*/

#include "mysh.h"

int ignore_sep(char *str, char sep, int i)
{
    for (; str[i] == sep && str[i]; i++);
    return (i);
}

int count_str(char *str, char sep)
{
    int count = 1;

    for (int i = 0; str[i]; i++) {
        if (str[i] == sep) {
            i = ignore_sep(str, sep, i);
            count++;
        }
    }
    return (count);
}

int count_char(char *str, char sep, int init)
{
    static int i = 0;
    int count = 0;

    if (init == 1)
        i = 0;
    for (; str[i] == sep && str[i]; i++);
    for (; str[i] != sep && str[i]; i++, count++);
    return (count);
}

char **str_to_word_tab(char *str, char sep, int init)
{
    char **tab;
    int nb_str = count_str(str, sep);
    int nb_char;

    tab = malloc(sizeof(char *) * (nb_str + 1));
    if (!tab)
        return (NULL);
    tab[nb_str] = NULL;
    for (int j = 0; j < nb_str; j++) {
        nb_char = count_char(str, sep, init);
        tab[j] = malloc(sizeof(char) * (nb_char + 1));
        if (!tab[j])
            return (NULL);
        tab[j] = fill_line_tab(tab[j], str, sep, init);
        init = 0;
    }
    return (tab);
}
