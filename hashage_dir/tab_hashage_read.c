/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** tab_hashage_read
*/

#include "tab_hashage.h"

int find_key(char const *key, tab_t *tab)
{
    int index = 0;
    int check = 0;

    for (; index <= tab->nb_elem && (check = my_strcmp(key, tab->elem[index].key)) < 0; index += 5);
    for (; index >= tab->nb_elem; index--);
    for (; index >= 0; index--) {
        if (my_strcmp(key, tab->elem[index].key) == 0)
            return (index);
    }
    return (-1);
}