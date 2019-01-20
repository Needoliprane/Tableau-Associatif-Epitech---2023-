/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** main
*/

#include <stddef.h>
#include "./hashage_dir/tab_hashage.h"

int main(int ac, char **av)
{
    tab_t *tab = create_tab(26);
    int index = 0;

    if (ac == 1) {
        my_putstr("Not enough av\n");
        return (84);
    }
    if (fill_hashage_tab(av + 1, tab) == 84)
        return (84);
    print_hashage(tab, false);
    index = find_key("b", tab);
    my_putstr("\nRead of one cell\n---->");
    print_simple_cellule(tab, index);
    tab_hashage_destroy(tab);
}