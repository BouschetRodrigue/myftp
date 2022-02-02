/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** display.c
*/

#include "include/ftp.h"

void help_h(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("       port is the port number ");
    printf("on which the server socket listens\n");
    printf("       path is the path to the home ");
    printf("directory for the Anonymous user\n");
}