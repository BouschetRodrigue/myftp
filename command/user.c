/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "../include/ftp.h"

int user(int srv_socket, char *buffer, struct ftp *varia)
{
    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 2] = '\0';
    varia->user = malloc(sizeof(buffer));
    if (varia->user != NULL) {
        strcpy(varia->user, buffer);
        varia->user_status = 1;
        write(srv_socket, "331 User name okay, need password.\n", 35);
        return (0);
    } else {
        varia->user_status = 0;
        write(srv_socket, "xxx\n", 4);
        return (84);
    }
}