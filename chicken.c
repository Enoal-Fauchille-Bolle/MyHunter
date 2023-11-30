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
#include <SFML/System/Clock.h>

chicken_t *chicken_create(sfRenderWindow *window)
{
    chicken_t *chicken = malloc(sizeof(chicken_t));

    chicken -> window = window;
    chicken -> texture = sfTexture_createFromFile("./resources/Chicken.png",
        &(sfIntRect){ 0, 0, 800, 150 });
    chicken -> sprite = sfSprite_create();
    chicken -> clock_animation = sfClock_create();
    chicken -> clock_movement = sfClock_create();
    chicken -> clock_speed = sfClock_create();
    chicken -> clock_gameover = sfClock_create();
    chicken -> rect = (sfIntRect){ 0, 0, 200, 150 };
    chicken -> position = (sfVector2f){ 0, 0 };
    chicken -> speed = 6.0;
    chicken -> text_score = sfText_create();
    chicken -> font =
        sfFont_createFromFile("./resources/Minecraftia-Regular.ttf");
    chicken -> score = 0;
    return chicken;
}

void chicken_spawn(chicken_t *chicken)
{
    int y = my_random(1, sfRenderWindow_getSize(chicken->window).y - 150);

    chicken->direction = my_random(1, 2);
    if (chicken->direction == 2) {
        chicken->position = (sfVector2f)
            { sfRenderWindow_getSize(chicken->window).x + 200, y };
    } else {
        chicken->position = (sfVector2f){ -200, y };
    }
}

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
}

void chicken_destroy(chicken_t *chicken)
{
    sfSprite_destroy(chicken->sprite);
    sfTexture_destroy(chicken->texture);
    sfClock_destroy(chicken->clock_animation);
    sfClock_destroy(chicken->clock_movement);
    sfClock_destroy(chicken->clock_speed);
    sfClock_destroy(chicken->clock_gameover);
    free(chicken);
}
