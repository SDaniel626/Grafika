#ifndef MATRIX_H
#define MATRIX_H

/**
 * Structure containing the coordinates that define a point.
*/
typedef struct {
    float x;
    float y;
    float w;
} Dot;
/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
* Initializes the matrix to make it a unit matrix.
*/
void init_identity_matrix(float matrix[3][3]);

/**
* Multiply each element of the matrix by the scalar.
*/
void multiplyMatrixByScalar(float matrix[3][3], float scalar);

/**
* Multiplies matrices with matrices.
*/
void multiply_matrices(float matrix1[3][3], float matrix2[3][3], float result[3][3]);

/**
* Perform matrix transformation on point's coordinates
*/
void transform_point(Dot *dot, float matrix[3][3]);

/**
 * Takes a matrix and a number then makes the matrix into a scaling matrix.
*/
void scale(float matrix[3][3], float lambda);

/**
 * Takes a matrix and two numbers theb makes the matrix into a shifting matrix.
*/
void shift(float matrix[3][3],float dx, float dy);

/**
 * Takes a matrix and an angle then makes the matrix into a rotation matrix.
*/
void rotate(float matrix[3][3], float phi);

#endif // MATRIX_H

