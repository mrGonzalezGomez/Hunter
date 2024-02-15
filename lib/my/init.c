/*
** EPITECH PROJECT, 2023
** My hunter
** File description:
** BS of my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

void create_textures(GameData *gameData)
{
    gameData->tex_d2 = sfTexture_createFromFile("PT/enemy2.png", NULL);
    gameData->tex_d1 = sfTexture_createFromFile("PT/enemy1.png", NULL);
    gameData->tex_men = sfTexture_createFromFile("PT/game.jpg", NULL);
}

void create_sprites(GameData *gameData)
{
    gameData->spr_d2 = sfSprite_create();
    sfSprite_setTexture(gameData->spr_d2, gameData->tex_d2, sfTrue);
    gameData->spr_d1 = sfSprite_create();
    sfSprite_setTexture(gameData->spr_d1, gameData->tex_d1, sfTrue);
    gameData->spr_men = sfSprite_create();
    sfSprite_setTexture(gameData->spr_men, gameData->tex_men, sfTrue);
}

void initialize_values(GameData *gameData)
{
    sfVideoMode videoMode = {1920, 725, 32};
    sfVector2f scale = {2.0f, 2.0f};
    sfVector2f initialPosition = {-200.0f, 0.0f};
    sfVector2f initialPositionEnemy1 = {1900.0f, 480.0f};

    gameData->clock = sfClock_create();
    gameData->win = sfRenderWindow_create(videoMode, "DOOM", sfClose, NULL);
    gameData->rect = (sfIntRect){0, 0, 120, 210};
    sfSprite_setScale(gameData->spr_d1, scale);
    sfSprite_setPosition(gameData->spr_d2, initialPosition);
    sfSprite_setPosition(gameData->spr_d1, initialPositionEnemy1);
}

void init(GameData *gameData)
{
    create_textures(gameData);
    create_sprites(gameData);
    initialize_values(gameData);
    gameData->music = sfMusic_createFromFile("PT/doomusic.ogg");
}
