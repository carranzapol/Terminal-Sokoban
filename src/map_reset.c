/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** map_reset
*/

#include "../include/my.h"

sokoban_game_t sokoban_map_restart(int row, int col,
    sokoban_game_t const *game)
{
    sokoban_game_t updated_game = *game;

    if (updated_game.new_game_map[row][col] == 'O'
    && updated_game.game_map[row][col] == ' ') {
        updated_game.game_map[row][col] = updated_game.new_game_map[row][col];
    }
    return (updated_game);
}

sokoban_game_t sokoban_map_restart_check(sokoban_game_t const *game)
{
    sokoban_game_t updated_game = *game;

    for (int i = 0; i < updated_game.num_rows; i++) {
        for (int j = 0; updated_game.new_game_map[i][j] != '\0'; j++) {
            updated_game = sokoban_map_restart(i, j, &updated_game);
        }
    }
    return (updated_game);
}
