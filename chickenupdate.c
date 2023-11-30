/*
** EPITECH PROJECT, 2023
** Bootstrap MyHunter
** File description:
** Chicken
*/

#include "my.h"
#include "my_printf.h"
#include "chicken.h"
#include "background.h"
#include "utils.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/System/Clock.h>

static void chicken_update_movement(chicken_t *chicken,
    background_t *background)
{
    if (sfClock_getElapsedTime(chicken->clock_movement).microseconds /
        1000.0 > 10) {
        if (chicken->direction == 1) {
            chicken->position.x += chicken->speed;
            sfSprite_setScale(chicken->sprite, (sfVector2f){ 1, 1 });
        } else {
            chicken->position.x -= chicken->speed;
            sfSprite_setScale(chicken->sprite, (sfVector2f){ -1, 1 });
        }
        sfClock_restart(chicken->clock_movement);
    }
    if ((chicken->direction == 1 &&
        chicken->position.x > sfRenderWindow_getSize(chicken->window).x) ||
        (chicken->direction == 2 &&
        chicken->position.x < 0)) {
        background->state = 3;
        sfClock_restart(chicken->clock_gameover);
        sfSound_play(chicken->sound_gameover);
    }
}

static void chicken_update_animation(chicken_t *chicken)
{
    if (sfClock_getElapsedTime(chicken->clock_animation).microseconds /
        1000.0 > 200) {
        move_rect(&chicken->rect, 200, 800);
        sfClock_restart(chicken->clock_animation);
    }
}

static void chicken_update_speed(chicken_t *chicken)
{
    if (sfClock_getElapsedTime(chicken->clock_speed).microseconds /
        1000.0 > 5000) {
        chicken->speed += 1.0;
        sfClock_restart(chicken->clock_speed);
    }
}

static void chicken_update_gameover(chicken_t *chicken)
{
    sfText_setString(chicken->text_score, my_int_to_str(chicken->score));
    sfText_setCharacterSize(chicken->text_score, 45);
    sfText_setFont(chicken->text_score, chicken->font);
    sfText_setFillColor(chicken->text_score, sfYellow);
    sfText_setPosition(chicken->text_score, (sfVector2f){ 969, 486 });
    sfRenderWindow_drawText(chicken->window, chicken->text_score, NULL);
}

static void chicken_update_score(chicken_t *chicken)
{
    sfText_setString(chicken->text_score, my_strconcat("Score: ",
        my_int_to_str(chicken->score)));
    sfText_setCharacterSize(chicken->text_score, 45);
    sfText_setFont(chicken->text_score, chicken->font);
    sfText_setFillColor(chicken->text_score, sfYellow);
    sfText_setPosition(chicken->text_score, (sfVector2f){ 10, 30 });
    sfRenderWindow_drawText(chicken->window, chicken->text_score, NULL);
}

static void chicken_update_sound(chicken_t *chicken)
{
    if (sfClock_getElapsedTime(chicken->clock_sound).microseconds /
        1000.0 > 3000) {
        switch (my_random(1, 3)) {
            case 1:
                sfSound_play(chicken->sound_idle1);
                break;
            case 2:
                sfSound_play(chicken->sound_idle2);
                break;
            case 3:
                sfSound_play(chicken->sound_idle3);
                break;
        }
        sfClock_restart(chicken->clock_sound);
    }
}

void chicken_update(chicken_t *chicken, background_t *background)
{
    if (background->state == 3)
        return chicken_update_gameover(chicken);
    if (background->state != 2) {
        chicken->score = 0;
        chicken->speed = 6.0;
        return;
    }
    chicken->texture = sfTexture_createFromFile("./resources/Chicken.png",
        &chicken->rect);
    sfSprite_setTexture(chicken->sprite, chicken->texture, sfTrue);
    sfSprite_setPosition(chicken->sprite, chicken->position);
    sfRenderWindow_drawSprite(chicken->window, chicken->sprite, NULL);
    chicken_update_speed(chicken);
    chicken_update_animation(chicken);
    chicken_update_movement(chicken, background);
    chicken_update_score(chicken);
    chicken_update_sound(chicken);
}
