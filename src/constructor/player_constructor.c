/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** player_constructor.c
*/

#include "structures.h"
#include <stdlib.h>

void set_position(sfSprite *sprite, float x, float y)
{
    sfVector2f position = {x, y};

    sfSprite_setPosition(sprite, position);
}

sfIntRect *set_player_rect(void)
{
    sfIntRect *rectangle = malloc(sizeof(sfIntRect));
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = 16;
    rectangle->height = 16;
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
    stats->att = 5;
    stats->def = 5;
    stats->spd = 2;
    return stats;
}

player_t *player_constructor(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfClock *clk = sfClock_create();
    sfTime tm;

    player->pos.x = 13 * 32;
    player->pos.y = 9 * 32;
    player->player_sprite =
    create_sprite("assets/img/player/player_ss.png", 2, 2);
    player->player_rect = set_player_rect();
    player->view = sfView_create();
    player->clock = clk;
    player->time = tm;
    player->stats = setup_stats();
    player->kb_dir = 0;
    player->kb_speed = 0;
    return player;
}
