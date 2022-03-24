/*
** EPITECH PROJECT, 2022
** constructors
** File description:
** Source code to construct scene
*/
#include "construct_scenes.h"

void construct_name(scene_t *scene, char **content, int index)
{
    char *value = get_value(content, index);
    
    scene->name = value;
}

void constructor(scene_t *scene, char **content, int line)
{
    char *keyword = get_keyword(content[line]);

    //TO DO ADD TEXT
    if (my_strcmp(keyword, "name") == 1)
        construct_name(scene, content, line);
    if (my_strcmp(keyword, "buttons") == 1)
        construct_button(scene, content, line);
    if (my_strcmp(keyword, "entities") == 1)
        construct_entity(scene, content, line);
}
