/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** error_handling
*/

#include "../include/my.h"

int sokoban_check_map(int row, int col, sokoban_game_t game)
{
    if (game.new_game_map[row][col] != '#'
    && game.new_game_map[row][col] != 'P' &&
        game.new_game_map[row][col] != ' '
        && game.new_game_map[row][col] != 'O' &&
        game.new_game_map[row][col] != '\n' &&
        game.new_game_map[row][col] != '\0')
        exit(84);
    return 0;
}

int sokoban_error_handling(sokoban_game_t const *game)
{
    for (int i = 0; i < game->num_rows; i++) {
        for (int j = 0; game->new_game_map[i][j] != '\0'; j++) {
            sokoban_check_map(i, j, *game);
        }
    }
    return (0);
}
