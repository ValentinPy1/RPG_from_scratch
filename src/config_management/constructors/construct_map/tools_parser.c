/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** tools_parser.c
*/

#include "map_parser.h"

int get_nb_row(char **tab)
{
    int row;

    for (row = 0; tab[row] != NULL; row ++);
    return (row);
}
