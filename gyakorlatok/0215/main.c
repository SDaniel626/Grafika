#include "brick.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    Brick brick;
    set_size(&brick,2.0,2.0,4.0);
    printf("The volume of the brick is: %lf \n The surface of the brick is: %lf \n The brick has square sides: %s",calc_volume(&brick),calc_surface(&brick),has_square_side(&brick)? "true" : "false" );
    return 0;
}