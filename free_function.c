/*
** EPITECH PROJECT, 2019
** free_function.c
** File description:
** free_function
*/

#include "my.h"

void free_arr(char **arr, int t)
{
    int i = 0;

    while (i < t) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_tab(char **arg, int t)
{
    for (int i = 0; arg[i] && i < t; i++)
        free(arg[i]);
    free(arg);
}