/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"

int condition_str(char *str)
{
    char **arr = my_str_to_word_array(str);

    if ((my_strcmp(arr[0], "env") != 0 || my_strlen(arr[0]) != 3) &&
        (my_strcmp(arr[0], "setenv") != 0 || my_strlen(arr[0]) != 6) &&
        (my_strcmp(arr[0], "unsetenv") != 0 || my_strlen(arr[0]) != 8) &&
        (my_strcmp(arr[0], "exit") != 0 || my_strlen(arr[0]) != 5) &&
        (my_strcmp(arr[0], "cd") != 0 || my_strlen(arr[0]) != 2)) {
        perror(arr[0]);
        return (0);
    }
    return (1);
}

char **compare_str(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);

    if (my_strcmp(arr[0], "env") == 0 && my_strlen(arr[0]) == 3)
        return (printf_env(new_env));
    if (my_strcmp(arr[0], "setenv") == 0 && my_strlen(arr[0]) == 6)
        return (setenv_function(str, new_env));
    if (my_strcmp(arr[0], "unsetenv") == 0 && my_strlen(arr[0]) == 8)
        return (remove_env(str, new_env));
    if (my_strcmp(arr[0], "exit") == 0 && my_strlen(arr[0]) == 4) {
        my_printf("exit\n");
        exit(0);
    }
    if (my_strcmp(arr[0], "cd") == 0 && my_strlen(arr[0]) == 2)
        return (cd_function(str, new_env));
    if (my_exec(str, new_env) == 1)
        return (new_env);
    if (condition_str(str) == 0)
        return (new_env);
    return (new_env);
}

int main(int argc, char **argv, char *env[])
{
    char *str = NULL;
    char **new_env = copy_env(env);
    size_t n = 0;

    if (new_env == NULL)
        return (84);
    if (isatty(0) == 1)
        my_printf("$> ");
    while (getline(&str, &n, stdin) != -1) {
        if (str[0] != '\0' && str[0] != '\n')
            new_env = compare_str(str, new_env);
        if (new_env == NULL)
            return (84);
        if (isatty(0) == 1)
            my_printf("$> ");
    }
    free_tab(new_env, 100);
    free(str);
    return (0);
}
