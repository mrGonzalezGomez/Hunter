/*
** EPITECH PROJECT, 2023
** Day09
** File description:
** My h
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    sfTexture* tex_d2;
    sfSprite* spr_d2;
    sfTexture* tex_d1;
    sfSprite* spr_d1;
    sfTexture* tex_men;
    sfSprite* spr_men;
    sfClock* clock;
    sfRenderWindow* win;
    sfIntRect rect;
    sfClock* ani_cloc;
    sfMusic* music;
} GameData;

typedef struct {
    float speed;
    float win_wid;
    float sII;
    float sI;
    float int_sec;
} GameParameters;

typedef struct {
    float bS;
    float sII;
    float sI;
    float int_sec;
} Loop;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void manage_mouse_click(sfMouseButtonEvent event);
void move_rect(sfIntRect *rect, int max_width, int max_value);
void analyse_events(sfRenderWindow *window, sfEvent event);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
void display_description(void);
void init(GameData *gameData);
void destroy(GameData *gameData);
void change_enemy_sprite(sfClock* clock, sfIntRect* rect, float int_sec);
int check_hit(sfVector2f point, sfSprite *sprite);
void move_sprite(sfSprite *sprite, float seconds, float speed, float win_wid);
