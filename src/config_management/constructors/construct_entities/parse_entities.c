/*
** EPITECH PROJECT, 2022
** parse_entities
** File description:
** Source code to construct entities of a scene
*/
#include "construct_entity.h"

int get_nb_entities(char **content, int entities)
{
    int counter = 0;

    for (entities = entities; content[entities] != NULL
    && nb_char_in_str(content[entities], '\t') != 1; entities++) {
        if (nb_char_in_str(content[entities], '\t') == 2)
            counter++;
    }
    return (counter);
}

int assign_entity_value(entity_t *entity, char *keyword,
                        char *value, int index)
{
    if (my_strcmp(ENT_CONS[index].name, keyword) == 1)
        if ((*ENT_CONS[index].func)(entity, value) == -1) {
            write_error("Error while loading entities\n");
            return (-1);
        }
    return (0);
}

int get_entity_value(entity_t *entity, char **content, int line)
{
    char *keyword;
    char *value;

    keyword = get_keyword(content[line]);
    value = get_value(content[line]);
    for (int index = 0; ENT_CONS[index].name != NULL; index++) {
        if (assign_entity_value(entity, keyword, value, index) == -1)
            return (-1);
    }
    free(keyword);
    free(value);
    return (0);
}

void create_entity(entity_t *entity, char **content, int line)
{
    for (line += 1; nb_char_in_str(content[line], '\t') == 3; line++) {
        if (get_entity_value(entity, content, line) == -1)
            entity = NULL;
    }
}

void construct_entity(scene_t *scene, char **content, int index)
{
    int entities = index + 1;
    int entity_index = 0;
    int nb_entities = get_nb_entities(content, entities);
    entity_t **list_entities = malloc((nb_entities + 1) * sizeof(entity_t));

    for (entities = entities; content[entities] != NULL
        && nb_char_in_str(content[entities], '\t') != 1; entities++) {
        if (nb_char_in_str(content[entities], '\t') == 2) {
            list_entities[entity_index] = malloc(sizeof(entity_t));
            create_entity(list_entities[entity_index], content, entities);
            entity_index++;
        }
    }
    list_entities[entity_index] = NULL;
    scene->entities = list_entities;
    return;
}
