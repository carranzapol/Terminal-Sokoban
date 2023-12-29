/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** game_logic
*/

#include "../include/my.h"

sokoban_game_t handle_gameplay(sokoban_game_t game)
{
    int key_press = 0;

    key_press = getch();
    game = handle_key_movement(game, key_press);
    game = sokoban_map_restart_check(&game);
    sokoban_check_win_condition(&game);
    sokoban_lose_condition_check(game);
    return game;
}

sokoban_game_t display_map(const char *path, sokoban_game_t game)
{
    int pos = 0;
    int col = 0;

    game.buffer = read_map(path, &game);
    game = count_lines(game);
    game.game_map = malloc(sizeof(char *) * game.num_rows);
    game.new_game_map = malloc(sizeof(char *) * game.num_rows);
    for (int y = 0; y < game.num_rows; y++) {
        col = count_columns(&game, pos);
        game.game_map[y] = malloc(sizeof(char *) * (col + 1));
        game.new_game_map[y] = malloc(sizeof(char *) * (col + 1));
        for (int x = 0; x < col; x++) {
            game.game_map[y][x] = game.buffer[pos];
            game.new_game_map[y][x] = game.buffer[pos];
            pos++;
        }
        pos++;
    }
    return (game);
}
