/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "../include/ftp.h"

int pwd(int srv_socket, struct ftp *varia)
{
    write(srv_socket, "530\n", 4);
    return (84);
}