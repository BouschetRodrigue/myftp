/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "include/ftp.h"

int standard2(int srv_socket, struct ftp *varia, char **temp)
{
    if (strcmp(temp[0], "NOOP\n") == 0 || strcmp(temp[0], "NOOP\r\n") == 0)
        write(srv_socket, "200\n", 4);
    else
        write (srv_socket, "500\n", 4);
    return (0);
}

int standard1(int srv_socket, struct ftp *varia, char **temp)
{
    if (strcmp(temp[0], "HELP\n") == 0 || strcmp(temp[0], "HELP\r\n") == 0)
        help(srv_socket);
    else if (strcmp(temp[0], "PWD\n") == 0 || strcmp(temp[0], "PWD\r\n") == 0)
        pwd(srv_socket, varia);
    else
        standard2(srv_socket, varia, temp);
    return (0);
}

int command_manager(int srv_socket, char *buff, struct ftp *varia)
{
    char **temp = my_str_to_word_array(buff, ' ');

    if (!temp) {
        write(srv_socket, "xxx\n", 4);
        return (0);
    }
    if (strcmp(temp[0], "USER") == 0)
        user(srv_socket, temp[1], varia);
    else if (strcmp(temp[0], "PASS") == 0)
        pass(srv_socket, temp[1], varia);
    else
        standard1(srv_socket, varia, temp);
    return (0);
}

int manage(int srv_socket, struct ftp *varia)
{
    char buff[4096];

    write(srv_socket, "220\n", 4);
    for (;;) {
        bzero(buff, 4096);
        read(srv_socket, buff, sizeof(buff));
        if (strncmp("QUIT", buff, 4) == 0) {
            quit(srv_socket, varia);
            write(srv_socket, "221\n", 4);
            close(srv_socket);
        }
        if (strlen(buff) > 0)
            command_manager(srv_socket, buff, varia);
    }
    return (0);
}