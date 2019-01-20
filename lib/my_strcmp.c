/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (-1);
    if (s2[0] == '\0')
        return (-1);
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return (s2[i] - s1[i]);
    }
    return (0);
}

char *my_strdup(char const *str)
{
    int i = 0;
    char *tmp = NULL;

    for (; str && str[i]; i++);
    tmp = malloc(sizeof(char) * (i + 1));
    for (int i = 0; str[i]; i++) {
        tmp[i] = str[i];
    }
    tmp[i] = '\0';
    return (tmp);
}