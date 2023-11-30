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

static void chicken_create_clocks(chicken_t *chicken)
{
    chicken -> clock_animation = sfClock_create();
    chicken -> clock_movement = sfClock_create();
    chicken -> clock_speed = sfClock_create();
    chicken -> clock_gameover = sfClock_create();
    chicken -> clock_sound = sfClock_create();
}

static void chicken_setup_sounds(chicken_t *chicken)
{
    sfSound_setBuffer(chicken->sound_idle1,
        sfSoundBuffer_createFromFile("./resources/ChickenIdle1.ogg"));
    sfSound_setVolume(chicken->sound_idle1, 50);
    sfSound_setBuffer(chicken->sound_idle2,
        sfSoundBuffer_createFromFile("./resources/ChickenIdle2.ogg"));
    sfSound_setVolume(chicken->sound_idle2, 50);
    sfSound_setBuffer(chicken->sound_idle3,
        sfSoundBuffer_createFromFile("./resources/ChickenIdle3.ogg"));
    sfSound_setVolume(chicken->sound_idle3, 50);
    sfSound_setBuffer(chicken->sound_hurt1,
        sfSoundBuffer_createFromFile("./resources/ChickenHurt1.ogg"));
    sfSound_setVolume(chicken->sound_hurt1, 50);
    sfSound_setBuffer(chicken->sound_hurt2,
        sfSoundBuffer_createFromFile("./resources/ChickenHurt2.ogg"));
    sfSound_setVolume(chicken->sound_hurt2, 50);
    sfSound_setBuffer(chicken->sound_gameover,
        sfSoundBuffer_createFromFile("./resources/ChickenPlop.ogg"));
}

static void chicken_create_sounds(chicken_t *chicken)
{
    chicken -> sound_idle1 = sfSound_create();
    chicken -> sound_idle2 = sfSound_create();
    chicken -> sound_idle3 = sfSound_create();
    chicken -> sound_hurt1 = sfSound_create();
    chicken -> sound_hurt2 = sfSound_create();
    chicken -> sound_gameover = sfSound_create();
}

chicken_t *chicken_create(sfRenderWindow *window)
{
    chicken_t *chicken = malloc(sizeof(chicken_t));

    chicken -> window = window;
    chicken -> texture = sfTexture_createFromFile("./resources/Chicken.png",
        &(sfIntRect){ 0, 0, 800, 150 });
    chicken -> sprite = sfSprite_create();
    chicken_create_clocks(chicken);
    chicken -> rect = (sfIntRect){ 0, 0, 200, 150 };
    chicken -> position = (sfVector2f){ 0, 0 };
    chicken -> speed = 6.0;
    chicken -> text_score = sfText_create();
    chicken -> font =
        sfFont_createFromFile("./resources/Minecraftia-Regular.ttf");
    chicken -> score = 0;
    chicken_create_sounds(chicken);
    chicken_setup_sounds(chicken);
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

void chicken_destroy_sounds(chicken_t *chicken)
{
    sfSound_destroy(chicken->sound_idle1);
    sfSound_destroy(chicken->sound_idle2);
    sfSound_destroy(chicken->sound_idle3);
    sfSound_destroy(chicken->sound_hurt1);
    sfSound_destroy(chicken->sound_hurt2);
    sfSound_destroy(chicken->sound_gameover);
}

void chicken_destroy(chicken_t *chicken)
{
    sfSprite_destroy(chicken->sprite);
    sfTexture_destroy(chicken->texture);
    sfClock_destroy(chicken->clock_animation);
    sfClock_destroy(chicken->clock_movement);
    sfClock_destroy(chicken->clock_speed);
    sfClock_destroy(chicken->clock_gameover);
    sfClock_destroy(chicken->clock_sound);
    chicken_destroy_sounds(chicken);
    free(chicken);
}
