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

sfSprite *create_sprite(char const *filepath, float x, float y)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

player_t *player_constructor(void)
{
    player_t *player = malloc(sizeof(player_t));
    
    player->pos.x = 500;
    player->pos.y = 500;
    player->player_sprite = create_sprite("asset/img/RED.png", 0.5, 0.5);
    player->view = sfView_create();
    return player;
}