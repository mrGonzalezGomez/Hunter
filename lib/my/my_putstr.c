/*
** EPITECH PROJECT, 2023
** Task02
** File description:
** Display 1-by-1
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
    return 0;
}
