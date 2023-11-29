/*
** EPITECH PROJECT, 2023
** Bootstrap MyHunter
** File description:
** Crosshair
*/

#include "my.h"
#include "my_printf.h"
#include "crosshair.h"
#include "background.h"
#include "utils.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

crosshair_t *crosshair_create(sfRenderWindow *window)
{
    crosshair_t *crosshair = malloc(sizeof(crosshair_t));

    crosshair->window = window;
    crosshair->texture = sfTexture_createFromFile("./resources/Crosshair.png",
        NULL);
    crosshair->sprite = sfSprite_create();
    return crosshair;
}

void crosshair_update(crosshair_t *crosshair, background_t *background)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(crosshair->window);

    if (background->state != 2) {
        sfRenderWindow_setMouseCursorVisible(background->window, sfTrue);
        return;
    }
    sfRenderWindow_setMouseCursorVisible(background->window, sfFalse);
    sfSprite_setTexture(crosshair->sprite, crosshair->texture, sfTrue);
    sfSprite_setPosition(crosshair->sprite, (sfVector2f){ position.x - 33,
        position.y - 33 });
    sfRenderWindow_drawSprite(crosshair->window, crosshair->sprite, NULL);
}

void crosshair_destroy(crosshair_t *crosshair)
{
    sfSprite_destroy(crosshair->sprite);
    sfTexture_destroy(crosshair->texture);
    free(crosshair);
}
