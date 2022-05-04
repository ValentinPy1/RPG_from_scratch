/*
** EPITECH PROJECT, 2022
** build_scene_entities
** File description:
** Header
*/

#ifndef BUILD_SCENE_ENTITIES_H_
    #define BUILD_SCENE_ENTITIES_H_
    #include "stddef.h"
    #include "structures.h"

static char *entitie_set[] = {
    "name",
    "posx",
    "posy",
    "width",
    "height",
    "scale",
    "rotation",
    "hostile"
    "texture",
    "hit_texture",
    "death_texture",
    "hit_sound",
    "death_sound",
    "dialogue",
    NULL
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_ENTITIES_H_ */
