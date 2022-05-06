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

void display_hitbox(sfRenderWindow *window, hitbox_t *hitbox)
{
    sfRenderWindow_drawRectangleShape(window, hitbox->rectangle, sfFalse);
    for (int index = 0; hitbox->circle[index] != NULL; index++) {
        sfRenderWindow_drawCircleShape(window, hitbox->circle[index], sfFalse);
    }
}

void draw_buttons(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    button_t *head_ref_but = scene->buttons;

    while (head_ref_but != NULL) {
        if (head_ref_but->is_hovered == 0) {
            sfRenderWindow_drawSprite(window,
                head_ref_but->sprite, NULL);
        } else if (head_ref_but->is_hovered == 1) {
            sfRenderWindow_drawSprite(window,
                head_ref_but->ho_sprite, NULL);
        }
        if (game_data->debug_mode == 1)
            display_hitbox(window, head_ref_but->hitbox);
        head_ref_but = head_ref_but->next;
    }
}

void draw_images(sfRenderWindow *window, scene_t *scene)
{
    image_t *head_ref_img = scene->images;

    while (head_ref_img != NULL) {
        sfRenderWindow_drawSprite(window, head_ref_img->sprite, NULL);
        head_ref_img = head_ref_img->next;
    }
}

void draw_texts(sfRenderWindow *window, scene_t *scene) {
    
    text_t *head_ref_txt = scene->texts;

    while (head_ref_txt != NULL) {
        sfRenderWindow_drawText(window, head_ref_txt->text, NULL);
        head_ref_txt = head_ref_txt->next;
    }
}

void display_scene(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    if (scene->background_sprite != NULL)
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
    else if (scene->map != NULL) {
        init_view(window, game_data);
        sfSprite_setTextureRect(game_data->red->player_sprite,
        *game_data->red->player_rect);
        sfRenderWindow_drawSprite(window, game_data->red->player_sprite, NULL);
        spawn_enem(game_data);
        update_enemies(game_data, game_data->enemies);
        draw_enemies(window, game_data->enemies);
        handle_particles(window, game_data, scene);
    }
    draw_images(window, scene);
    draw_texts(window, scene);
    draw_buttons(window, game_data, scene);
}
