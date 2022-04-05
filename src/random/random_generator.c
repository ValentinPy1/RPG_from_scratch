/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** random_generator.c
*/

#include "random.h"

double get_rdm(void)
{
    return (double)rand() / (double)RAND_MAX;
}

float rdm_float(float min, float max)
{
    float range = max - min;
    float num = get_rdm();
    num *= range;
    num += min;
    return num;
}
