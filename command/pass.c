/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "../include/ftp.h"

int pass(int srv_socket, char *buffer, struct ftp *var)
{
    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 2] = '\0';
    if (var->user_status == 1) {
        if (strcmp(var->user, "Anonymous") == 0 && strcmp(buffer, "") == 0) {
            var->user_status = 2;
            write(srv_socket, "230 User logged in, proceed.\n", 29);
            return (0);
        }
        else {
            var->user_status = 1;
            write(srv_socket, "530\n", 4);
            return (0);
        }
    }
    else {
        var->user_status = 1;
        write(srv_socket, "530\n", 4);
        return (0);
    }
}