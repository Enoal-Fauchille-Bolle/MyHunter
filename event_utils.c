/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Events Utilities
*/

#include "my.h"
#include "my_printf.h"
#include "events.h"
#include <SFML/Graphics/RenderWindow.h>

void analyse_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_click(event.mouseButton);
    }
}

void manage_mouse_click(sfMouseButtonEvent event)
{
    (void)event;
    // my_printf("Mouse x=%d y=%d\n", event.x, event.y);
}
