/*
** EPITECH PROJECT, 2022
** constructors
** File description:
** Source code to construct scene
*/
#include "constructors.h"

void construct_name(scene_t *scene, char **content, int index)
{
    char *value = get_value(content, index);

    if (my_strcmp(value, "home_menu")) {
        scene->is_running = 1;
    } else {
        scene->is_running = 0;
    }
    if (my_strcmp(value, "game_menu"))
        scene->map = map_constructor();
        scene->gun_loc_sprite = sfSprite_create();
        scene->gun_loc_texture = sfTexture_createFromFile(
                                    "img/gun_loc.png", NULL);
        sfSprite_setTexture(scene->gun_loc_sprite,
                                scene->gun_loc_texture, sfFalse);
        scene->zombie = fill_zombie();
    scene->name = value;
}

void constructor(scene_t *scene, char **content, int line)
{
    char *keyword = get_keyword(content[line]);

    if (my_strcmp(keyword, "buttons") == 1)
        construct_button(scene, content, line);
    if (my_strcmp(keyword, "entities") == 1)
        construct_entity(scene, content, line);
    if (my_strcmp(keyword, "background") == 1)
        construct_background(scene, content, line);
    if (my_strcmp(keyword, "name") == 1)
        construct_name(scene, content, line);
}
