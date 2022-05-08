/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_texts.c
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
    if (gd->frame_count % (int) (gd->framerate * 60.0 /
    (float) gd->red->stats->heal) == 0 && gd->red->percentage > 0) {
        gd->red->percentage -= 1;
    }
    sfText_setColor(percentage, color);
    sfText_setPosition(percentage,
                (sfVector2f) {gd->red->pos.x - 10, gd->red->pos.y + 150});
    sfText_setString(percentage, str_w_per);
    free(str_w_per);
}

void handle_killstreak(data_t *gd, scene_t *scene)
{
    char *str = my_getstr(gd->red->kill_streak);
    sfText *kill_streak = get_text(scene->texts, "kill_streak")->text;
    sfColor color = (sfColor)
    {255 - gd->red->kill_streak * 2.55, 255, 255 - gd->red->kill_streak * 2.55, 255};
    sfText_setColor(kill_streak, color);
    sfText_setString(kill_streak, str);
    free(str);
}

void handle_xp_points(data_t *gd, scene_t *scene)
{
    char *str = my_getstr(gd->red->stats->xp);
    sfText *xp = get_text(scene->texts, "xp_points")->text;
    char *str_w_per = my_strconc("xp: ", str);

    free(str);
    if (gd->red->stats->xp >= 5)
        sfText_setColor(xp, sfGreen);
    else {
        sfText_setColor(xp, sfWhite);
    }
    sfText_setPosition(xp,
    (sfVector2f) {gd->red->pos.x + 240, gd->red->pos.y + 150});
    sfText_setString(xp, str_w_per);
    free(str_w_per);
}