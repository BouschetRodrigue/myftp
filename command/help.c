/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "../include/ftp.h"

int help(int srv_socket)
{
    write(srv_socket, "214\n", 4);
    return (0);
}