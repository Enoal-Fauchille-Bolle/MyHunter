/*
** EPITECH PROJECT, 2023
** Bootstrap MyHunter
** File description:
** Sprite Utilities
*/

#include "my.h"
#include "my_printf.h"
#include "sprites.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

sfTexture *get_bg_texture(void)
{
    return sfTexture_createFromFile("./resources/Background.png",
        &(sfIntRect){ 0, 0, 1920, 1080 });
}

sfTexture *get_chicken_texture(void)
{
    return sfTexture_createFromFile("./resources/Chicken.png",
    // return sfTexture_createFromFile("./resources/ChickenTest.png",
        &(sfIntRect){ 0, 0, 800, 150 });
}

int show_background(sfRenderWindow *window, sfTexture *bg_texture,
    sfSprite *bg_sprite)
{
    if (!bg_texture)
        return 84;
    bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg_sprite, bg_texture, sfTrue);
    sfRenderWindow_drawSprite(window, bg_sprite, NULL);
    return 0;
}
