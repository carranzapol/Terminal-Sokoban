/*
** EPITECH PROJECT, 2023
** B-PSU-100-BAR-1-1-sokoban-pol.carranza-lavado
** File description:
** loadmap
*/

#include "../include/my.h"

int count_columns(const sokoban_game_t *game, int pos)
{
    const char *row = game->buffer + pos;
    int col = 0;

    while (*row != '\0' && *row != '\n') {
        col++;
        row++;
    }
    return (col);
}

sokoban_game_t count_lines(sokoban_game_t game)
{
    int lines = 0;
    const char *ptr = game.buffer;

    while (*ptr != '\0') {
        if (*ptr == '\n') {
            game.num_rows++;
        }
        ptr++;
    }
    return (game);
}

sokoban_game_t initialize_map(char const *path)
{
    sokoban_game_t game;
    int pos = 0, col;

    game.buffer = read_map(path, &game);
    game = count_lines(game);
    game.game_map = malloc(sizeof(char *) * (game.num_rows + 1));
    game.new_game_map = malloc(sizeof(char *) * (game.num_rows + 1));
    for (int y = 0; y < game.num_rows; y++) {
        col = count_columns(&game, pos);
        game.game_map[y] = malloc(col + 1);
        strncpy(game.game_map[y], &game.buffer[pos], col);
        game.game_map[y][col] = '\0';
        game.new_game_map[y] = my_strdup(game.game_map[y]);
        pos += col + 1;
    }
    game.game_map[game.num_rows] = NULL;
    game.new_game_map[game.num_rows] = NULL;
    return (game);
}
