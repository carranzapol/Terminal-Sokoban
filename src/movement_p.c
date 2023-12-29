/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** player_movement
*/

#include "../include/my.h"

sokoban_game_t move_player_up(sokoban_game_t game)
{
    int new_row = game.player_pos_y - 1;
    int new_col = game.player_pos_x;

    if (game.game_map[new_row][new_col] != '#') {
        if (game.game_map[new_row][new_col] == 'X')
            game = move_box_up(game);
        else {
            game.game_map[new_row][new_col] = 'P';
            game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
            game.player_pos_y = new_row;
        }
    }
    return (game);
}

sokoban_game_t move_player_down(sokoban_game_t game)
{
    int new_row = game.player_pos_y + 1;
    int new_col = game.player_pos_x;

    if (game.game_map[new_row][new_col] != '#') {
        if (game.game_map[new_row][new_col] == 'X')
            game = move_box_down(game);
        else {
            game.game_map[new_row][new_col] = 'P';
            game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
            game.player_pos_y = new_row;
        }
    }
    return (game);
}

sokoban_game_t move_player_right(sokoban_game_t game)
{
    int new_row = game.player_pos_y;
    int new_col = game.player_pos_x + 1;

    if (game.game_map[new_row][new_col] != '#') {
        if (game.game_map[new_row][new_col] == 'X')
            game = move_box_right(game);
        else {
            game.game_map[new_row][new_col] = 'P';
            game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
            game.player_pos_x = new_col;
        }
    }
    return (game);
}

sokoban_game_t move_player_left(sokoban_game_t game)
{
    int new_row = game.player_pos_y;
    int new_col = game.player_pos_x - 1;

    if (game.game_map[new_row][new_col] != '#') {
        if (game.game_map[new_row][new_col] == 'X')
            game = move_box_left(game);
        else {
            game.game_map[new_row][new_col] = 'P';
            game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
            game.player_pos_x = new_col;
        }
    }
    return (game);
}
