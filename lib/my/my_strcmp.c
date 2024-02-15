/*
** EPITECH PROJECT, 2023
** task06
** File description:
** compare
*/

#include <stdio.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && i < my_strlen(s1); i++);
    if (i == my_strlen(s1) && i == my_strlen(s2)){
        return 0;
    }
    return (s1[i] - s2[i]);
}
