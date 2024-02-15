/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** My put nbr
*/

#include <unistd.h>
#include "my.h"
#include <limits.h>
#include <stdio.h>

int put_my_nbr(long int nb)
{
    if (nb > INT_MAX || nb < INT_MIN){
        nb = 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        put_my_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return nb;
}

int my_put_nbr(int nb)
{
    put_my_nbr(nb);
    return nb;
}
