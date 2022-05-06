/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** player_constructor.c
*/

#include "structures.h"
#include <stdlib.h>

sfIntRect *set_rect(int size)
{
    sfIntRect *rectangle = malloc(sizeof(sfIntRect));
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = size;
    rectangle->height = size;
    return rectangle;
}

sfSprite *create_sprite(char const *filepath, float x, float y)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};
    sfVector2f origin = {8, 8};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setOrigin(sprite, origin);
    return (sprite);
}

static stats_t *setup_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));
    stats->att = 19;
    stats->def = 5;
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
    player->view = sfView_create();
    player->clock = clk;
    player->time = tm;
    player->stats = setup_stats();
    player->kb_dir = 0;
    player->kb_speed = 0;
    player->percentage = 0;
    return player;
}
