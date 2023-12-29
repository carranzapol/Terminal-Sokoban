/*
** EPITECH PROJECT, 2023
** B-PSU-100-BAR-1-1-sokoban-pol.carranza-lavado
** File description:
** print_help
*/

#include "../include/my.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("map file representing the warehouse map, containing '#'\n");
    my_putstr("for walls, 'P' for the player, 'X' for boxes and 'O' for\n");
    my_putstr("storage locations.\n");
}
