#include "array.h"

#include <stdio.h> // or in header file
#include <math.h>

void fill_n(double tab[N], double value)
{
    fill(tab, N, value);
}

double sum_n(double tab[N])
{
    return sum(tab, N);
}

void display_n(double tab[N])
{
    display(tab, N);
}

void fill(double tab[], size_t n, double value)
{
    for (size_t i=0; i < n; i++) {
        tab[i] = value;
    }
}

double sum(double tab[], size_t n)
{
    double acc = 0.0;
    for (size_t i=0; i < n; i++) {
        acc += tab[i];
    } 
    return sqrt(acc*acc); // just for fun and to use libm
}

void display(double tab[], size_t n)
{
    for (size_t i=0; i < n; i++) {
        printf("%f ", tab[i]);
    }
}

void display2D(double tab[][N], size_t rows)
{
    for (size_t i=0; i < rows; i++) {
        for (size_t j=0; j < N; j++) {
            printf("%.2f ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void display2Ddyn(double *tab, size_t rows, size_t cols){
    for (size_t i=0; i < rows; i++) {
        for (size_t j=0; j < cols; j++) {
            printf("%.2f ", *(tab + i * cols + j)); // i.e. tab[i][j]
        }
        printf("\n");
    }
    printf("\n");
}
