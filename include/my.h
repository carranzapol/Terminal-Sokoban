/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <ncurses.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>

typedef struct sokoban_game {
    char **game_map;
    char **new_game_map;
    char *buffer;
    char const *path;
    int num_rows;
    int player_pos_x;
    int player_pos_y;
    int win_condition;
    int read_descriptor;
    int file_descriptor;
    int map_size;
    int storage_counter;
    int box_number;
    int box_counter;
} sokoban_game_t;

void print_help(void);

sokoban_game_t handle_gameplay(sokoban_game_t game);

int count_columns(const sokoban_game_t *game, int pos);
sokoban_game_t count_lines(sokoban_game_t game);
char *read_map(const char *path, sokoban_game_t *game);
sokoban_game_t initialize_map(char const *path);
sokoban_game_t display_map(const char *path, sokoban_game_t game);

sokoban_game_t find_player_position(sokoban_game_t game);
sokoban_game_t check_player_position(sokoban_game_t game, int row, int col);

sokoban_game_t move_player_up(sokoban_game_t game);
sokoban_game_t move_player_down(sokoban_game_t game);
sokoban_game_t move_player_right(sokoban_game_t game);
sokoban_game_t move_player_left(sokoban_game_t game);

sokoban_game_t move_box_up(sokoban_game_t game);
sokoban_game_t move_box_down(sokoban_game_t game);
sokoban_game_t move_box_left(sokoban_game_t game);
sokoban_game_t move_box_right(sokoban_game_t game);

sokoban_game_t handle_key_movement(sokoban_game_t game, int key_press);

sokoban_game_t sokoban_gameplay(char const *filepath);

int sokoban_is_box_on_target(int y, int x, sokoban_game_t game);
int sokoban_is_box_not_on_target(int y, int x, sokoban_game_t game);

int check_row_for_box_not_on_target(int row, sokoban_game_t game);
int all_boxes_on_targets(sokoban_game_t const *game);
void win_condition(int y, int x, sokoban_game_t game);
void sokoban_check_win_condition(sokoban_game_t const *game);

void sokoban_lose_condition(int row, int col, sokoban_game_t game);
void sokoban_lose_condition_check(sokoban_game_t game);

sokoban_game_t sokoban_map_restart(int row, int col,
    sokoban_game_t const *game);
sokoban_game_t sokoban_map_restart_check(sokoban_game_t const *game);

int sokoban_check_map(int row, int col, sokoban_game_t game);
int sokoban_error_handling(sokoban_game_t const *game);

int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strdup(char const *src);

char *allocate_buffer(const char *path, sokoban_game_t *game);
void read_file_content(sokoban_game_t *game);
void check_read_error(sokoban_game_t *game);
void close_file_descriptor(sokoban_game_t *game);
char *read_map(const char *path, sokoban_game_t *game);

#endif
