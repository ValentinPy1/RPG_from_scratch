/*
** EPITECH PROJECT, 2022
** display_objects
** File description:
** Source code to display object
*/
#include "structures.h"
#include <stdlib.h>

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
                (sfVector2f) {gd->red->pos.x - 290, gd->red->pos.y + 170});
    sfText_setString(percentage, str_w_per);
    free(str_w_per);
}