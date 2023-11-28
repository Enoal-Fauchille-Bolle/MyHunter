/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Utilities
*/

#include "my.h"
#include "utils.h"
#include <stdlib.h>
#include <time.h>

static int power_10(int x)
{
    int result = 1;

    for (int i = 0; i < x; i++) {
        result *= 10;
    }
    return result;
}

int str_to_int(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        if (str[i] > '9' || str[i] < '0')
            return -1;
        result += (str[i] - '0') * power_10(my_strlen(str) - i - 1);
        i++;
    }
    return result;
}

void change_icon(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile("./resources/Icon.png");

    sfRenderWindow_setIcon(window, 432, 432, sfImage_getPixelsPtr(icon));
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

int my_random(int min, int max)
{
    srand(time(NULL));
    return rand() % max + min;
}
