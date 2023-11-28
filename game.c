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
    sfClock *chicken_clock = sfClock_create();
    sfIntRect rect = { 0, 0, 200, 150 };
    sfVector2f chicken_position = { 0, 0 };

    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window);
        sfRenderWindow_clear(window, sfBlack);
        show_background(window, bg_texture, bg_sprite);
        chicken(window, chicken_clock, &rect, chicken_position);
        crosshair(window);
        // chicken_position.x += 5;
        // chicken_position.y += 5;
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(bg_sprite);
    sfTexture_destroy(bg_texture);
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
