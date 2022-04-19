/*
** EPITECH PROJECT, 2022
** map_collision
** File description:
** SOurce code of the collision of the map
*/
#include "map_collision.h"

int parse_tile(map_t *map)
{
    for (int row = 0; row < map->size_y; row++) {
        for (int col = 0; col < map->size_x; col++) {
            printf("TILE:%i\t", map->tiles[row][col]);
            printf("at (x:%i, y:%i)\n", row * 32, col * 32);
        }
    }
}