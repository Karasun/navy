/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my_str_to_word_array
*/

#include <stddef.h>

#include <stdlib.h>

int my_strlen(char const *str);

char *begining_str(char *str)
{
    int i = 0;

    while (str[i] == ' ')
        i++;
    return (str);
}

int my_str_alphanum(char c)
{
    if (c == ' ' || c == ':')
        return (0);
    return (1);
}

int count_words(char const *str)
{
    int count = 0;
    int flag = 0;

    for (int n = 0; str[n] != '\0'; n++) {
        if (my_str_alphanum(str[n]) == 1 && flag == 0) {
            count++;
            flag = 1;
        } else
            if (my_str_alphanum(str[n]) == 0)
                flag = 0;
    }
    return (count);
}

char *check_spaces(char *str)
{
    char *tmp = malloc(sizeof(char *) * my_strlen(str) - 1);
    int i = 0;

    str = begining_str(str);
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] != ' ')
            tmp[i++] = str[j];
        else
            if (tmp[i - 1] != ' ')
                tmp[i++] = str[j];
    }
    tmp[i] = '\0';
    return (tmp);
}

int count_size(char *str)
{
    int tmp = 0;
    int word = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (my_str_alphanum(str[j]) == 1)
            tmp++;
        else
            tmp = 0;
        if (word < tmp)
            word = tmp;
    }
    return (word);
}

char **my_str_to_word_array(char *str)
{
    char **dest = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    str = check_spaces(str);
    k = count_words(str);
    dest = malloc(sizeof(char *) * k + 1);
    for (int y = 0; y < k; y++)
        dest[y] = malloc(sizeof(char) * count_size(str));
    for (int l = 0; str[l] != '\0'; l++) {
        if (my_str_alphanum(str[l]) == 1) {
            dest[i][j++] = str[l];
        } else {
            dest[i++][j] = '\0';
            j = 0;
        }
    }
    dest[++i] = NULL;
    return (dest);
}
