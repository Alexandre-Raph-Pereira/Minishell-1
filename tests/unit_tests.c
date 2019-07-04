/*
** EPITECH PROJECT, 2019
** unit_tests.c
** File description:
** unit_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(setenv, is_equal)
{
    char *env[] = {"SALUT=SAUSSICE", "COUCOU=HOLA", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"SALUT=SAUSSICE", "COUCOU=HOLA", "bonjour=", NULL};
    char str[] = "setenv bonjour";
    int i = 0;

    env_copied = setenv_function(str, env_copied);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(setenv_double, is_equal)
{
    char *env[] = {"SALUT=SAUSSICE", "COUCOU=HOLA", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"SALUT=SAUSSICE", "COUCOU=HOLA", "bonjour=salut", NULL};
    char str[] = "setenv bonjour salut";
    int i = 0;

    env_copied = setenv_function(str, env_copied);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(setenv, is_not_equal)
{
    char *env[] = {"SALUT=SAUSSICE", "COUCOU=HOLA", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"SALUT=SAUSSICE", "COUCOU=HOLA", "bonjour", NULL};
    char str[] = "setenv coucou";

    env_copied = setenv_function(str, env_copied);
    cr_assert_str_neq(env_copied[2], new_env[2]);
}

Test(setenv, is_not_good, .init = redirect_all_std)
{
    char *env[] = {"SALUT=SAUSSICE", "COUCOU=HOLA", NULL};
    char **env_copied = copy_env(env);
    char str[] = "setenv coucou hola coucou bonjour";

    setenv_function(str, env_copied);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(remove_env, is_equal_2)
{
    char *env[] = {"SALUT=SAUSSICE", "COUCOU=HOLA", "bonjour=", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"SALUT=SAUSSICE", "COUCOU=HOLA", NULL};
    char str[] = "unsetenv bonjour";
    int i = 0;

    env_copied = remove_env(str, env_copied);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(not_remove_env, is_equal_2)
{
    char *env[] = {"SALUT=SAUSSICE", "COUCOU=HOLA", "bonjour=salut", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"SALUT=SAUSSICE", "COUCOU=HOLA", "bonjour=salut", NULL};
    char str[] = "unsetenv salut";
    int i = 0;

    env_copied = remove_env(str, env_copied);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(remove_2_env, is_equal_3)
{
    char *env[] = {"SALUT=SAU", "COUCOU=HOLA", "bonjour=salut", "hola=", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"SALUT=SAU", "COUCOU=HOLA", NULL};
    char str[] = "unsetenv bonjour hola";
    int i = 0;

    env_copied = remove_env(str, env_copied);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(check_bin, is_equal, .init = redirect_all_std)
{
    char str[] = "aaaaaaa";
    char *str2 = "bbbbbb";

    check_bin(str, str2);
    cr_assert_stderr_eq_str("bbbbbb: Command not found.\n");
}

Test(cd, is_equal)
{
    char *env[] = {"PWD=/home/apereira/Documents", "HOME=/home/apereira", NULL};
    char **env_copied = copy_env(env);
    char *new_env[] =  {"PWD=/home/apereira", "HOME=/home/apereira", NULL};
    char str[] = "cd";
    int i = 0;

    env_copied = cd_function(str, env_copied);
    while (new_env[i] != NULL) {
        cr_assert_str_eq(env_copied[i], new_env[i]);
        i++;
    }
}

Test(cd, is_equal_not_eq, .init = redirect_all_std)
{
    char *env[] = {"PWD=/home/apereira", "HOME=/home/apereira", "hola=", NULL};
    char **env_copied = copy_env(env);
    char str[] = "cd salut";

    env_copied = cd_function(str, env_copied);
    cr_assert_stderr_eq_str("salut: No such file or directory.\n");
}

Test(cd, cd_a_file, .init = redirect_all_std)
{
    char *env[] = {"PWD=/home/apereira", "HOME=/home/apereira", "hola=", NULL};
    char **env_copied = copy_env(env);
    char str[] = "cd main.c";

    env_copied = cd_function(str, env_copied);
    cr_assert_stderr_eq_str("main.c: Not a directory.\n");
}

Test(exec, is_equal_not_eq, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/bin/:/bin/", "HOME=/home/apereira", "h=", NULL};
    char **env_copied = copy_env(env);
    char str[] = "oiuezaez";

    my_exec(str, env_copied);
    cr_assert_stderr_eq_str("oiuezaez: Command not found.\n");
}

Test(exec, wrond_argument, .init = redirect_all_std)
{
    char *env[] = {"PATH=/salut/:/bonjour/", "HOME=/home/apereira", NULL};
    char **env_copied = copy_env(env);
    char str[] = "oiuezaez";

    my_exec(str, env_copied);
    cr_assert_stderr_eq_str("oiuezaez: Command not found.\n");
}

Test(exec, not_path, .init = redirect_all_std)
{
    char *env[] = {"HOME=/home/apereira", NULL};
    char **env_copied = copy_env(env);
    char str[] = "oiuezaez";

    my_exec(str, env_copied);
    cr_assert_stderr_eq_str("oiuezaez: Command not found.\n");
}

Test(exec, exec_directory, .init = redirect_all_std)
{
    char *env[] = {"HOME=/home/apereira", "PATH=/salut/:/bonjour/", NULL};
    char **env_copied = copy_env(env);
    char str[] = "/usr/bin";

    my_exec(str, env_copied);
    cr_assert_stderr_eq_str("/usr/bin: Permission denied.\n");
}
