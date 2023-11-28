/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Utilities Header
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <SFML/Graphics.h>

int str_to_int(char *str);
void change_icon(sfRenderWindow *window);
void move_rect(sfIntRect *rect, int offset, int max_value);
int my_random(int min, int max);

#endif /* UTILS_H_ */
