/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Framebuffer Utilities
*/

#include "my.h"
#include "framebuffer.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));
    sfUint8 *pixels = malloc(width * height * 32 / 8);

    fb->width = width;
    fb->height = height;
    fb->pixels = pixels;
    return fb;
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color)
{
    int offset = x * 4 + y * 4 * framebuffer->width;

    framebuffer->pixels[0 + offset] = color.r;
    framebuffer->pixels[1 + offset] = color.g;
    framebuffer->pixels[2 + offset] = color.b;
    framebuffer->pixels[3 + offset] = color.a;
}

void my_draw_square(framebuffer_t *buffer, sfVector2u *position,
    unsigned int size, sfColor color)
{
    for (unsigned int x = position->x; x < position->x + size; x++) {
        for (unsigned int y = position->y; y < position->y + size; y++) {
            my_put_pixel(buffer, x, y, color);
        }
    }
}
