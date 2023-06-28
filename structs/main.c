#include <stdlib.h>
#include <stdio.h>

#include "smartarray.h"

void play_with_smartmatrix() {
    SmartMatrix_ptr matrix1_ptr = empty(10, 10, C_ORDER | WRITEABLE);
    set(matrix1_ptr, 3, 4, 5.5);
    display(matrix1_ptr);
    printf("\n");

    SmartMatrix_ptr matrix2_ptr = zeros(4, 5, F_ORDER | WRITEABLE);
    set(matrix2_ptr, 3, 4, 5.5);
    display(matrix2_ptr);
    printf("Somme matrice de 0 = %f\n", sum(matrix2_ptr));
    printf("\n");

    SmartMatrix_ptr matrix3_ptr = ones(10, 3, C_ORDER | READ_ONLY);
    set(matrix3_ptr, 3, 2, 5.5);
    display(matrix3_ptr);
    printf("Somme matrice de 1 = %f\n", sum(matrix3_ptr));
    printf("\n");

    destroy(matrix1_ptr);
    free(matrix1_ptr);
    destroy(matrix2_ptr);
    free(matrix2_ptr);
    destroy(matrix3_ptr);
    free(matrix3_ptr);
}



int main() {
    play_with_smartmatrix();
    return EXIT_SUCCESS;
}