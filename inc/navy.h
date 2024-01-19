/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#ifndef NAVY_H_
# define NAVY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int ac, char **av);
void    display_help(void);
void    my_putchar(char c);
void    my_putstr(char *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
char    **set_map(void);
void    print_map(void);
void    trade_pid(int sig, siginfo_t *new, void *cont);
int first_host(void);
int second_host(int my_pid);

#endif
