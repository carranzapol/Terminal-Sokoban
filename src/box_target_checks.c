/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** box_target_checks
*/

#include "../include/my.h"

int sokoban_is_box_on_target(int y, int x, sokoban_game_t game)
{
    return (game.game_map[y][x] == 'X' && game.new_game_map[y][x] == 'O');
}

int sokoban_is_box_not_on_target(int y, int x, sokoban_game_t game)
{
    return (game.game_map[y][x] == 'X' && game.new_game_map[y][x] != 'O');
}
