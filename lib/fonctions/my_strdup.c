/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** my_strdup.c
*/

char *my_strdup(char *str)
{
    char *dup = malloc(my_strlen(str) + 1);
    my_strcpy(dup, str);
    return dup;
}
