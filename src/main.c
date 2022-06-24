 /*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** main, prompt, check_arg, check_arg_builtin
*/

#include "mysh.h"

int check_arg_builtin(char *line, char **path, char **env)
{
    if (check_exit(line) == 1)
        return (0);
    if ((check_env(line, env)) == 1)
        return (1);
    if (check_cd(line) == 1)
        return (1);
    return (-1);
}

int check_arg(char *line, char **path, char **env)
{
    char *tmp = NULL;
    int i = -1;
    char *str;
    int builtin;

    line = clear_line(line);
    if (i == -1 && access(line, X_OK) == 0)
        i = execute_cmd(line, line, env);
    builtin = check_arg_builtin(line,path,env);
    if (builtin != -1)
        return (builtin);
    for (int j = 0; path[j]; j++) {
        tmp = my_strcat(path[j], my_strcat("/", short_command(line)));
        if (access(tmp, X_OK) == 0 || line == NULL)
            i = execute_cmd(tmp, line, env);
    }
    if (i == -1)
        my_putstr_error(line);
    return (1);
}

int prompt(char **env, char **av)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *str_path = get_path(env);
    char **path = str_to_word_tab(str_path, ':', 0);

    if (isatty(0) == 1)
        write(1, "$> ", 3);
    while (1) {
        if (getline(&line, &len, stdin) != -1) {
            if (check_arg(line, path, env) == 0 || read == -1)
                return (0);
            if (isatty(0) == 1)
                write(1, "$> ", 3);
        }
        else
            return (0);
    }
    free(line);
    return (0);
}

int main(int ac, char **av, char **env)
{
    char **env_copy = NULL;

    if (ac != 1)
        return (84);
    if (env[0] == NULL)
        return (84);
    env_copy = copy_environement(env_copy, env);
    return (prompt(env_copy, av));
}
