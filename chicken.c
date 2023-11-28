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
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

int show_chicken(sfRenderWindow *window, sfTexture *chicken_texture,
    sfSprite *chicken_sprite, sfClock *clock)
{
    // float ms = sfClock_getElapsedTime(clock).microseconds / 1000;
    sfIntRect rect = { 0, 0, 200, 150 };

    if (!chicken_texture)
        return 84;
    chicken_sprite = sfSprite_create();
    if (sfClock_getElapsedTime(clock).microseconds / 1000.0 > 200) {
        move_rect(&rect, 200, 800);
        my_printf("%d\n", rect.left);
        sfClock_restart(clock);
    }
    chicken_texture = sfTexture_createFromFile("./resources/Chicken.png",
        &rect);
    sfSprite_setTexture(chicken_sprite, chicken_texture, sfTrue);
    sfSprite_setPosition(chicken_sprite, (sfVector2f){ 1000, 500 });
    sfRenderWindow_drawSprite(window, chicken_sprite, NULL);
    return 0;
}

int move_chicken(sfRenderWindow *window, sfTexture *chicken_texture,
    sfSprite *chicken_sprite, sfClock *clock)
{
    // float ms = sfClock_getElapsedTime(clock).microseconds / 1000;
    sfIntRect rect = { 0, 0, 200, 150 };

    if (!chicken_texture)
        return 84;
    chicken_sprite = sfSprite_create();
    if (sfClock_getElapsedTime(clock).microseconds / 1000.0 > 200) {
        move_rect(&rect, 200, 4);
        sfClock_restart(clock);
    }
    chicken_texture = sfTexture_createFromFile("./resources/Chicken.png",
        &rect);
    sfSprite_setTexture(chicken_sprite, chicken_texture, sfTrue);
    // sfSprite_setPosition(chicken_sprite, (sfVector2f){ 1000, 500 });
    sfSprite_move(chicken_sprite, (sfVector2f){ 1, 1 });
    sfRenderWindow_drawSprite(window, chicken_sprite, NULL);
    return 0;
}

void create_chicken(sfRenderWindow *window)
{
    sfTexture* chicken_texture = get_chicken_texture();
    sfSprite* chicken_sprite = sfSprite_create();
    sfClock *clock_animation = sfClock_create();

    show_chicken(window, chicken_texture, chicken_sprite, clock_animation);
}

void chicken_manager(sfRenderWindow *window, sfClock *clock)
{
    // create_chicken(window);
    (void)window;
    (void)clock;
    // my_printf("b\n");

    // create_chicken
    if (sfClock_getElapsedTime(clock).microseconds / 1000.0 > 2000) {
        my_printf("a\n");
        sfClock_restart(clock);
    }
}

void chicken(sfRenderWindow *window, sfClock *clock, sfIntRect *rect,
    sfVector2f chicken_position)
{
    sfTexture* chicken_texture = get_chicken_texture();
    sfSprite* chicken_sprite = sfSprite_create();

    (void)clock;
    chicken_texture = sfTexture_createFromFile("./resources/Chicken.png",
        rect);
    sfSprite_setTexture(chicken_sprite, chicken_texture, sfTrue);
    sfSprite_setPosition(chicken_sprite, chicken_position);
    sfRenderWindow_drawSprite(window, chicken_sprite, NULL);
    if (sfClock_getElapsedTime(clock).microseconds / 1000.0 > 200) {
        move_rect(rect, 200, 800);
        sfClock_restart(clock);
    }
    sfSprite_destroy(chicken_sprite);
    sfTexture_destroy(chicken_texture);
}
