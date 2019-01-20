/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** tab_hashage
*/

#include <stdlib.h>
#include "tab_hashage.h"

elemen_i_t *elem_cpy(char **tab_data, int j, tab_t *tab)
{
    elemen_i_t *elem_tmp = malloc(sizeof(elemen_i_t) * (tab->elem[j].nb_elem));
    int i = 0;

    for (; i < tab->elem[j].nb_elem - 1; i++) {
        elem_tmp[i].key = my_strdup(tab->elem[j].elem_i[i].key);
        elem_tmp[i].value = tab->elem[j].elem_i[i].value;
        free(tab->elem[j].elem_i[i].key);
    }
    elem_tmp[i].key = my_strdup(tab_data[0]);
    elem_tmp[i].value = my_getnbr(tab_data[1]);
    free(tab->elem[j].elem_i);
    return (elem_tmp);
}

void add_elem(tab_t *tab, int j, char **tab_data)
{
    if (tab->elem[j].nb_elem == 0) {
        tab->elem[j].nb_elem += 1;
        tab->elem[j].elem_i = malloc(sizeof(elemen_i_t) * 1);
        tab->elem[j].elem_i[0].key = my_strdup(tab_data[0]);
        tab->elem[j].elem_i[0].value = my_getnbr(tab_data[1]);
        return;
    }
    if (tab->elem[j].nb_elem > 0) {
        tab->elem[j].nb_elem += 1;
        tab->elem[j].elem_i = elem_cpy(tab_data, j, tab);
        return;
    }
}

void fill_elemen(tab_t *tab, char **tab_data, int j)
{
    if (tab_data[0][0] == tab->elem[j].key[0]) {
        add_elem(tab, j, tab_data);
        return;
    }
    free(tab->elem[j].key);
    tab->elem[j].key = NULL;
    tab->elem[j].key = my_strdup(tab_data[0]);
    tab->elem[j].value = my_getnbr(tab_data[1]);
}

int fill_hashage_tab(char **av, tab_t *tab)
{
    char **tab_data = NULL;

    master_sort(av);
    for (int i = 0, j = 0 ; av[i] && j < tab->nb_elem;) {
        if (tab_data == NULL)
            tab_data = my_str_to_word_array(av[i]);
        if (my_strlen_tab(tab_data) != 2) {
            my_putstr("Error : Bad format\n");
            return (84);
        }
        if (tab->elem[j].letter == tab_data[0][0]) {
            fill_elemen(tab, tab_data, j);
            tab_data = free_tab(tab_data);
            (av[i + 1] && av[i][0] == av[i + 1][0]) ? j : j++, i++;
        }
        else if (j < tab->nb_elem && tab->elem[j].letter != tab_data[0][0])
            j++;
    }
    return (0);
}