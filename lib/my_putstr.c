/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    for (; str[i]; i++);
    write(1, str, i);
    return (0);
}

int my_show_word_array(char **tab)
{
    for (int i = 0; tab && tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}