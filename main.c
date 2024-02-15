/*
** EPITECH PROJECT, 2023
** My hunter
** File description:
** BS of my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_mouse_events(sfEvent event, GameData *gameData)
{
    sfVector2f mousePos = { event.mouseButton.x, event.mouseButton.y };
    sfVector2f farLeftPosition;
    sfVector2f farRightPosition1;

    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) {
        if (check_hit(mousePos, gameData->spr_d2)) {
            farLeftPosition.x = -200.0f;
            farLeftPosition.y = 0.0f;
            sfSprite_setPosition(gameData->spr_d2, farLeftPosition);
        }
        if (check_hit(mousePos, gameData->spr_d1)) {
            farRightPosition1.x = 1900.0f;
            farRightPosition1.y = 480.0f;
            sfSprite_setPosition(gameData->spr_d1, farRightPosition1);
        }
    }
}

static void poll_events(GameData *gameData)
{
    sfEvent event;
    sfVector2f d1Pos;
    sfVector2f fp1;

    while (sfRenderWindow_pollEvent(gameData->win, &event)) {
        analyse_events(gameData->win, event);
        d1Pos = sfSprite_getPosition(gameData->spr_d1);
        if (d1Pos.x < -sfSprite_getGlobalBounds(gameData->spr_d1).width) {
            fp1.x = sfRenderWindow_getSize(gameData->win).x;
            fp1.y = 480.0f;
            sfSprite_setPosition(gameData->spr_d1, fp1);
        }
        handle_mouse_events(event, gameData);
    }
}

void move_enemies(GameData *gD, float seconds, float speed, float win_wid)
{
    move_sprite(gD->spr_d2, seconds, speed, win_wid);
    move_sprite(gD->spr_d1, seconds, -speed, win_wid);
}

static void update_enemy_behavior(sfClock* eC, GameData *gD, float int_sec)
{
    sfTime time = sfClock_getElapsedTime(eC);
    float seconds = sfTime_asSeconds(time);

    if (seconds > int_sec) {
        change_enemy_sprite(eC, &gD->rect, int_sec);
        sfClock_restart(eC);
    }
}

void update_game(GameData *gD, sfClock* sC, sfClock* eC, GameParameters params)
{
    sfTime time = sfClock_getElapsedTime(gD->clock);
    float seconds = sfTime_asSeconds(time);
    sfTime speedTime = sfClock_getElapsedTime(sC);
    float speedSeconds = sfTime_asSeconds(speedTime);

    move_enemies(gD, seconds, params.speed, params.win_wid);
    update_enemy_behavior(eC, gD, params.int_sec);
    if (speedSeconds > params.sII) {
        params.speed += params.sI;
        sfClock_restart(sC);
    }
}

static void render(GameData *gameData)
{
    sfRenderWindow_clear(gameData->win, sfRed);
    sfRenderWindow_drawSprite(gameData->win, gameData->spr_men, NULL);
    gameData->rect.width = 48;
    sfSprite_setTextureRect(gameData->spr_d1, gameData->rect);
    gameData->rect.width = 120;
    sfRenderWindow_drawSprite(gameData->win, gameData->spr_d2, NULL);
    sfRenderWindow_drawSprite(gameData->win, gameData->spr_d1, NULL);
    sfRenderWindow_display(gameData->win);
}

static void handle_gl(GameData *gD, sfClock* sC, sfClock* eC, Loop lop)
{
    GameParameters params = {
        lop.bS,
        (float)sfRenderWindow_getSize(gD->win).x,
        lop.sII,
        lop.sI,
        lop.int_sec
    };

    update_game(gD, sC, eC, params);
    poll_events(gD);
    render(gD);
}

static void gameloop(GameData *gD, Loop loopParams)
{
    sfClock* sC = sfClock_create();
    sfClock* eC = sfClock_create();

    if (gD->music) {
        sfMusic_play(gD->music);
        sfMusic_setLoop(gD->music, sfTrue);
    }
    while (sfRenderWindow_isOpen(gD->win)) {
        handle_gl(gD, sC, eC, loopParams);
    }
    sfClock_destroy(sC);
    sfClock_destroy(eC);
}

int main(int argc, char *argv[])
{
    float bS = 0.005f;
    float sII = 70.0f;
    float sI = 0.00001f;
    float int_sec = 0.5f;
    GameData *gD = malloc(sizeof(GameData));
    Loop loopParams = { bS, sII, sI, int_sec };

    argc = argc;
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        display_description();
        return 0;
    }
    init(gD);
    gameloop(gD, loopParams);
    destroy(gD);
    free(gD);
    return 0;
}
