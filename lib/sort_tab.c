/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** sort_tab
*/

#include <stdlib.h>
#include "../hashage_dir/tab_hashage.h"

char *free_work(char *str)
{
    free(str);
    return (NULL);
}

char *duplicate_only_lower(char *str)
{
    char value = 'a' - 'A';
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] < 96)
            tmp[i] = str[i] + value;
        else
            tmp[i] = str[i];
    }
    tmp[i] = '\0';
    return (tmp);
}

void sort_list(char **list)
{
    char *s1 = NULL;
    char *s2 = NULL;

    for (int i = 0; i < my_strlen_tab(list) + 1; i++) {
        if (list[i + 1] == NULL)
            return;
        s1 = duplicate_only_lower(list[i]);
        s2 = duplicate_only_lower(list[i + 1]);
        if (my_strcmp(s1, s2) < 0)
            swap(&list[i], &list[i + 1]);
        s1 = free_work(s1);
        s2 = free_work(s2);
    }
}

int check_sort(char **list)
{
    char *s1 = NULL;
    char *s2 = NULL;

    for (int i = 0; i + 1 < my_strlen_tab(list); i++) {
        s1 = duplicate_only_lower(list[i]);
        s2 = duplicate_only_lower(list[i + 1]);
        if (my_strcmp(s1, s2) < 0) {
            s1 = free_work(s1);
            s2 = free_work(s2);
            return (1);
        }
        s1 = free_work(s1);
        s2 = free_work(s2);
    }
    return (0);
}

void master_sort(char **stock_file)
{
    for (; check_sort(stock_file) != 0;)
        sort_list(stock_file);
}