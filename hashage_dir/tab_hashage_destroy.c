/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** tab_hashage_destroy
*/

#include <stdlib.h>
#include "tab_hashage.h"

void free_cell(tab_t *tab, int i)
{
    for (int j = 0; j < tab->elem[i].nb_elem; j++) {
        free(tab->elem[i].elem_i[j].key);
    }
    free(tab->elem[i].elem_i);
}

void tab_hashage_destroy(tab_t *tab)
{
    for (int i = 0; i < tab->nb_elem; i++) {
        if (tab->elem[i].nb_elem != 0) {
            free_cell(tab, i);
        }
        free(tab->elem[i].key);
    }
    free(tab->elem);
    free(tab);
}