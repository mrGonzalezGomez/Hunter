/*
** EPITECH PROJECT, 2023
** My hunter
** File description:
** BS of my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdio.h>
#include <string.h>

void display_description(void)
{
    my_putstr("Welcome to a DOOM version of My Hunter!\n");
    my_putstr("OBJECTIVE:\n");
    my_putstr("Kill all the demons and have fun!\n");
    my_putstr("INSTRUCTIONS:\n");
    my_putstr("Left click to shoot your regular gun\n");
    my_putstr("ADVICE:\n");
    my_putstr("Enemies will be going progressively faster\n");
}
