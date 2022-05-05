/*
** EPITECH PROJECT, 2021
** manage_display
** File description:
** Source code to manage display
*/
#include "manage_display.h"
#include "particles.h"
#include "random.h"

void init_view(sfRenderWindow *window, data_t *game_data);
void spawn_ennem(data_t *gd);

void display_hitbox(sfRenderWindow *window, hitbox_t *hitbox)
{
    sfRenderWindow_drawRectangleShape(window, hitbox->rectangle, sfFalse);
    for (int index = 0; hitbox->circle[index] != NULL; index++) {
        sfRenderWindow_drawCircleShape(window, hitbox->circle[index], sfFalse);
    }
}

void draw_buttons(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    for (int index = 0; scene->buttons[index] != NULL; index++) {
        if (scene->buttons[index]->is_hovered == 0) {
            sfRenderWindow_drawSprite(window,
                scene->buttons[index]->sprite, NULL);
        } else if (scene->buttons[index]->is_hovered == 1) {
            sfRenderWindow_drawSprite(window,
                scene->buttons[index]->ho_sprite, NULL);
        }
        if (game_data->debug_mode == 1)
            display_hitbox(window, scene->buttons[index]->hitbox);
    }
}

void draw_images(sfRenderWindow *window, scene_t *scene)
{
    for (int index = 0; scene->images[index] != NULL; index++) {
        sfRenderWindow_drawSprite(window, scene->images[index]->sprite, NULL);
    }
}

void draw_texts(sfRenderWindow *window, data_t *game_data, scene_t *scene) {
    for (int index = 0; scene->texts[index] != NULL; index++)
        sfRenderWindow_drawText(window, scene->texts[index], NULL);
}

void display_scene(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    if (scene->background_to_run == 2)
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
    else if (scene->background_to_run == 1) {
        spawn_ennem(game_data);
        update_ennemies(game_data, game_data->ennemies);
        display_map(window, scene->map);
        init_view(window, game_data);
        sfSprite_setTextureRect(game_data->red->player_sprite,
        *game_data->red->player_rect);
        sfRenderWindow_drawSprite(window, game_data->red->player_sprite, NULL);
        handle_particles(window, game_data, scene);
        draw_ennemies(window, game_data->ennemies);
    }
    draw_images(window, scene);
    draw_texts(window, game_data, scene);
    draw_buttons(window, game_data, scene);
}
