#ifndef BRICK_H
#define BRICK_H

typedef struct Brick
{
    double x;
    double y;
    double z;
} Brick;

void set_size(Brick* brick, double x, double y, double z);

double calc_volume (Brick* brick);

double calc_surface(Brick* brick);

int has_square_side(Brick* brick);

#endif