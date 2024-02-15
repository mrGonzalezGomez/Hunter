/*
** EPITECH PROJECT, 2023
** Task03
** File description:
** Count-Return
*/

#include <unistd.h>
#include "my.h"

int my_strlen(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++){
        n++;
    }
    return n;
}
