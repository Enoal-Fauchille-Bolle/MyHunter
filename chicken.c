/*
** EPITECH PROJECT, 2023
** Bootstrap MyHunter
** File description:
** Chicken
*/

#include "my.h"
#include "my_printf.h"
#include "chicken.h"
#include "sprites.h"
#include "utils.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

chicken_t *chicken_create(sfRenderWindow *window)
{
    chicken_t *chicken = malloc(sizeof(chicken_t));

    chicken -> window = window;
    chicken -> texture = get_chicken_texture();
    chicken -> sprite = sfSprite_create();
    chicken -> clock = sfClock_create();
    chicken -> rect = (sfIntRect){ 0, 0, 200, 150 };
    chicken -> position = (sfVector2f){ 0, 0 };
    return chicken;
}

void chicken_spawn(chicken_t *chicken)
{
    int y = my_random(1, sfRenderWindow_getSize(chicken->window).y - 150);

    chicken->direction = my_random(1, 2);
    if (chicken->direction == 2) {
        chicken->position = (sfVector2f)
            { sfRenderWindow_getSize(chicken->window).x, y };
    } else {
        chicken->position = (sfVector2f){ -200, y };
    }
}

void chicken_update(chicken_t *chicken)
{
    chicken->texture = sfTexture_createFromFile("./resources/Chicken.png",
        &chicken->rect);
    sfSprite_setTexture(chicken->sprite, chicken->texture, sfTrue);
    sfSprite_setPosition(chicken->sprite, chicken->position);
    sfRenderWindow_drawSprite(chicken->window, chicken->sprite, NULL);
    if (sfClock_getElapsedTime(chicken->clock).microseconds / 1000.0 > 200) {
        move_rect(&chicken->rect, 200, 800);
        sfClock_restart(chicken->clock);
    }
    if (chicken->direction == 1) {
        chicken->position.x += 5;
    } else {
        chicken->position.x -= 5;
    }
}

void chicken_destroy(chicken_t *chicken)
{
    sfSprite_destroy(chicken->sprite);
    sfTexture_destroy(chicken->texture);
    free(chicken);
}
