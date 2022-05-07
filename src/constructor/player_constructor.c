/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** player_constructor.c
*/

#include "player.h"
#include <stdlib.h>

static stats_t *setup_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));
    stats->att = 19;
    stats->def = 5;
    stats->spd = 20;
    return stats;
}

static void set_player_values(player_t *player)
{
    player->pos.x = 13 * 32;
    player->pos.y = 9 * 32;
    player->attack_state = 0;
    player->stats = setup_stats();
    player->facing = 0;
    player->kb_dir = 0;
    player->kb_speed = 0;
    player->percentage = 0;
    player->view = sfView_create();
}

static void get_sound(sfSoundBuffer **buffer, sfSound **sound, char *path)
{
    *buffer = sfSoundBuffer_createFromFile(path);
    *sound = sfSound_create();
    sfSound_setBuffer(*sound, *buffer);
}

player_t *player_constructor(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfClock *clk = sfClock_create();
    sfClock *att_clk = sfClock_create();
    sfTime tm;
    sfTime att_tm;

    set_player_values(player);
    player->player_sprite =
    create_sprite("assets/img/player/player_ss.png", 2, 2);
    player->player_rect = set_rect(16);
    player->attack_sprite =
    create_sprite("assets/img/player/attack_ss.png", 2, 2);
    player->attack_rect = set_rect(32);
    player->attack_clock = att_clk;
    player->attack_time = att_tm;
    player->clock = clk;
    player->time = tm;
    player->stats = setup_stats();
    get_sound(&player->kill_buffer, &player->kill, "assets/snd/kill.ogg");
    return player;
}
