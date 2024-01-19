/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#include <unistd.h>

void my_putstr(char const *str);

int my_strcmp(char *pos_dep, char *pos_fin);

void my_shot(char *coor);

char **my_str_to_word_array(char *str);

int my_getnbr(char const *str);

int check_coor_ship(int size, int boat_start_x_pos, int boat_end_x_pos,
int boat_start_y_pos, int boat_end_y_pos);

/*int main(int ac, char **av)
{
    char **tab = NULL;

    tab = my_str_to_word_array(av[1]);
    check_coor_ship(my_getnbr(tab[0]), tab[1], tab[2]);
    return (0);
}*/

int my_strcmp(char *pos_dep, char *pos_fin)
{
    int i = 0;

    while (pos_dep[i] != '\0') {
        if (pos_dep[i] == pos_fin[i]) {
            i++;
            break;
        } else
            break;
    }
    if (((pos_dep[i] < 'A') && (pos_dep[i] > '8')) || (pos_dep[i] > 'H') ||
    (pos_dep[i] < '1') || ((pos_fin[i] < 'A') && (pos_fin[i] > '8')) ||
    (pos_fin[i] > 'H') || (pos_fin[i] < '1')) {
        my_putstr("wrong position\n");
        return (-1);
    }
    else {
        my_putstr("good position\n");
        return (0);
    }
}

void my_shot(char *coor)
{
    int i = 0;

    if ((coor[i] >= 'A') && (coor[i] <= 'H')) {
        i++;
        if ((coor[i] >= '1') && (coor[i] <= '8'))
            my_putstr("FIRE !!!!!!\n");
        else
            my_putstr("Unable to fire\n");
    } else
        my_putstr("Unable to fire\n");
}

int check_coor_ship(int size, int boat_start_x_pos, int boat_end_x_pos,
int boat_start_y_pos, int boat_end_y_pos)
{
    int orientation = 0;
    int hyp = 0;
    int side_1 = 0;
    int side_2 = 0;

    hyp = (size - 1) * (size - 1);
    side_1 = (boat_start_x_pos - boat_end_x_pos) * (boat_start_x_pos - boat_end_x_pos);
    side_2 = (boat_start_y_pos - boat_end_y_pos) * (boat_start_y_pos - boat_end_y_pos);
    printf("%d\n%d\n%d\n", hyp, side_1, side_2);
    if (hyp == side_1 + side_2) {
        if (boat_start_x_pos - boat_end_x_pos == 0) {
            orientation = 0;
            my_putstr("good position\n");
        } else if (boat_start_y_pos - boat_end_y_pos == 0) {
            orientation = 1;
            my_putstr("good position\n");
        } else {
            orientation = 2;
            my_putstr("wrong position\n");
        }
    } else {
        orientation = 2;
        my_putstr("wrong position\n");
    }
    return (orientation);
}
