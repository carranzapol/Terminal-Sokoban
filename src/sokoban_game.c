/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** sokoban_game
*/

#include "../include/my.h"

sokoban_game_t sokoban_gameplay(char const *filepath)
{
    sokoban_game_t game = initialize_map(filepath);

    game = find_player_position(game);
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    clear();
    refresh();
    while (1) {
        refresh();
        for (int i = 0; i < game.num_rows; i++)
            mvprintw(i, 0, "%s", game.game_map[i]);
        move(game.player_pos_y, game.player_pos_x);
        game = handle_gameplay(game);
    }
    return (game);
}
