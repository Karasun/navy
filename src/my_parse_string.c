/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_shell.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

void    my_putchar(char c);

char *my_parse_string(char *s, int pos)
{
    char *sf = malloc(sizeof(char) * (my_strlen(s) + 1));
    int i = 0;

    for (i = pos; i < my_strlen(s); i++) {
        if ((s[i] != ' ') && (s[i] != '\t') && (s[i] != ':') && (s[i] != '=')) {
            sf[i - pos] = s[i];
            my_putchar(s[i]);
        }
        else
            break;
    }
    sf[i - pos] = '\0';
    return (sf);
}
