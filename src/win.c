/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** win_condition
*/

#include "../include/my.h"

int check_row_for_box_not_on_target(int row, sokoban_game_t game)
{
    int j = 0;

    while (game.new_game_map[row][j] != '\0') {
        if (sokoban_is_box_not_on_target(row, j, game)) {
            return 1;
        }
        j++;
    }
    return 0;
}

int all_boxes_on_targets(sokoban_game_t const *game)
{
    int i = 0;

    while (i < game->num_rows) {
        if (check_row_for_box_not_on_target(i, *game)) {
            return 0;
        }
        i++;
    }
    return 1;
}

void win_condition(int y, int x, sokoban_game_t game)
{
    if (sokoban_is_box_on_target(y, x, game) && all_boxes_on_targets(&game)) {
        endwin();
        exit(0);
    }
}

void sokoban_check_win_condition(sokoban_game_t const *game)
{
    int i = 0;
    int j = 0;

    while (i < game->num_rows) {
        while (game->new_game_map[i][j] != '\0') {
            win_condition(i, j, *game);
            j++;
        }
        i++;
    }
}
