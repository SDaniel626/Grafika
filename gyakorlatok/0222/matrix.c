#include "matrix.h"

#include <stdio.h>
#include <math.h>

struct Dot {
    float x;
    float y;
    float w;
};

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) {
				matrix[i][j] = 1.0;
			} else {
				matrix[i][j] = 0.0;
			}
		}
	}
}

void multiplyMatrixByScalar(float matrix[3][3], float scalar) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] *= scalar;
        }
    }
}

void multiply_matrices(float matrix1[3][3], float matrix2[3][3], float result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transform_point(Dot *dot, float matrix[3][3])
{
	float newX = matrix[0][0] * dot->x + matrix[0][1] * dot->y + matrix[0][2] * dot->w;
    float newY = matrix[1][0] * dot->x + matrix[1][1] * dot->y + matrix[1][2] * dot->w;
    float newW = matrix[2][0] * dot->x + matrix[2][1] * dot->y + matrix[2][2] * dot->w;

    dot->x = newX;
    dot->y = newY;
    dot->w = newW;
}

void scale(float matrix[3][3], float lambda)
{
	init_identity_matrix(matrix);
	matrix[0][0] = lambda;
	matrix[1][1] = lambda;
}

void shift(float matrix[3][3],float dx, float dy)
{
	init_identity_matrix(matrix);
	matrix[0][2] = dx;
	matrix[1][2] = dy;
}

void rotate(float matrix[3][3], float phi)
{
	init_identity_matrix(matrix);
	matrix[0][0] = (float)cos(phi * M_PI / 180.0);
	matrix[0][1] = (float)-sin(phi * M_PI / 180.0);
	matrix[1][0] = (float)sin(phi * M_PI / 180.0);
	matrix[1][1] = (float)cos(phi * M_PI / 180.0);
}

typedef struct {
    float matrices[5][3][3]; 
    int stackIndex;          
} MatrixStack;


void initialize_matrix_container(MatrixStack *container) {
    container->stackIndex = 0;
}


void push_matrix(MatrixStack *container, float matrix[3][3]) {
    if (container->stackIndex < 5) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                container->matrices[container->stackIndex][i][j] = matrix[i][j];
            }
        }        
        container->stackIndex++;
    } else {
        printf("Matrix stack overflow\n");
    }
}


float (*pop_matrix(MatrixStack *container))[3][3] {
    if (container->stackIndex > 0) {
        container->stackIndex--;
        return &(container->matrices[container->stackIndex]);
    } else {
        printf("Matrix stack underflow\n");
        return NULL;
    }
}



