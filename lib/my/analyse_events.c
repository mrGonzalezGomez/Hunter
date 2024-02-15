/*
** EPITECH PROJECT, 2023
** My hunter
** File description:
** BS of my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include <stdio.h>

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
