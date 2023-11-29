/*
** EPITECH PROJECT, 2023
** Bootstrap MyHunter
** File description:
** Background
*/

#include "my.h"
#include "my_printf.h"
#include "background.h"
#include "chicken.h"
#include "utils.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

static void background_create_textures(background_t *background)
{
    sfSprite_setTexture(background->menu_sprite,
        background->menu_texture, sfTrue);
    sfSprite_setTexture(background->game_sprite,
        background->game_texture, sfTrue);
    sfSprite_setTexture(background->gameover_sprite,
        background->gameover_texture, sfTrue);
}

background_t *background_create(sfRenderWindow *window)
{
    background_t *background = malloc(sizeof(background_t));

    background->window = window;
    background->state = 1;
    background->menu_texture =
        sfTexture_createFromFile("./resources/Menu.png",
        &(sfIntRect){ 0, 0, 1920, 1080 });
    background->game_texture =
        sfTexture_createFromFile("./resources/Background.png",
        &(sfIntRect){ 0, 0, 1920, 1080 });
    background->gameover_texture =
        sfTexture_createFromFile("./resources/Gameover.png",
        &(sfIntRect){ 0, 0, 1920, 1080 });
    background->menu_sprite = sfSprite_create();
    background->game_sprite = sfSprite_create();
    background->gameover_sprite = sfSprite_create();
    background_create_textures(background);
    return background;
}

void background_update(background_t *background)
{
    if (background->state == 1) {
        sfRenderWindow_drawSprite(background->window,
            background->menu_sprite, NULL);
    }
    if (background->state == 2) {
        sfRenderWindow_drawSprite(background->window,
            background->game_sprite, NULL);
    }
    if (background->state == 3) {
        sfRenderWindow_drawSprite(background->window,
            background->gameover_sprite, NULL);
    }
}

void background_destroy(background_t *background)
{
    sfSprite_destroy(background->menu_sprite);
    sfSprite_destroy(background->game_sprite);
    sfSprite_destroy(background->gameover_sprite);
    sfTexture_destroy(background->menu_texture);
    sfTexture_destroy(background->game_texture);
    sfTexture_destroy(background->gameover_texture);
    free(background);
}
