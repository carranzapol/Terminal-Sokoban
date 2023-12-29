/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** movement_key
*/

#include "../include/my.h"

sokoban_game_t handle_key_movement(sokoban_game_t game, int key)
{
    if (key == KEY_UP)
        game = move_player_up(game);
    if (key == KEY_DOWN)
        game = move_player_down(game);
    if (key == KEY_RIGHT)
        game = move_player_right(game);
    if (key == KEY_LEFT)
        game = move_player_left(game);
    return game;
}
