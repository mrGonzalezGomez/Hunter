/*
** EPITECH PROJECT, 2023
** My hunter
** File description:
** Movement
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "my.h"

void move_rect(sfIntRect *rect, int max_width, int max_value)
{
    rect->left += max_width;
    if (rect->left >= max_value)
        rect->left = 0;
}
