#ifndef _ARRAY_H
#define _ARRAY_H

#include <stdlib.h>

#define N 10

// array with fixed size

/**
 * @brief 
 * 
 * @param tab 
 * @param value 
 */
void fill_n(double tab[N], double value);

/**
 * @brief 
 * 
 * @param tab 
 * @return double 
 */
double sum_n(double tab[N]);

/**
 * @brief 
 * 
 * @param tab 
 */
void display_n(double tab[N]);

void fill(double tab[], size_t n, double value);
double sum(double tab[], size_t n);
void display(double tab[], size_t n);

// void fill(double *tab, size_t n);
// double sum(double *tab, size_t n);
// void display(double *tab, size_t n);

// 2D

/**
 * @brief 
 * 
 * @param tab 
 * @param rows 
 */
void display2D(double tab[][N], size_t rows);

/**
 * @brief 
 * 
 * @param tab 
 * @param rows 
 * @param cols 
 */
void display2Ddyn(double *tab, size_t rows, size_t cols);

#endif // !_ARRAY_H
