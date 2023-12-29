/*
** EPITECH PROJECT, 2023
** B-PSU-100-BAR-1-1-sokoban-pol.carranza-lavado
** File description:
** loadmap2
*/

#include "../include/my.h"

char *allocate_buffer(const char *path, sokoban_game_t *game)
{
    struct stat sb;

    game->file_descriptor = open(path, O_RDONLY);
    if (game->file_descriptor == -1)
        exit(84);
    stat(path, &sb);
    game->buffer = malloc(sb.st_size + 1);
    if (game->buffer == NULL)
        exit(84);
    return (game->buffer);
}

void read_file_content(sokoban_game_t *game)
{
    struct stat sb;

    game->read_descriptor = read(game->file_descriptor,
    game->buffer, sb.st_size);
    game->buffer[game->read_descriptor] = '\0';
}

void check_read_error(sokoban_game_t *game)
{
    if (game->map_size == -1 && game->read_descriptor == -1)
        exit(84);
}

void close_file_descriptor(sokoban_game_t *game)
{
    close(game->file_descriptor);
}

char *read_map(const char *path, sokoban_game_t *game)
{
    allocate_buffer(path, game);
    read_file_content(game);
    check_read_error(game);
    close_file_descriptor(game);
    return (game->buffer);
}
