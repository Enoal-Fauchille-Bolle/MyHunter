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
#include "sprites.h"
#include "chicken.h"
#include "crosshair.h"
#include "framebuffer.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

static void game(sfRenderWindow* window)
{
    sfTexture* bg_texture = get_bg_texture();
    sfSprite* bg_sprite = sfSprite_create();
    chicken_t *chicken = chicken_create(window);

    chicken_spawn(chicken);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window);
        sfRenderWindow_clear(window, sfBlack);
        show_background(window, bg_texture, bg_sprite);
        chicken_update(chicken);
        crosshair(window);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(bg_sprite);
    sfTexture_destroy(bg_texture);
    chicken_destroy(chicken);
}

int game_instance(int width, int height)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow* window;

    window = sfRenderWindow_create(mode, "MyHunter", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    change_icon(window);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    game(window);
    sfRenderWindow_destroy(window);
    return 0;
}
