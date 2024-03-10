#include "matrix.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    printf("\nThe addition of the previous 2 matrices:\n");

    print_matrix(c);

    init_identity_matrix(c);

    printf("\nAn identity matrix:\n");

    print_matrix(c);

    printf("\nThe first matrix muliplied by 2:\n");

    multiplyMatrixByScalar(a,2.0);

    print_matrix(a);

    printf("\nThe previous matrix multiplied by the following matrix:\n");

    print_matrix(b);

    printf("\n leads to the following result:\n");

    multiply_matrices(a,b,c);

    print_matrix(c);

    Dot myDot = {1.0, 2.0, 1.0};
    float transformationMatrix[3][3] = {
        {2.0, 0.0, 0.0},
        {0.0, 0.5, 0.0},
        {0.0, 0.0, 1.0}
    };

    transform_point(&myDot, transformationMatrix);
    printf("Transformed Point: (%.2f, %.2f, %.2f)\n", myDot.x, myDot.y, myDot.w);

    float scaleMatrix[3][3];
    float scaleFactor = 2.0;
    scale(scaleMatrix, scaleFactor);
    printf("\nAn indentity matrix made into a scaling matrix with a factor of 2:\n");
    print_matrix(scaleMatrix);

    float shiftMatrix[3][3];
    float dx = 3.0, dy = 1.0;
    shift(shiftMatrix, dx, dy);
    printf("\nAn indentity matrix made into a shifting matrix:\n");
    print_matrix(shiftMatrix);

    float rotateMatrix[3][3];
    float rotationAngle = 45.0;
    rotate(rotateMatrix, rotationAngle);
    printf("\nAn indentity matrix made into a rotation matrix with an angle of 45:\n");
    print_matrix(rotateMatrix);


    //printf("");
	return 0;
}

