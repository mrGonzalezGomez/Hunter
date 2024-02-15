/*
** EPITECH PROJECT, 2023
** My hunter
** File description:
** Clicks
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "my.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    if (event.button == sfMouseLeft){
        my_putstr(" Mouse x = ");
        my_put_nbr(event.x);
        my_putstr(" Mouse y = ");
        my_put_nbr(event.y);
        my_putstr(" The left button was pressed\n");
    }
    if (event.button == sfMouseRight){
        my_putstr(" Mouse x = ");
        my_put_nbr(event.x);
        my_putstr(" Mouse y = ");
        my_put_nbr(event.y);
        my_putstr(" The right button was pressed\n");
    }
}
