/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#include "../inc/navy.h"

char    **set_map(void)
{
    int line = 1;
    char **map = malloc(sizeof(char *) * 9);

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int y = 0; y <= 8; y++) {
        map[y] = malloc(sizeof(char) * 16);
        for (int x = 0; x <= 15; x++) {
            map[y][x] = '.';
            if (x % 2 != 0 && x <= 15)
                map[y][x] = ' ';
        }
        map[y][15] = '\0';
    }
    map[8] = NULL;
    line++;
    return (map);
}

void    print_map(void)
{
    char **map = set_map();
    int line = 1;

    for (int i = 0; map[i]; i++) {
        my_put_nbr(line);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
        line++;
    }
}
