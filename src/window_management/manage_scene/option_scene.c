/*
** EPITECH PROJECT, 2022
** option_scene
** File description:
** Source code to
*/
#include "structures.h"
#include "manage_display.h"
#include <stdlib.h>

void print_xp(data_t *game_data, scene_t *option_scene)
{
    sfText *xp = get_text(option_scene->texts, "xp")->text;
    char *nb_xp = my_getstr(game_data->red->stats->xp);
    char *full_xp = my_strconc("xp:\n", nb_xp);

    sfText_setString(xp, full_xp);
    free(nb_xp);
    free(full_xp);
}

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
