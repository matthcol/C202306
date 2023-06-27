#include "array.h"

#include <stdio.h> // or in header file

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
    return acc;
}

void display(double tab[], size_t n)
{
    for (size_t i=0; i < n; i++) {
        printf("%f ", tab[i]);
    }
}
