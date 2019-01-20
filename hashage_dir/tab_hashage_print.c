/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** tab_hashage_tool
*/

#include <stdio.h>
#include "tab_hashage.h"

void print_simple_cellule(tab_t *tab, int i)
{
    if (i == -1) {
        my_putstr("Error cellule not find\n");
        return;
    }
    my_putstr("Key : ");
    my_putstr(tab->elem[i].key);
    my_putstr(", data : ");
    my_put_nbr(tab->elem[i].value);
    my_putstr(", Index : ");
    my_put_nbr(i);
    my_putstr("\n");
}

void print_no_elem(tab_t *tab, int i)
{
    my_putstr("No element for ");
    my_putchar(tab->elem[i].letter);
    my_putstr(" letter\n");
}

void print_inside_cellule(tab_t *tab, int i)
{
    print_simple_cellule(tab, i);
    for (int p = 0; p < tab->elem[i].nb_elem; p++) {
        for (int j = 0; j <= p; j++) {
            my_putstr("---");
        }
        my_putstr("> Key : ");
        my_putstr(tab->elem[i].elem_i[p].key);
        my_putstr(", data : ");
        my_put_nbr(tab->elem[i].elem_i[p].value);
        my_putstr(", Index in cell : ");
        my_put_nbr(p);
        my_putstr("\n");
    }
}

void print_hashage(tab_t *tab, bool print_empty)
{
    for (int i = 0; i < tab->nb_elem; i++) {
        if (print_empty == true && tab->elem[i].key[0] == '\0')
            print_no_elem(tab, i);
        if (tab->elem[i].key[0] != '\0' && tab->elem[i].nb_elem != 0)
            print_inside_cellule(tab, i);
        if (tab->elem[i].key[0] != '\0' && tab->elem[i].nb_elem == 0)
            print_simple_cellule(tab, i);
    }
}