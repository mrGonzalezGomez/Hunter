/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** My putchar
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
