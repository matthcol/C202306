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
    display_n(temperatures2); // deborde de 7 cases
    printf("\n");
    display(temperatures2, 3000); // segment fault
    printf("\n");
}

int main() {
    play_with_arrays();
    printf("That's all Folks\n");
    return EXIT_SUCCESS;
}