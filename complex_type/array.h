#ifndef _ARRAY_H
#define _ARRAY_H

#include <stdlib.h>

#define N 10

// array with fixed size
void fill_n(double tab[N], double value);
double sum_n(double tab[N]);
void display_n(double tab[N]);

void fill(double tab[], size_t n, double value);
double sum(double tab[], size_t n);
void display(double tab[], size_t n);

// void fill(double *tab, size_t n);
// double sum(double *tab, size_t n);
// void display(double *tab, size_t n);

// 2D
void display2D(double tab[][N], size_t rows);
void display2Ddyn(double *tab, size_t rows, size_t cols);

#endif // !_ARRAY_H
