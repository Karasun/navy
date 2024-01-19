/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#include "../inc/navy.h"

int main(int ac, char **av)
{
    if (av[1] && av[1][1] && av[1][0] &&
        av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return (0);
    }
    if (ac == 2) {
        first_host();
        return (0);
    }
    if (ac == 3) {
        second_host(my_getnbr(av[1]));
        return (0);
    }
}
