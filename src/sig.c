/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#include "../inc/navy.h"

int connect = 0;

int first_host(void)
{
    struct sigaction act;

    act.sa_sigaction = &trade_pid;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &act, NULL);
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\nwaiting for enemy connection...\n");
    pause();
    my_putstr("\nenemy connection\n\n");
    return (0);
}

int second_host(int my_pid)
{
    kill(my_pid, SIGUSR2);
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\nsuccessfully connected\n\n");
    return (0);
}

void    trade_pid(int sig, siginfo_t *new, void *cont)
{
    if (sig == SIGUSR2)
        connect = new->si_pid;
}
