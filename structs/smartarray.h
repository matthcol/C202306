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

typedef struct _SmartMatrix {
    size_t rows;
    size_t cols;
    // flags: C (0) or F (1) order, Writeable (0:false, 1:true), ...
    unsigned char flags; 
    double *data;
} SmartMatrix, *SmartMatrix_ptr;

SmartMatrix_ptr empty(size_t rows, size_t cols, unsigned char flags);
SmartMatrix_ptr zeros(size_t rows, size_t cols, unsigned char flags);
SmartMatrix_ptr ones(size_t rows, size_t cols, unsigned char flags);
SmartMatrix_ptr full(size_t rows, size_t cols, unsigned char flags, double value);

void destroy(SmartMatrix_ptr matrix_ptr);

double get(SmartMatrix_ptr matrix_ptr, size_t i, size_t j);
void set(SmartMatrix_ptr matrix_ptr, size_t i, size_t j, double value);

double sum(SmartMatrix_ptr matrix_ptr);
void display(SmartMatrix_ptr matrix_ptr);

bool is_c_order(SmartMatrix_ptr matrix_ptr); 
bool is_f_order(SmartMatrix_ptr matrix_ptr);
bool is_writeable(SmartMatrix_ptr matrix_ptr);
bool is_read_only(SmartMatrix_ptr matrix_ptr);