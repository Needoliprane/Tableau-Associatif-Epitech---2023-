/*
** EPITECH PROJECT, 2019
** tableau de hashage
** File description:
** tab_hashage
*/

#ifndef TAB_HASHAGE_H_
#define TAB_HASHAGE_H_

/* Include */

#include <stdbool.h>

/* Struct */

typedef struct eleme_i_s {
    char *key;
    int value;
} elemen_i_t;

typedef struct eleme_s {
    int nb_elem;
    char letter;
    char *key;
    int value;
    elemen_i_t *elem_i;
} elemen_t;

typedef struct tab_s {
    int nb_elem;
    elemen_t *elem;
} tab_t;

/* Create */

tab_t *create_tab(int nb);

/* Hashage */

int fill_hashage_tab(char **av, tab_t *tab);

/* Find index */

int find_key(char const *key, tab_t *tab);

/* Read */

void print_simple_cellule(tab_t *tab, int i);

/* Print */

void print_hashage(tab_t *tab, bool print_empty);

/* Destroy */

void tab_hashage_destroy(tab_t *tab);

/* LIB */

int my_strlen_tab(char **av);
int my_strlen(char const *str);
void swap(char **s1, char **s2);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
void master_sort(char **stock_file);
char **my_str_to_word_array(char const *str);
int my_getnbr(char const *str);
char **free_tab(char **tab);
void my_putchar(char c);
char *my_strdup(char const *str);
int my_put_nbr(int nb);

#endif /* !TAB_HASHAGE_H_ */

