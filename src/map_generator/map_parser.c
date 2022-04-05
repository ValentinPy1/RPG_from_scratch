/*
** EPITECH PROJECT, 2022
** map_parser.c
** File description:
** Source code to load a map from a config file
*/

#include "map_parser.h"

int get_nb_row(char **tab)
{
    int row;

    for (row = 0; tab[row] != NULL; row ++);
    return (row);
}

int **malloc_int(int width, int height)
{
    int **map_int = malloc(height * sizeof(int *));
    int rows;

    for (rows = 0; rows < height; rows++)
        map_int[rows] = malloc(width * sizeof(int));
    return (map_int);
}

int **tiles_parser(map_t *map_data)
{
    int line;
    int number;
    char **map = get_content_file("config_files/map_config/map.config");
    int width = count_char(map[0], ',') + 1;
    int height = get_nb_row(map);
    int **tiles = malloc_int(width, height);
    char **temp;

    for (line = 0; map[line] != NULL; line++) {
        temp = my_split(map[line], ',');
        for (number = 0; temp[number] != NULL; number++) {
            tiles[line][number] = my_getnbr(temp[number]);
        }
        free(temp);
    }
    return (tiles);
}

sfIntRect fill_int_rect(int left, int top, int width, int height)
{
    sfIntRect rect;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

map_t *map_constructor(void)
{
    map_t *map_data = malloc(sizeof(map_t));
    sfTexture *tile_texture = sfTexture_createFromFile(
                                "img/map/map_ss.png", NULL);
    sfSprite *tile_sprite = sfSprite_create();

    sfSprite_setTexture(tile_sprite, tile_texture, sfFalse);
    map_data->tiles_sprite = tile_sprite;
    map_data->tiles = tiles_parser(map_data);
    return (map_data);
}

void display_map(sfRenderWindow *window, map_t *map_data)
{
    sfIntRect limit = fill_int_rect(0, 0, 32, 32);
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 34; i++) {
        for (int j = 0; j < 60; j++) {
            limit.left = map_data->tiles[i][j] * 32;
            pos.x = j * 32;
            pos.y = i * 32;
            sfSprite_setPosition(map_data->tiles_sprite, pos);
            sfSprite_setTextureRect(map_data->tiles_sprite, limit);
            sfRenderWindow_drawSprite(window, map_data->tiles_sprite, NULL);
        }
    }
}
