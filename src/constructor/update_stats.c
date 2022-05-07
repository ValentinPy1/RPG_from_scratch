/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display_stats.c
*/

#include "structures.h"
#include "manage_display.h"

void update_stats(data_t *game_data)
{
    sfText *attack = game_data->scene_list[2]->texts[0];
    sfText *defense = game_data->scene_list[2]->texts[1];
    sfText *speed = game_data->scene_list[2]->texts[2];
    char *att = my_getstr(game_data->red->stats->att);
    char *def = my_getstr(game_data->red->stats->def);
    char *spd = my_getstr(game_data->red->stats->spd);
    sfText_setString(attack, att);
    sfText_setString(defense, def);
    sfText_setString(speed, spd);
    free(att);
    free(def);
    free(spd);
}
