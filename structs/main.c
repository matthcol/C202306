#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "smartarray.h"
#include "matrixio.h"
#include "functional.h"

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

void play_input_output_matrix(){
    SmartMatrix_ptr matrix_ptr = full(10, 300, WRITEABLE|C_ORDER, -5.75);
    display(matrix_ptr);
    if (save_littleendian(matrix_ptr, "matrix_le.dat")) {
        printf("Matrix saved (little endian) with success\n");
    } else {
        printf("Fail saving matrix\n");
    }
     if (save_bigendian(matrix_ptr, "matrix_be.dat")) {
        printf("Matrix saved (big) endian) with success\n");
    } else {
        printf("Fail saving matrix\n");
    }
}

void play_endianness(){
    uint32_t data = 0x123456fa;
    uint32_t data_out;
    swap_endianness(&data, &data_out, sizeof(data));
    printf("data in=%x, out=%x\n", data, data_out);
}


double plus(double d1, double d2){ return d1 + d2;}

double mind(double d1, double d2){ return d1 < d2 ? d1: d2;}

void play_functional_matrix(){
    SmartMatrix_ptr matrix_ptr = ones(10, 30, WRITEABLE|C_ORDER);
    set(matrix_ptr, 2, 3, 5.0);
    set(matrix_ptr, 3, 2, -3.0);    
    display(matrix_ptr);
    double s = reduce(matrix_ptr, plus, 0.0);
    // double s = reduce(matrix_ptr, &plus, 0.0); // puriste du C
    printf("Somme matrix: %.3f\n", s);

    double m = reduce(matrix_ptr, mind, INFINITY);
    printf("Min matrix: %.3f\n", m);
}

int main() {
    // play_with_smartmatrix();
    // play_input_output_matrix();
    // play_endianness();
    play_functional_matrix();
    return EXIT_SUCCESS;
}