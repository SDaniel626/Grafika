#include <brick.h>
#include <stdio.h>

void set_size(Brick* brick, double x, double y, double z)
{
    if(x>0 && y>0 && z>0)
    {
        brick.x = x;
        brick.y = y;
        brick.z = z;
    }
    else
    {
        printf("invalid input\n");
    }
}

double calc_volume (Brick* brick)
{
    double V = brick->x*brick->y*brick->z;
    return V;
}

double calc_surface(Brick* brick)
{
    double S = 2*(brick->x * brick->y + brick->y * brick->z + brick->x * brick->z) ;
    return S;
}

int has_square_side(Brick* brick)
{
    if (brick->x == brick->y || brick->x == brick->z || brick->y == brick->z)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}