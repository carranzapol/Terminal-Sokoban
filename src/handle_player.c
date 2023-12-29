/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** handle_player
*/

#include "../include/my.h"

sokoban_game_t check_player_position(sokoban_game_t game, int row, int col)
{
    if (game.game_map[row][col] == 'P') {
        game.player_pos_x = col;
        game.player_pos_y = row;
    }
    return game;
}

sokoban_game_t find_player_position(sokoban_game_t game)
{
    for (int row = 0; row < game.num_rows; row++) {
        for (int col = 0; game.game_map[row][col] != '\0'; col++) {
            game = check_player_position(game, row, col);
        }
    }
    return (game);
}
