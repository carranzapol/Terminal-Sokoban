/*
** EPITECH PROJECT, 2023
** unix_system
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        print_help();
    } else {
        sokoban_gameplay(argv[1]);
    }
    return (0);
}
