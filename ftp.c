/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "include/ftp.h"

int multi_proc(int processus)
{
    static int nb;
    if (processus == 1)
        nb++;
    else if (processus == 2)
        nb--;
    return (nb);
}

int init_client(struct sockaddr_in *client, char *port, int init_socket)
{
    socklen_t length;
    int connfd;

    while (1) {
        listen(init_socket, 42);
        length = sizeof(client);
        connfd = accept(init_socket, (struct sockaddr *)&client, &length);
        if (connfd < 0) {
            close(init_socket);
            return (-1);
        }
        int pid = fork();

        if (pid < 0)
            return (84);
        else if (pid > 0) {
            multi_proc(1);
            return (connfd);
        }
    }
}

int init_sockaddr(char *port)
{
    int init_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveur;
    struct sockaddr_in client;

    serveur.sin_family = AF_INET;
    serveur.sin_addr.s_addr = htonl(INADDR_ANY);
    serveur.sin_port = htons(atoi(port));
    if (bind(init_socket, (struct sockaddr *)&serveur, sizeof(serveur)) != 0)
    {
        close(init_socket);
        return (-1);
    }
    return (init_client(&client, port, init_socket));
}
