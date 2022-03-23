/*
** EPITECH PROJECT, 2022
** my_parser
** File description:
** Header
*/

#ifndef PARS_H_
    #define PARS_H_
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "structures.h"

int nb_char_in_str(char *str, char c);

int error_handling(char **content);

void constructor(scene_t *scene, char **content, int line);

#endif /*PARS_H_*/
