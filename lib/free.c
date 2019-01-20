/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** free
*/

#include <stdlib.h>

char **free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    return (NULL);
}