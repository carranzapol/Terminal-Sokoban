/*
** EPITECH PROJECT, 2023
** B-PSU-100-BAR-1-1-sokoban-pol.carranza-lavado
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int j = 0;
    char *result = malloc(my_strlen(src));

    while (src[j] != '\0') {
        result[j] = src[j];
        j++;
    }
    result[j] = src[j];
    return (result);
}
