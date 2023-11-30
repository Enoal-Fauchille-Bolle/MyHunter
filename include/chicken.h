/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Chicken Header
*/

#ifndef CHICKEN_H_
    #define CHICKEN_H_

    #include <SFML/Graphics.h>
    #include "background.h"

typedef struct chicken_s {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock_animation;
    sfClock *clock_movement;
    sfClock *clock_speed;
    sfClock *clock_gameover;
    sfIntRect rect;
    sfVector2f position;
    int direction; // 1: left, 2: right
    float speed;
    sfText *text_score;
    sfFont *font;
    int score;
} chicken_t;

chicken_t *chicken_create(sfRenderWindow *window);
void chicken_spawn(chicken_t *chicken);
void chicken_update(chicken_t *chicken, background_t *background);
void chicken_destroy(chicken_t *chicken);

#endif /* !CHICKEN_H_ */
