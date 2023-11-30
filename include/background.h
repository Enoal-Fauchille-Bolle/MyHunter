/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Chicken Header
*/

#ifndef BACKGROUND_H_
    #define BACKGROUND_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct background_s {
    sfRenderWindow *window;
    int state;
    sfTexture *menu_texture;
    sfSprite *menu_sprite;
    sfTexture *game_texture;
    sfSprite *game_sprite;
    sfTexture *gameover_texture;
    sfSprite *gameover_sprite;
    sfMusic *music;
    sfSound *sound_click;
} background_t;

background_t *background_create(sfRenderWindow *window);
void background_update(background_t *background);
void background_destroy(background_t *background);

#endif /* !BACKGROUND_H_ */
