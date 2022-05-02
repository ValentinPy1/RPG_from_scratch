/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** Source code to handle error in my parcer
*/
#include "error_handling.h"

int nb_char_in_str(char *str, char c)
{
    int counter = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == c)
            counter++;
    }
    return (counter);
}

int is_in_list(char **list, char *str)
{
    char *keyword;
    int flag = 0;

    keyword = get_keyword(str);
    for (int index = 0; list[index] != NULL; index++) {
        if (my_strcmp(list[index], keyword) == 1)
            flag = 1;
    }
    if (flag == 0) {
        write_error("[");
        write_error(keyword);
        write_error("] Is not a valid parameter.\n");
    }
    free(keyword);
    return (flag);
}

int is_invalid_line(char **content, int line)
{
    int nb_tab = nb_char_in_str(content[line], '\t');
    return (0);
}

int error_handling(char **content)
{
    int line;

    for (line = 0; content[line] != NULL; line++) {
        if (is_invalid_line(content, line) == 1)
            return (1);
    }
    return (0);
}
