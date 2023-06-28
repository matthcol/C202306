#pragma once

#include <stdlib.h>

// to use bool instead of _Bool (C99)
#include <stdbool.h>

// constants for flags
// bit 7
extern const unsigned char C_ORDER; // 0x00, 0b00000000
extern const unsigned char F_ORDER; // 0x80, 0b10000000
// bit 6
extern const unsigned char READ_ONLY;  // 0x00, 0b00000000
extern const unsigned char WRITEABLE;  // 0x40, 0b01000000

// flags: C (0) or F (1) order, Writeable (0:false, 1:true), ...
#define SMART_MATRIX_T(T, F) \
typedef struct _SmartMatrix_ ## T { \
    size_t rows; \
    size_t cols; \
    unsigned char flags; \
    T *data; \
} SmartMatrix_ ## T , *SmartMatrix_ ## T ## _ptr; \
\
bool is_f_order_ ## T (SmartMatrix_ ## T ## _ptr matrix_ptr) \
{ \
    return (matrix_ptr->flags & F_ORDER) == F_ORDER; \
} \
\
SmartMatrix_ ## T ## _ptr empty_ ## T (size_t rows, size_t cols, unsigned char flags) \
{ \
    SmartMatrix_ ## T ## _ptr matrix_ptr = malloc(sizeof(SmartMatrix_ ## T )); \
    if (!matrix_ptr) { \
        fprintf(stderr, "Error while allocating matrix struct\n"); \
        return matrix_ptr; \
    } \
    matrix_ptr->cols = cols; \
    matrix_ptr->rows = rows; \
    matrix_ptr->flags = flags; \
    matrix_ptr->data = malloc(rows*cols*sizeof(T)); \
    if (!matrix_ptr->data) { \
        fprintf(stderr, "Error while allocating matrix data\n"); \
        return matrix_ptr; \
    } \
    return matrix_ptr; \
} \
\
void display_ ## T (SmartMatrix_ ## T ## _ptr matrix_ptr)  \
{  \
    if (is_f_order_ ## T (matrix_ptr)) {  \
        for (size_t i=0; i< matrix_ptr->rows; i++){  \
            for (size_t j=0; j< matrix_ptr->cols; j++){  \
                printf(F " ", matrix_ptr->data[j*matrix_ptr->rows + i]); \
            } \
            printf("\n");  \
        } \
    } else {  \
        for (size_t i=0; i< matrix_ptr->rows; i++){  \
            for (size_t j=0; j< matrix_ptr->cols; j++){  \
                printf(F " ", matrix_ptr->data[i*matrix_ptr->cols + j]);  \
            } \
            printf("\n"); \
        } \
    } \
} 




// SmartMatrix_ptr empty(size_t rows, size_t cols, unsigned char flags);
// SmartMatrix_ptr zeros(size_t rows, size_t cols, unsigned char flags);
// SmartMatrix_ptr ones(size_t rows, size_t cols, unsigned char flags);
// SmartMatrix_ptr full(size_t rows, size_t cols, unsigned char flags, double value);

// void destroy(SmartMatrix_ptr matrix_ptr);

// double get(SmartMatrix_ptr matrix_ptr, size_t i, size_t j);
// void set(SmartMatrix_ptr matrix_ptr, size_t i, size_t j, double value);

// double sum(SmartMatrix_ptr matrix_ptr);
// void display(SmartMatrix_ptr matrix_ptr);

// bool is_c_order(SmartMatrix_ptr matrix_ptr); 
// bool is_f_order(SmartMatrix_ptr matrix_ptr);
// bool is_writeable(SmartMatrix_ptr matrix_ptr);
// bool is_read_only(SmartMatrix_ptr matrix_ptr);