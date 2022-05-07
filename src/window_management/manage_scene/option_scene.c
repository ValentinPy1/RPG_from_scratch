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
    sfText *attack = get_text(option_scene->texts, "attack_text")->text;
    sfText *defense = get_text(option_scene->texts, "defense_text")->text;
    sfText *speed = get_text(option_scene->texts, "speed_text")->text;
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
