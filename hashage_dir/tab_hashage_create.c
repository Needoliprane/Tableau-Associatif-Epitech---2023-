/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** tab_hashage
*/

#include <stdlib.h>
#include "tab_hashage.h"

char *malloc_helper(int nb)
{
    char *tmp = malloc(sizeof(char) * nb + 1);

    if (tmp == NULL) {
        my_putstr("Error: Malloc fail");
        return (NULL);
    }
    for (int i = 0; i < nb; i++)
        tmp[i] = '\0';
    return (tmp);
}

void memset_tab(tab_t *tab)
{
    char letter = 'a';

    for (int i = 0; i < tab->nb_elem; i++, letter++) {
        tab->elem[i].nb_elem = 0;
        tab->elem[i].value = 0;
        tab->elem[i].key = malloc_helper(8);
        tab->elem[i].letter = letter;
        tab->elem[i].elem_i = NULL;
    }
}

tab_t *create_tab(int nb)
{
    tab_t *tab = malloc(sizeof(tab_t));

    if (tab == NULL) {
        my_putstr("Error: Malloc fail");
        return (NULL);
    }
    tab->nb_elem = nb;
    tab->elem = malloc(sizeof(elemen_t) * (nb));
    if (tab->elem == NULL) {
        my_putstr("Error: Malloc fail");
        return (NULL);
    }
    memset_tab(tab);
    return (tab);
}