#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define CITY "Pau"
#define CITY_IDENT(C) city_ ## C

#define FLOAT 0
#define DOUBLE 1
#define LONG_DOUBLE 2

// 1st version of T
// #define META_T DOUBLE
// #define T double
// #define T_DEFAULT 0.0
// #define T_FORMAT "%.3f"

// 2nd version of T
#define META_T FLOAT
#define T float
#define T_DEFAULT 0.0f
#define T_FORMAT "%.3f"


#define CARRE(N) N*N
#define DEBUG(V,F) printf("variable = " #V " ; value = " F " ; @ = %p\n", V, &V);
#define DEBUG_T(V) DEBUG(V,T_FORMAT)
#define DEBUG_STR(V) DEBUG(V,"%s")
#define DEBUG_PTR(V) DEBUG(V, "%p")

#define CITY_VAR1 CITY_IDENT(Pau)
#define CITY_VAR2 CITY_IDENT(Toulouse)


#if META_T == DOUBLE
    #define SQRT sqrt
#elif META_T == FLOAT
    #define SQRT sqrtf
#elif META_T == LONG_DOUBLE
    #define SQRT sqrtl
#else
    #define SQRT __unknown_sqrt__
#endif

void fonction_adaptative(
#if META_T == DOUBLE
    double *x
#else
    void *x
#endif
) {
    printf("je m'adapte: %p\n", x);
}

// macros OS dependent
#ifdef __linux__
    #define OS "LINUX"
#else
    #ifdef _WIN64
        #define OS "WINDOWS64"
    #else
        #ifdef _WIN32
            #define OS "WINDOWS32"
        #else
            #define OS "OTHER"
        #endif
    #endif
#endif




int main() {
    char CITY_VAR1[] = CITY;
    char CITY_VAR2[] = "Toulouse";
    printf("City: %s\n", CITY_VAR1);

    T nombre = T_DEFAULT;
    nombre = SQRT(CARRE(nombre) + CARRE(4.0));
    T *nombre_ptr = &nombre; 
    printf(T_FORMAT, nombre);
    printf("\n");
    DEBUG(nombre, T_FORMAT)
    DEBUG(CITY_VAR1, "%s")
    DEBUG(main, "%p")
    // same thing with macro of macro
    printf("\n");
    DEBUG_T(nombre)
    DEBUG_STR(CITY_VAR1)
    DEBUG_STR(CITY_VAR2)
    DEBUG_PTR(main)
    DEBUG_PTR(nombre_ptr)

    fonction_adaptative(&nombre);

    printf("OS=%s\n", OS);
    return EXIT_SUCCESS;
}