/*
** EPITECH PROJECT, 2022
** construct_sound
** File description:
** Source code to construct sound
*/
#include "construct_sound.h"

int sound_construct_path(scene_t *scene, char *path)
{
    scene->sound_buffer = sfSoundBuffer_createFromFile(path);
    if (scene->sound_buffer == NULL) {
        write_error("Sound path not found\n");
        return (-1);
    }
    sfSound_setBuffer(scene->music, scene->sound_buffer);
    return (0);
}

int sound_construct_volume(scene_t *scene, char *path)
{
    float volume = my_atof(path);
    
    sfSound_setVolume(scene->music, volume);
    return (0);
}

int sound_construct_pitch(scene_t *scene, char *path)
{
    float pitch = my_atof(path);

    sfSound_setPitch(scene->music, pitch);
    return (0);
}

int sound_construct_loop(scene_t *scene, char *path)
{
    if (my_strcmp(path, "no"))
        sfSound_setLoop(scene->music, sfFalse);
    if (my_strcmp(path, "yes"))
        sfSound_setLoop(scene->music, sfTrue);
    return (0);
}