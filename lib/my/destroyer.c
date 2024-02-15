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

void destroy(GameData *gameData)
{
    if (gameData->music) {
        sfMusic_stop(gameData->music);
        sfMusic_destroy(gameData->music);
    }
    sfTexture_destroy(gameData->tex_d2);
    sfTexture_destroy(gameData->tex_men);
    sfSprite_destroy(gameData->spr_d2);
    sfSprite_destroy(gameData->spr_men);
    sfTexture_destroy(gameData->tex_d1);
    sfSprite_destroy(gameData->spr_d1);
    sfRenderWindow_destroy(gameData->win);
    sfClock_destroy(gameData->clock);
}
