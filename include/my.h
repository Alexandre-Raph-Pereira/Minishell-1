/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <grp.h>
#include <string.h>
#include <errno.h>
#include "my_printf.h"

int my_printf(char *str, ...);
char **printf_env(char *env[]);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *str);
char **reallocation(char **str, int taille);
char *my_strcat(char *dest, char const *str);
char **printf_env(char *env[]);
char **setenv_function(char *str, char *env[]);
char **copy_env(char *env[]);
char **recopy_env(char *env[]);
char **cd_function(char *str, char *new_env[]);
char *find_pwd(char *new_env[]);
char **find_old_pwd(char *str, char *new_env[]);
char **modif_arr(char **arr, char *new_env[]);
char **remove_env(char *str, char *new_env[]);
int check_exec(char **arr);
int my_exec(char *str, char *new_env[]);
char *is_a_bin(char *arr, char *new_env[]);
int taille_env(char *str);
char *my_getenv(char *new_env[], char *str);
void free_arr(char **arr, int t);
void free_tab(char **arg, int t);
int env_length(char **arr);
char **add_env(char *new_env[], char **str, int i);
char **copy_env(char *old_env[]);
int check_bin(char *str, char *str2);
int check_arg(char **arr);
#endif /* !MY_H_ */
