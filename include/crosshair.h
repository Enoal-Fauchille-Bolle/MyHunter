/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Chicken Header
*/

#ifndef CROSSHAIR_H_
    #define CROSSHAIR_H_

    #include <SFML/Graphics.h>
    #include "background.h"

typedef struct crosshair_s {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
} crosshair_t;

crosshair_t *crosshair_create(sfRenderWindow *window);
void crosshair_update(crosshair_t *crosshair, background_t *background);
void crosshair_destroy(crosshair_t *crosshair);

#endif /* !CROSSHAIR_H_ */
