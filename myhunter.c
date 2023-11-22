/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Main File
*/

#include "my.h"
#include "my_printf.h"
// #include "myhunter.h"

static void help_page(void)
{
    my_printf("SDIKQU");
}

int main(int argc, char **argv)
{
    if (argc >= 2 && my_strcmp(argv[1], "-h") == 0)
        help_page();
}
