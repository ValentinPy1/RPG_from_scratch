/*
** EPITECH PROJECT, 2022
** get_keyword
** File description:
** Source code to get keyword of a line into my_parser
*/
#include "get_keyword.h"

char *get_keyword(char *str)
{
    int counter = 0;
    char *keyword;
    int index2 = 0;

    for (int index = 0; str[index] != ':'; index++) {
        if (str[index] != '\t')
            counter++;
    }
    keyword = malloc((counter + 1) * sizeof(char));
    for (int index = 0; str[index] != ':'; index++) {
        if (str[index] != '\t') {
            keyword[index2] = str[index];
            index2++;
        }
    }
    keyword[index2] = '\0';
    return (keyword);
}
