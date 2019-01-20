/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** swap
*/

void swap(char **s1, char **s2)
{
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}