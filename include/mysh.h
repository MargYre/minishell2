/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** mysh.h
*/

#ifndef __MYSH__
#define __MYSH__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void my_putstr(char *str);
void my_putstr_error(char *str);
int my_strlen(char *str);
char *get_path(char **env);
char *my_strcat(char *str, char *str_bis);
char **str_to_word_tab(char *str, char sep, int init);
char *fill_line_tab(char *line, char *str, char sep, int init);
int ignore_sep(char *str, char sep, int i);
char *short_command(char *str);
char *rm_return_line(char *str);
int execute_cmd(char *filename, char *argv, char **const envp);
int check_env(char *line, char **env);
int check_cd(char *line);
int check_exit(char *line);
char *clear_line(char *str);
char *short_exec(char *str);
char **copy_environement(char **env_copy, char **env);

#endif
