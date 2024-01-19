/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#include "../inc/navy.h"

void    my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb < 10) {
        my_putchar(nb % 10 + 48);
    } else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int rez = 0;
    int ng = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            ng *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        rez *= 10;
        rez += str[i] - 48;
        i++;
    }
    return (rez * ng);
}

void    display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player.");
    my_putstr("  pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the ");
    my_putstr("positions of the ships.\n");
}
