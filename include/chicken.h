/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Chicken Header
*/

#ifndef CHICKEN_H_
    #define CHICKEN_H_

    #include <SFML/Graphics.h>

int show_chicken(sfRenderWindow *window, sfTexture *chicken_texture,
    sfSprite *chicken_sprite, sfClock *clock);
void chicken_manager(sfRenderWindow *window, sfClock *clock);
void chicken(sfRenderWindow *window, sfClock *clock, sfIntRect *rect,
    sfVector2f chicken_position);

#endif /* !CHICKEN_H_ */
