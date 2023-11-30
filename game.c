/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Game File
*/

#include "my.h"
#include "my_printf.h"
#include "myhunter.h"
#include "utils.h"
#include "events.h"
#include "background.h"
#include "chicken.h"
#include "crosshair.h"
#include "framebuffer.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

static void game(sfRenderWindow* window)
{
    background_t *background = background_create(window);
    chicken_t *chicken = chicken_create(window);
    crosshair_t *crosshair = crosshair_create(window);

    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, chicken, background);
        sfRenderWindow_clear(window, sfBlack);
        background_update(background);
        chicken_update(chicken, background);
        crosshair_update(crosshair, background);
        sfRenderWindow_display(window);
    }
    chicken_destroy(chicken);
    crosshair_destroy(crosshair);
    background_destroy(background);
}

int game_instance(int width, int height)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow* window;

    window = sfRenderWindow_create(mode, "Chicken Hunter",
        sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    change_icon(window);
    game(window);
    sfRenderWindow_destroy(window);
    return 0;
}
