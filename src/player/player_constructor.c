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
    stats->heal = 5;
    stats->spd = 2;
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
    player->is_in_house = false;
    player->kill_streak = 0;
}

static sounds_t *get_sound(void)
{
    sounds_t *effects = malloc(sizeof(sounds_t));
    effects->kill = sfSound_create();
    effects->kill_buffer = sfSoundBuffer_createFromFile("assets/snd/kill.ogg");
    sfSound_setBuffer(effects->kill, effects->kill_buffer);
    effects->swing = sfSound_create();
    effects->swing_buffer =
    sfSoundBuffer_createFromFile("assets/snd/swing.ogg");
    sfSound_setBuffer(effects->swing, effects->swing_buffer);
    effects->slash = sfSound_create();
    effects->slash_buffer =
    sfSoundBuffer_createFromFile("assets/snd/slash.ogg");
    sfSound_setBuffer(effects->slash, effects->slash_buffer);
    effects->hit = sfSound_create();
    effects->hit_buffer =
    sfSoundBuffer_createFromFile("assets/snd/player_hit.ogg");
    sfSound_setBuffer(effects->hit, effects->hit_buffer);
    effects->fall = sfSound_create();
    effects->fall_buffer =
    sfSoundBuffer_createFromFile("assets/snd/fall.ogg");
    sfSound_setBuffer(effects->fall, effects->fall_buffer);
    return effects;
}

player_t *player_constructor(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfClock *clk = sfClock_create();
    sfClock *att_clk = sfClock_create();
    sfTime tm = sfClock_getElapsedTime(clk);
    sfTime att_tm = sfClock_getElapsedTime(att_clk);

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
    player->effects = get_sound();
    return player;
}
