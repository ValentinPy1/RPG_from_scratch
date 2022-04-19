/*
** EPITECH PROJECT, 2022
** parse_image
** File description:
** Source code to construct a image
*/

#include "construct_image.h"

int get_nb_images(char **content, int images)
{
    int counter = 0;

    for (images = images; content[images] != NULL
        && nb_char_in_str(content[images], '\t') != 1; images++) {
        if (nb_char_in_str(content[images], '\t') == 2)
            counter++;
    }
    return (counter);
}

int assign_image_value(image_t *image, char *keyword,
                        char *value, int index)
{
    if (my_strcmp(IMG_CONS[index].name, keyword) == 1)
        if ((*IMG_CONS[index].func)(image, value) == -1) {
            write_error("Error while loading images\n");
            return (-1);
        }
    return (0);
}

int get_image_value(image_t *image, char **content, int line)
{
    char *keyword;
    char *value;

    keyword = get_keyword(content[line]);
    value = get_value(content[line]);
    for (int index = 0; IMG_CONS[index].name != NULL; index++) {
        if (assign_image_value(image, keyword, value, index) == -1)
            return (-1);
    }
    free(keyword);
    free(value);
    return (0);
}

void create_image(image_t *image, char **content, int line)
{
    for (line += 1; nb_char_in_str(content[line], '\t') == 3; line++) {
        if (get_image_value(image, content, line) == -1)
            image = NULL;
    }
}

void construct_image(scene_t *scene, char **content, int index)
{
    int images = index + 1;
    int image_index = 0;
    int nb_images = get_nb_images(content, images);
    image_t **list_image = malloc((nb_images + 1) * sizeof(image_t));

    for (images = images; content[images] != NULL
        && nb_char_in_str(content[images], '\t') != 1; images++) {
        if (nb_char_in_str(content[images], '\t') == 2) {
            list_image[image_index] = malloc(sizeof(image_t));
            create_image(list_image[image_index], content, images);
            image_index++;
        }
    }
    list_image[image_index] = NULL;
    scene->images = list_image;
    return;
}
