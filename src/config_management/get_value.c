/*
** EPITECH PROJECT, 2022
** get_value
** File description:
** SOurce code to get a value of a string into my_parser
*/
#include "get_value.h"

int get_starting_index(char *str)
{
    int counter = 0;

    for (int index = 0; str[index] != ':' && str[index] != '\0'; index++) {
        if (str[index] == '\0') {
            write_error(str);
            write_error(" Haven't ':' to asign value\n");
            return (-1);
        }
        counter++;
    }
    return (counter);
}

char *get_value(char *str)
{
    char *value;
    int counter = 0;
    int index2 = 0;
    int st_index = get_starting_index(str);

    for (int index = st_index + 1; str[index] != '\0'; index++) {
        counter++;
    }
    value = malloc((counter + 1) * sizeof(char));
    for (int index = st_index + 1; str[index] != '\0'; index++) {
        value[index2] = str[index];
        index2++;
    }
    value[index2] = '\0';
    return (value);
}
