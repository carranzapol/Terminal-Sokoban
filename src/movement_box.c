/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** movement_box
*/

#include "../include/my.h"

sokoban_game_t move_box_up(sokoban_game_t game)
{
    if (game.game_map[game.player_pos_y - 2][game.player_pos_x] == 'X')
        return game;
    else if (game.game_map[game.player_pos_y - 2][game.player_pos_x] == '#')
        return game;
    else {
        game.game_map[game.player_pos_y - 2][game.player_pos_x] = 'X';
        game.game_map[game.player_pos_y - 1][game.player_pos_x] = 'P';
        game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
        game.player_pos_y--;
    }
    return game;
}

sokoban_game_t move_box_down(sokoban_game_t game)
{
    if (game.game_map[game.player_pos_y + 2][game.player_pos_x] == 'X')
        return game;
    else if (game.game_map[game.player_pos_y + 2][game.player_pos_x] == '#')
        return game;
    else {
        game.game_map[game.player_pos_y + 2][game.player_pos_x] = 'X';
        game.game_map[game.player_pos_y + 1][game.player_pos_x] = 'P';
        game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
        game.player_pos_y++;
    }
    return game;
}

sokoban_game_t move_box_left(sokoban_game_t game)
{
    if (game.game_map[game.player_pos_y][game.player_pos_x - 2] == 'X')
        return game;
    else if (game.game_map[game.player_pos_y][game.player_pos_x - 2] == '#')
        return game;
    else {
        game.game_map[game.player_pos_y][game.player_pos_x - 1] = 'P';
        game.game_map[game.player_pos_y][game.player_pos_x - 2] = 'X';
        game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
        game.player_pos_x--;
    }
    return game;
}

sokoban_game_t move_box_right(sokoban_game_t game)
{
    if (game.game_map[game.player_pos_y][game.player_pos_x + 2] == 'X')
        return game;
    else if (game.game_map[game.player_pos_y][game.player_pos_x + 2] == '#')
        return game;
    else {
        game.game_map[game.player_pos_y][game.player_pos_x + 2] = 'X';
        game.game_map[game.player_pos_y][game.player_pos_x + 1] = 'P';
        game.game_map[game.player_pos_y][game.player_pos_x] = ' ';
        game.player_pos_x++;
    }
    return game;
}
