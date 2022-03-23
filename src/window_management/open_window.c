/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** Source code to open a window in csfml
*/
#include "open_window.h"

void create_window(sfRenderWindow **window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, "MyRpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void event_handling(sfRenderWindow *window, scene_t **scene_list, int index)
{
    sfEvent event;
    sfVector2i mouse_loc;

    mouse_loc = sfMouse_getPositionRenderWindow(window);
    //TO DO EVENT
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased)
            printf("Clic released at: (%i, %i)\n", mouse_loc.x, mouse_loc.y);
    }
}

int scene_selector(sfRenderWindow *window, scene_t **scene_list)
{
    for (int index = 0; scene_list[index] != NULL; index++) {
        if (scene_list[index]->is_running == 1) {
            event_handling(window, scene_list, index);
            display_scene(window, scene_list[index]);
            return (0);
        }
    }
    return (1);
}

void open_window(int width, int height, scene_t **scene_list)
{
    sfRenderWindow *window;

    create_window(&window, width, height);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (scene_selector(window, scene_list) == 1) {
            sfRenderWindow_close(window);
            break;
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
