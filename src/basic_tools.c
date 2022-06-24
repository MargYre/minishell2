/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_strlen, my_putchar, my_putstr
*/

#include "mysh.h"

int my_strlen(char *str)
{
    int count = 0;

    for (; str[count]; count++);
    return (count);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
}

void my_putstr_error(char *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar_error(str[i]);
    }
    write(2, ": Command not found.\n", 21);
}
