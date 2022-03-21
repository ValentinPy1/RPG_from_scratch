/*
** EPITECH PROJECT, 2022
** get_value
** File description:
** SOurce code to get a value of a string into my_parser
*/
#include "get_value.h"

int get_starting_index(char **content, int line)
{
    int counter = 0;

    for (int index = 0; content[line][index] != ':'
    && content[line][index] != '\0'; index++) {
        if (content[line][index] == '\0') {
            write_error(content[line]);
            write_error(" Haven't ':' to asign value\n");
            return (-1);
        }
        counter++;
    }
    return (counter);
}

char *get_value(char **content, int line)
{
    char *value;
    int counter = 0;
    int index2 = 0;
    int st_index = get_starting_index(content, line);

    for (int index = st_index + 1; content[line][index] != '\0'; index++) {
        counter++;
    }
    value = malloc((counter + 1) * sizeof(char));
    for (int index = st_index + 1; content[line][index] != '\0'; index++) {
        value[index2] = content[line][index];
        index2++;
    }
    value[index2] = '\0';
    return (value);
}
