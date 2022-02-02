/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** main.c
*/

#include "include/ftp.h"

int str_is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 48 || str[i] > 57)
            return (84);
    }
    return (0);
}

int error2(int ac, char **av)
{
    if (ac != 3)
    {
        help_h();
        return (84);
    }
    else if (str_is_digit(av[1]) == 84)
    {
        printf("Error port\n");
        return (84);
    }
    return (0);
}

int error(int ac, char **av)
{
    if (ac <= 1)
    {
        help_h();
        return (84);
    }
    else if (strcmp(av[1], "-help") == 0)
    {
        help_h();
        return (1);
    }
    return (error2(ac, av));
}

int main(int ac, char **av, char **envp)
{
    int result = error(ac, av);
    int srv_socket;
    struct ftp varia;

    if (result == 84)
        return (84);
    else if (result == 1)
        return (1);
    srv_socket = init_sockaddr(av[1]);
    if (srv_socket == -1)
        return (84);
    else if (srv_socket == -2)
        return (0);
    varia.env = &envp;
    manage(srv_socket, &varia);
    return (0);
}