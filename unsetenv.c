/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** unsetenv
*/

#include "my.h"

int check_arg(char **arr)
{
    int t = 1;

    while (arr[t] != NULL) {
        if (my_str_isalpha(arr[t]) == 0) {
            my_putstr2("setenv");
            my_putstr2(": Variable name must contain ");
            my_putstr2("alphanumeric characters.\n");
            return (0);
        }
        t++;
    }
    return (1);
}

char **find_remove(char *arr, char *new_env[], int i, int *u)
{
    if (my_strcmp(arr, new_env[i]) == 0
        && my_strlen(arr) == taille_env(new_env[i])) {
        new_env[i][0] = '\0';
        new_env = recopy_env(new_env);
        *u = 1;
    }
    return (new_env);
}

char **remove_env(char *str, char *new_env[])
{
    int i = 0;
    int j = 1;
    int u = 0;
    char **arr = my_str_to_word_array(str);
    int t = 0;

    for (t = 0; arr[t]; t++);
    if (t == 1) {
        my_putstr2(arr[0]);
        my_putstr2(": Too few arguments.\n");
    }
    while (arr[j] != NULL) {
        while (u == 0 && new_env[i] != NULL) {
            new_env = find_remove(arr[j], new_env, i, &u);
            i++;
        }
        i = 0;
        j++;
        u = 0;
    }
    return (new_env);
}
