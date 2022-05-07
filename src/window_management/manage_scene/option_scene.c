/*
** EPITECH PROJECT, 2022
** option_scene
** File description:
** Source code to
*/
#include "structures.h"
#include "manage_display.h"
#include <stdlib.h>

void update_stats(data_t *game_data, scene_t *option_scene)
{
    sfText *attack = get_text(option_scene->texts, "attack")->text;
    sfText *healing = get_text(option_scene->texts, "heal")->text;
    sfText *speed = get_text(option_scene->texts, "speed")->text;
    char *att = my_getstr(game_data->red->stats->att);
    char *heal = my_getstr(game_data->red->stats->heal);
    char *spd = my_getstr(game_data->red->stats->spd);

    sfText_setString(attack, att);
    sfText_setString(healing, heal);
    sfText_setString(speed, spd);
    free(att);
    free(heal);
    free(spd);
}
