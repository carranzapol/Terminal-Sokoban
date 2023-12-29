/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** lose_condition
*/

#include "../include/my.h"

void sokoban_lose_condition(int row, int col, sokoban_game_t game)
{
    if (game.game_map[row][col] == 'X') {
        if (((game.game_map[row][col + 1] == '#' &&
        game.game_map[row + 1][col] == '#') ||
            (game.game_map[row][col - 1] == '#' &&
            game.game_map[row - 1][col] == '#') ||
            (game.game_map[row + 1][col] == '#' &&
            game.game_map[row][col - 1] == '#') ||
            (game.game_map[row - 1][col] == '#' &&
            game.game_map[row][col + 1] == '#')) &&
            game.new_game_map[row][col] != 'O') {
                endwin();
                exit(1);
            }
    }
}

void sokoban_lose_condition_check(sokoban_game_t game)
{
    for (int col = 0; col < game.num_rows; col++) {
        for (int rows = 0; game.new_game_map[col][rows] != '\0'; rows++) {
            sokoban_lose_condition(col, rows, game);
        }
    }
}
