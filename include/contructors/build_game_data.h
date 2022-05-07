/*
** EPITECH PROJECT, 2022
** build_game_data
** File description:
** Header
*/

#ifndef BUILD_GAME_DATA_H_
    #define BUILD_GAME_DATA_H_
    #include "structures.h"
    #include <stdlib.h>

player_t *player_constructor(void);
keys_t *build_keys(void);
scene_t **get_scene_list(void);
char **get_names_scene(scene_t **scene_list);
int get_run_index(char **scene_names, char *name);
#endif /* !BUILD_GAME_DATA_H_ */
