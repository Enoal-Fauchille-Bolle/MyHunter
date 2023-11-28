/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Framebuffer Header
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_

    #include <SFML/Graphics.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color);
void my_draw_square(framebuffer_t *buffer, sfVector2u *position,
    unsigned int size, sfColor color);

#endif    /* FRAMEBUFFER_H_ */
