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
    particle_param_t param = setup_lava_param();
    partic_ll_t *node;

    if (scene->background_to_run == 2)
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
    else if (scene->background_to_run == 1) {
        display_map(window, scene->map);
        init_view(window, game_data);
        sfSprite_setTextureRect(game_data->red->player_sprite, *game_data->red->player_rect);
        sfRenderWindow_drawSprite(window, game_data->red->player_sprite, NULL);
        if (get_rdm() > 0.9) {
            param.pos = (sfVector2f) {get_rdm() * 1920, get_rdm() * 1080};
            node = setup_partic_node(&param);
            add_partic_group(game_data->partic, node);
        }
        update_groups(game_data->partic->next);
        sup_partic_groups(game_data->partic->next);
        draw_groups(window, game_data->partic->next);
    }
    draw_images(window, scene);
    draw_texts(window, game_data, scene);
    draw_buttons(window, game_data, scene);
}
