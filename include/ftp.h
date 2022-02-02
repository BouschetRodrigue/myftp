/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.h
*/

#ifndef _FTP_H
#define _FTP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <dirent.h>

struct ftp
{
    int user_status;
    char *user;
    char ***env;
};

void help_h(void);
int init_sockaddr(char *port);
int manage(int srv_socket, struct ftp *varia);
int multi_proc(int processus);
char **my_str_to_word_array(char *str, char parse);
int quit(int srv_socket, struct ftp *varia);
int user(int srv_socket, char *buffer, struct ftp *varia);
int pass(int srv_socket, char *buffer, struct ftp *var);
int help(int srv_socket);
int pwd(int srv_socket, struct ftp *varia);

#endif
