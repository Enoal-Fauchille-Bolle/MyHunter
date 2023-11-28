/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Sprites Header
*/

#ifndef SPRITES_H_
    #define SPRITES_H_

    #include <SFML/Graphics.h>

sfTexture *get_bg_texture(void);
sfTexture *get_chicken_texture(void);
int show_background(sfRenderWindow *window, sfTexture *bg_texture,
    sfSprite *bg_sprite);

#endif /* !SPRITES_H_ */
