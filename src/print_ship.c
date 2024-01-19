#include <stddef.h>

#include <stdlib.h>

#include <stddef.h>

#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

void my_putstr(char const *str);

void my_putchar(char c);

int my_strcmp(char *pos_dep, char *pos_fin);

void my_shot(char *coor);

char * *shot_fired(int pos_x, int pos_y, char **map);

char * *my_str_to_word_array(char *str);

char *my_parse_string(char *s, int pos);

char * *print_ship(char boat_type, int pos_x, int pos_y, char **map);

int pos_num(char pos);

int check_coor_ship(int size, int boat_start_x_pos, int boat_end_x_pos,
                    int boat_start_y_pos, int boat_end_y_pos);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char * *get_map(char const *filepath);

char * *get_map(char const *filepath)
{
    int i = 0;
    int fd = 0;
    char **map = NULL;

    fd = open(filepath, O_RDONLY);
    map = malloc(sizeof(char *) * 9);
    my_putstr("  |A B C D E F G H\n -+---------------\n");
    while (i < 8) {
        map[i] = malloc(sizeof(char) * 19 + 1);
        read(fd, map[i], 19);
        my_putstr(map[i]);
        i++;
    }
    map[7][19] = '\0';
    map[8] = NULL;
    close(fd);
    return (map);
}

char **print_map(char **map)
{
    int i = 0;

    my_putstr("  |A B C D E F G H\n -+---------------\n");
    while (i <= 8) {
        my_putstr(map[i]);
        i++;
    }
    map[8][19] = '\0';
    return (map);
}

int pos_num(char pos)
{
    int res = 0;

    res = pos - 64;
    return (res);
}

char **shot_fired(int pos_x, int pos_y, char **map)
{
    if (map[pos_y - 1][2 * pos_x + 1] != '.')
        map[pos_y - 1][2 * pos_x + 1] = 'x';
    else if (map[pos_y - 1][2 * pos_x + 1] == '.')
        map[pos_y - 1][2 * pos_x + 1] = 'o';
    return (map);
}

char **print_ship(char boat_type, int pos_x, int pos_y, char **map)
{
    map[pos_y - 1][2 * pos_x + 1] = boat_type;
    return (map);
}

int main(int ac, char **av)
{
    char **tab = NULL;
    char boat_type = 0;
    char **map = NULL;
    //char *shot = NULL;
    int i = 0;
    int orientation = 0;
    int boat_size = 0;
    int boat_start_x_pos = 0;
    int boat_start_y_pos = 0;
    int boat_end_x_pos = 0;
    int boat_end_y_pos = 0;
    int j = 0;


    //shot = malloc(sizeof(char) * 3);
    tab = malloc(sizeof(int) * (3 + 1));
    if (ac < 3)
        return (0);
    my_putstr(av[2]);
    my_putchar('\n');
    printf("%d\n", my_strlen(av[2]));
    while (j <= 2) {
        tab[j] = my_parse_string(av[2], i);
        if (j == 0) {
            boat_type = tab[0][0];
            boat_size = boat_type - 48;
        } else if (j == 1) {
            boat_start_x_pos = pos_num(tab[1][0]);
            boat_start_y_pos = tab[1][1] - 48;
        } else if (j == 2) {
            boat_end_x_pos = pos_num(tab[2][0]);
            boat_end_y_pos = tab[2][1] - 48;
        }
        i = i + my_strlen(tab[j]) + 1;
        j++;
    }
    /*shot[0] = pos_num(av[3][0]);
       shot[1] = pos_num(av[3][1]);
       shot[2] = '\0';*/
    printf("\nboat_type = %c\n, start %d,%d\n, end %d,%d\n", boat_type, boat_start_x_pos, boat_start_y_pos, boat_end_x_pos, boat_end_y_pos);
    orientation = check_coor_ship(boat_size, boat_start_x_pos, boat_end_x_pos, boat_start_y_pos, boat_end_y_pos);
    map = get_map(av[1]);
    for (i = 0; i < boat_size; i++) {
        if (orientation == 0)
            print_ship(boat_type, boat_start_x_pos, boat_start_y_pos + i, map);
        else
            print_ship(boat_type, boat_start_x_pos + i, boat_start_y_pos, map);
    }
    //shot_fired(shot[0], shot[1], map);
    print_map(map);
    return (0);
}
