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
void spawn_enem(data_t *gd);

void knife(data_t *game_data)
{
    set_position(game_data->red->attack_sprite,
    game_data->red->pos.x + OFFSET[game_data->red->facing].x,
    game_data->red->pos.y + OFFSET[game_data->red->facing].y);
    if (game_data->red->attack_state != 5) {
        sfRenderWindow_drawSprite(game_data->window,
        game_data->red->attack_sprite, NULL);
    }
    game_data->red->attack_time =
    sfClock_getElapsedTime(game_data->red->attack_clock);
    game_data->red->attack_seconds =
    game_data->red->attack_time.microseconds / 1000000.0;
    if (game_data->red->attack_seconds > 0.10) {
        if (game_data->red->attack_state !=  5) {
            move_rect(game_data->red->attack_rect, 32, 160);
            sfClock_restart(game_data->red->attack_clock);
            game_data->red->attack_state++;
        }
    }
}

static void game_scene(sfRenderWindow *window,
data_t *game_data, scene_t *scene)
{
    player_move(game_data, game_data->scene_list[game_data->run_index]);
    spawn_enem(game_data);
    update_enemies(game_data, game_data->enemies);
    display_map(window, scene->map);
    init_view(window, game_data);
    sfSprite_setTextureRect(game_data->red->player_sprite,
    *game_data->red->player_rect);
    sfRenderWindow_drawSprite(window, game_data->red->player_sprite, NULL);
    sfSprite_setTextureRect(game_data->red->attack_sprite,
    *game_data->red->attack_rect);
    handle_particles(window, game_data, scene);
    draw_enemies(window, game_data->enemies);
    knife(game_data);
}

void display_scene(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    if (scene->background_sprite != NULL) {
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
        update_stats(game_data);
    } else if (scene->map != NULL) {
        game_scene(window, game_data, scene);
    }
    draw_images(window, scene);
    draw_texts(window, game_data, scene);
    draw_buttons(window, game_data, scene);
}