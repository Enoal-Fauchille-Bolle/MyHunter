/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Events Utilities
*/

#include "my.h"
#include "my_printf.h"
#include "events.h"
#include "chicken.h"
#include <SFML/Graphics/RenderWindow.h>

static void chicken_click(sfMouseButtonEvent event, chicken_t *chicken)
{
    if (chicken->direction == 1) {
        if (chicken->position.x + 25.0 < event.x &&
            event.x < chicken->position.x + 175.0 &&
            chicken->position.y < event.y &&
            event.y < chicken->position.y + 150.0) {
            chicken_spawn(chicken);
            chicken->score += 1;
        }
    } else {
        if (chicken->position.x - 175.0 < event.x &&
            event.x < chicken->position.x - 25.0 &&
            chicken->position.y < event.y &&
            event.y < chicken->position.y + 150.0) {
            chicken_spawn(chicken);
            chicken->score += 1;
        }
    }
}

static void manage_mouse_click(sfMouseButtonEvent event, chicken_t *chicken,
    background_t *background)
{
    if (event.button != sfMouseLeft)
        return;
    if (background->state == 1) {
        background->state = 2;
        chicken_spawn(chicken);
    }
    if (background->state == 2) {
        chicken_click(event, chicken);
    }
    if (background->state == 3 &&
        sfClock_getElapsedTime(chicken->clock_gameover).microseconds /
        1000.0 > 1000) {
        background->state = 1;
    }
}

static void manage_keys(sfKeyEvent event, background_t *background)
{
    if (event.code != sfKeyEscape)
        return;
    if (background->state == 1) {
        sfRenderWindow_close(background->window);
    }
    if (background->state == 2) {
        background->state = 1;
    }
}

void analyse_events(sfRenderWindow *window, chicken_t *chicken,
    background_t *background)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_click(event.mouseButton, chicken, background);
        if (event.type == sfEvtKeyPressed)
            manage_keys(event.key, background);
    }
}
