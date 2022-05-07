/*
** EPITECH PROJECT, 2022
** display_objects
** File description:
** Source code to display object
*/
#include "structures.h"
#include <stdlib.h>

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

void draw_texts(sfRenderWindow *window, scene_t *scene)
{
    text_t *head_ref_txt = scene->texts;

    while (head_ref_txt != NULL) {
        sfRenderWindow_drawText(window, head_ref_txt->text, NULL);
        head_ref_txt = head_ref_txt->next;
    }
}

void handle_percentage(data_t *gd, scene_t *scene)
{
    char *str = my_getstr(gd->red->percentage);
    sfText *percentage = get_text(scene->texts, "percent")->text;
    sfColor color = (sfColor) 
            {255, 255 - gd->red->percentage, 255 - gd->red->percentage, 255};

    char *str_w_per = my_strconc(str, "%");
    free(str);

    if (gd->frame_count % (gd->framerate * REGEN_DELAY) == 0 &&
    gd->red->percentage > 0) {
        gd->red->percentage -= 1;
    }
    sfText_setColor(percentage, color);
    sfText_setPosition(percentage, 
                (sfVector2f) {gd->red->pos.x - 10, gd->red->pos.y + 150});
    sfText_setString(percentage, str_w_per);
    free(str_w_per);
}