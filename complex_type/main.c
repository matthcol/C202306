#include <stdio.h>
#include <stdlib.h>

#include "array.h"

// déclaration en avant
int f(int d); // => .h (header)

int f(int d){  // => .c
    return 2 * d + 1;
}

void play_with_arrays() {
    double temperatures[] = {12.25, 25.3, 12.3, 56.4, 23.1, -10.2, 22.1, 20.4, 26.2, 12.3};
    double temperatures2[] = {6.6, 7.7, 8.8};
    display(temperatures, 10);
    printf("\n");
    display_n(temperatures);
    printf("\n");
    display(temperatures2, 3);
    printf("\n");
    // display_n(temperatures2); // deborde de 7 cases
    // printf("\n");
    // display(temperatures2, 3000); // segment fault
    // printf("\n");
    double temperatures3[5]; // static non initialized
    display(temperatures3, 5);
    printf("\n");
    fill(temperatures3, 5, 3.5);
    display(temperatures3, 5);
    printf("\n");
    printf("@var temperatures3=%p, @tab temperatures3=%p\n\n", &temperatures3, temperatures3);
    // double temperatures4[1000000000];  // too big for the stack
    // display(temperatures4, 10);
    size_t taille = 250000000;
    double *temperatures4 = malloc(taille*sizeof(double));
    fill(temperatures4, taille, 5.5);
    display(temperatures4, 10);
    printf(" ... ");
    display(temperatures4 + taille - 11, 10);
    printf("\n");
    printf("@var temperatures4=%p, @tab temperatures4=%p\n\n", &temperatures4, temperatures4);

    printf("values: %f %f ; @: %p %p\n", temperatures4[3], *(temperatures4+3), &(temperatures4[3]), temperatures4+3);
    printf("values: %f %f ; @: %p %p\n", temperatures3[3], *(temperatures3+3), &(temperatures3[3]), temperatures3+3);

    // temperatures3 = temperatures2; // forbidden array assignment
    double *array = temperatures;
    display(array, 3); printf("\n");
    array = temperatures2;
    display(array, 3); printf("\n");
    array = temperatures4 + 1000;
    display(array, 3); printf("\n");
    free(temperatures4);
    // sion fait d'autres choses ici, par sureté mettre à null le(s) pointeur(s)
    temperatures4 = NULL;
    array = NULL;
    // display(array, 5); // seg fault
    // display(temperatures4, 5); // seg fault
}

void play_with_arrays2D() {
    double values[5][N] = {
        {12.25, 25.3, 12.3, 56.4, 23.1, -10.2, 22.1, 20.4, 26.2, 22.3},
        {13.25, 25.3, 12.3, 56.4, 23.1, -10.2, 22.1, 20.4, 26.2, 32.3},
        {14.25, 25.3, 12.3, 56.4, 23.1, -10.2, 22.1, 20.4, 26.2, 42.3},
        {15.25, 25.3, 12.3, 56.4, 23.1, -10.2, 22.1, 20.4, 26.2, 52.3},
        {16.25, 25.3, 12.3, 56.4, 23.1, -10.2, 22.1, 20.4, 26.2, 62.3},
    };
    double values2[20] = { // 4x5
        12.25, 25.0, 12.0, 56.6, 24.1, // row 0
        22.25, 25.2, 12.1, 56.7, 25.1, // row 1
        32.25, 25.4, 12.2, 56.8, 26.1, // row 2
        42.25, 25.6, 12.3, 56.9, 27.1, // row 3
    };
    double *values3 = malloc(80*sizeof(double)); // 8x10
    display2D(values, 5);
    display2Ddyn((double *) values, 5, 10); // to see 2D array as 1D array
    display2Ddyn(values2, 4, 5);
    display2Ddyn(values3, 8, 10);
    free(values3);
}

int main() {
    // play_with_arrays();
    play_with_arrays2D();
    printf("That's all Folks\n");
    return EXIT_SUCCESS;
}