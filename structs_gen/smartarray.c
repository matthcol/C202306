#include "smartarray.h"

#include <stdio.h>

// constants for flags
// bit 7
const unsigned char C_ORDER = 0x00; // 0b00000000
const unsigned char F_ORDER = 0x80; // 0b10000000
// bit 6
const unsigned char READ_ONLY = 0x00;  // 0b00000000
const unsigned char WRITEABLE = 0x40;  // 0b01000000

// SmartMatrix_ptr empty(size_t rows, size_t cols, unsigned char flags)
// {
//     SmartMatrix_ptr matrix_ptr = malloc(sizeof(SmartMatrix));
//     if (!matrix_ptr) {
//         fprintf(stderr, "Error while allocating matrix struct\n");
//         return matrix_ptr;
//     }
//     matrix_ptr->cols = cols;
//     matrix_ptr->rows = rows;
//     matrix_ptr->flags = flags;
//     matrix_ptr->data = malloc(rows*cols*sizeof(double));
//     if (!matrix_ptr->data) {
//         fprintf(stderr, "Error while allocating matrix data\n");
//         return matrix_ptr;
//     }
//     return matrix_ptr;
// }

// SmartMatrix_ptr zeros(size_t rows, size_t cols, unsigned char flags)
// {
//     SmartMatrix_ptr matrix_ptr = empty(rows, cols, flags);
//     if (!matrix_ptr) return matrix_ptr;
//     for (size_t i=0; i<rows*cols; i++) matrix_ptr->data[i] = 0.0;
//     return matrix_ptr;
// }

// SmartMatrix_ptr ones(size_t rows, size_t cols, unsigned char flags)
// {
//     SmartMatrix_ptr matrix_ptr = empty(rows, cols, flags);
//     if (!matrix_ptr) return matrix_ptr;
//     for (size_t i=0; i<rows*cols; i++) matrix_ptr->data[i] = 1.0;
//     return matrix_ptr;
// }

// SmartMatrix_ptr full(size_t rows, size_t cols, unsigned char flags, double value)
// {
//     SmartMatrix_ptr matrix_ptr = empty(rows, cols, flags);
//     if (!matrix_ptr) return matrix_ptr;
//     for (size_t i=0; i<rows*cols; i++) matrix_ptr->data[i] = value;
//     return matrix_ptr;
// }

// void destroy(SmartMatrix_ptr matrix_ptr)
// {
//     free(matrix_ptr->data);
//     matrix_ptr->data = NULL;
// }

// double sum(SmartMatrix_ptr matrix_ptr)
// {
//     // TODO: optimize iteration
//     return 0.0;
// }

// double get(SmartMatrix_ptr matrix_ptr, size_t i, size_t j)
// {
//     if (is_f_order(matrix_ptr)) return matrix_ptr->data[j*matrix_ptr->rows + i];
//     else return matrix_ptr->data[i*matrix_ptr->cols + j];
// }

// void set(SmartMatrix_ptr matrix_ptr, size_t i, size_t j, double value)
// {
//     if (is_f_order(matrix_ptr)) matrix_ptr->data[j*matrix_ptr->rows + i] = value;
//     else matrix_ptr->data[i*matrix_ptr->cols + j] = value;
// }


// bool is_c_order(SmartMatrix_ptr matrix_ptr)
// {
//     return !is_f_order(matrix_ptr);
// }


// bool is_writeable(SmartMatrix_ptr matrix_ptr)
// {
//     return (matrix_ptr->flags & WRITEABLE) == WRITEABLE;  
// }

// bool is_read_only(SmartMatrix_ptr matrix_ptr)
// {
//     return !is_writeable(matrix_ptr);
// }
