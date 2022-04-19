/*
** EPITECH PROJECT, 2022
** map_collision
** File description:
** SOurce code of the collision of the map
*/
#include "map_collision.h"

int parse_tile(map_t *map)
{
    int row = 0;
    int col = 0;

    for (row = 0; row < map->size_y; row++);
    for (col = 0; col < map->size_x; col++);
    printf("LEN tile[%i][%i]\n", col, row);
}

int is_blocking_tile(map_t *map, sfVector2f pos)
{
    int x = floor(pos.x);
    int y = floor(pos.y);

    if (map == NULL || x < 0 || y < 0) // TO DO better error handling
        return (1);
    // printf("P pos:(%i, %i)\n", x, y);
    // parse_tile(map);
    // printf("P relative pos:(%i, %i)\n", x / 32, y / 32);
    // printf("Current tile value:%i\n", map->tiles[y / 32][x / 32]);
    if (map->tiles[y / 32][x / 32] == 7) {
        printf("Lava not good\n");
        return (1);
    } else {
        printf("GOOD\n");
        return (0);
    }
}