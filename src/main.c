/*
** EPITECH PROJECT, 2022
** main
** File description:
** Source code of the main
*/
#include "main.h"

static void usage(void)
{
    my_putstr("./my_rpg\n");
}

int init_game(int ac, char **av, data_t *game_data);

int my_rpg(int ac, char *av[])
{
    data_t *game_data = malloc(sizeof(data_t));
    int flag = 0;

    if (init_game(ac, av, game_data) == -1)
        flag = 1;
    if (flag == 0) {
        // parse_tile(game_data->scene_list[index]->map);
        // open_window(1920, 1080, game_data);
        button_t *tmp_head = game_data->scene_list[0]->buttons;
        while (tmp_head != NULL) {
            printf("Button name: %s\n", tmp_head->name);
            tmp_head = tmp_head->next;
        }
        entity_t *tmp_head2 = game_data->scene_list[0]->entities;
        while (tmp_head2 != NULL) {
            printf("entity name: %s\n", tmp_head2->name);
            tmp_head2 = tmp_head2->next;
        }
    }
    free_data(game_data);
}

int main(int ac, char *av[])
{   
    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        usage();
        return (0);
    }
    my_rpg(ac, av);
    
    return (0);
}
