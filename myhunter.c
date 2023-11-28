/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** Main File
*/

#include "my.h"
#include "my_printf.h"
#include "myhunter.h"
#include "utils.h"

/*
USAGE
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...

DESCRIPTION
    x abscissa of the original point
    y ordinate of the original point

    transfo arg1 [arg2]
    -t i j translation along vector (i, j)
    -z m n scaling by factors m (x-axis) and n (y-axis)
    -r d rotation centered in O by a d degree angle
    -s d reflection over the axis passing through O with an inclination
    angle of d degrees
*/

static int help_page(void)
{
    my_printf("USAGE\n");
    my_printf("    ./my_hunter [-h]\n\n");
    my_printf("DESCRIPTION\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc >= 2 && my_strcmp(argv[1], "-h") == 0)
        return help_page();
    else
        return game_instance(1920, 1080);
}
