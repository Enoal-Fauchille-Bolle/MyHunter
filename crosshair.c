/*
** EPITECH PROJECT, 2023
** Bootstrap MyHunter
** File description:
** Crosshair
*/

#include "my.h"
#include "my_printf.h"
#include "chicken.h"
#include "sprites.h"
#include "utils.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

void crosshair(sfRenderWindow *window)
{
    sfTexture* crosshair_texture = get_chicken_texture();
    sfSprite* crosshair_sprite = sfSprite_create();
    sfVector2i position = sfMouse_getPositionRenderWindow(window);

    crosshair_texture = sfTexture_createFromFile("./resources/Crosshair.png",
        NULL);
    sfSprite_setTexture(crosshair_sprite, crosshair_texture, sfTrue);
    sfSprite_setPosition(crosshair_sprite, (sfVector2f){ position.x - 24,
        position.y - 24 });
    sfRenderWindow_drawSprite(window, crosshair_sprite, NULL);
    sfSprite_destroy(crosshair_sprite);
    sfTexture_destroy(crosshair_texture);
}
