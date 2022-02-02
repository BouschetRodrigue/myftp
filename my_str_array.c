/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp.c
*/

#include "include/ftp.h"

int count(char *str, char parse, int index)
{
    int i = 0;

    for (; str[index] != '\0' && str[index] != parse; index++, i++);
    return (i);
}

int parse_t(char *str, char parse)
{
    int j = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == parse)
        {
            j++;
        }
    }
    return (j);
}

char **my_str_to_word_array(char *str, char parse)
{
    int nb = parse_t(str, parse);
    char **array = (char **)malloc(sizeof(char *) * (nb + 1));
    int i;
    int index = 0;
    int j;

    for (j = 0; j < nb; j++) {
        array[j] = (char *)malloc(sizeof(
        char) * (count(str, parse, index) + 1));
        if (!array[j])
            return (NULL);
        i = 0;
        for (; str[index] != parse && str[index] != '\0'; i++, index++)
            array[j][i] = str[index];
        array[j][i] = '\0';
        index++;
    }
    array[j] = NULL;
    return (array);
}