/*
** EPITECH PROJECT, 2022
** construct_scene
** File description:
** Source code to parse a config file
*/
#include "my_parser.h"

void init_scene(scene_t *scene, char **content)
{
    int line;
    int nb_tab;

    scene->buttons = NULL;
    scene->entities = NULL;
    scene->texts = NULL;
    scene->background_to_run = 0;
    scene->map = NULL;
    for (line = 0; content[line] != NULL; line++) {
        nb_tab = nb_char_in_str(content[line], '\t');
        if (nb_tab != 2)
            constructor(scene, content, line);
    }
}

scene_t *my_parser(char **content)
{
    scene_t *new_scene = malloc(sizeof(scene_t));

    if (content == NULL || error_handling(content) == 1)
        return (NULL);
    init_scene(new_scene, content);
    return (new_scene);
}
