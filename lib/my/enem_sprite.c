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

void change_enemy_sprite(sfClock* clock, sfIntRect* rect, float int_sec)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > int_sec) {
        move_rect(rect, 48, 192);
        sfClock_restart(clock);
    }
}

int check_hit(sfVector2f point, sfSprite *sprite)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);

    return sfFloatRect_contains(&hitbox, point.x, point.y);
}

void move_sprite(sfSprite *sprite, float seconds, float speed, float win_wid)
{
    sfVector2f position = sfSprite_getPosition(sprite);

    position.x += speed * seconds;
    if (position.x > win_wid) {
        position.x = -sfSprite_getGlobalBounds(sprite).width;
    }
    sfSprite_setPosition(sprite, position);
}
