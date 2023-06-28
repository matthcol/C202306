#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "smartarray.h"

SMART_MATRIX_T(double, "%.3f")

SMART_MATRIX_T(int, "%d")

void play_with_smartmatrix() {
    SmartMatrix_double matrix1;
    SmartMatrix_int matrix2;  

    SmartMatrix_double_ptr matrix3_ptr = empty_double(5,4, C_ORDER);
    SmartMatrix_int_ptr matrix4_ptr = empty_int(5,4, F_ORDER);

    matrix3_ptr->data[1] = 12.5;
    display_double(matrix3_ptr);

    printf("\n");

    matrix4_ptr->data[2] = 108;
    display_int(matrix4_ptr);

    // TODO: destroy matrix 3 et 4 and data of theses 2 matrix
}


int main() {
    play_with_smartmatrix();
    return EXIT_SUCCESS;
}