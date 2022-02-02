/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "../include/ftp.h"

int quit(int srv_socket, struct ftp *varia)
{
    varia->user_status = 0;
    varia->user = NULL;
    multi_proc(2);
    return (0);
}