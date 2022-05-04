/*
** EPITECH PROJECT, 2022
** callbacks
** File description:
** Header
*/

#ifndef CALLB_H_
    #define CALLB_H_
    #include <stddef.h>
    #include <unistd.h>
    #include "structures.h"

int my_putstr(char *str);
int my_strcmp(char *str1, char *str2);
void load_vertices(hitbox_t *hitbox);

#endif /*CALLB_H_*/
