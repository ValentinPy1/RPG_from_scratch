/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/

#include "construct_button.h"
#include "construct_callbacks.h"

int but_construct_callback(button_t *button, char *value)
{
    for (int index = 0; BUT_CALL[index].name != NULL; index++) {
        if (my_strcmp(BUT_CALL[index].name, value) == 1) {
            button->callback = BUT_CALL[index].func;
            return (0);
        }
    }
    write_error("Unable to find :\"");
    write_error(value);
    write_error("\".\n");
    return (-1);
}
// TO DO CLICKED TEXTURE
