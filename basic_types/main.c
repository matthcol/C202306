#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <fenv.h>

// activate round mode change
// #pragma STDC FENV_ACCESS ON // eventually (unknown pragma)

/**
 * @brief show processor round mode
 * source: cppreference.com
 * links:
 * https://www.gnu.org/software/libc/manual/html_node/Rounding.html
 */
void show_fe_current_rounding_direction(void)
{
    printf("current rounding direction:  ");
    switch (fegetround()) {
           case FE_TONEAREST:  printf ("FE_TONEAREST");  break;
           case FE_DOWNWARD:   printf ("FE_DOWNWARD");   break;
           case FE_UPWARD:     printf ("FE_UPWARD");     break;
           case FE_TOWARDZERO: printf ("FE_TOWARDZERO"); break;
           default:            printf ("unknown");
    };
    printf("\n");
}

// surcharge interdite en C
// void f(int x) {}
// void f(long x) {}

void f_int(int x) {}
void f_long(long x) {}

void playWithIntegers() {
    printf("Integers in C\n");
    int x = 12; // -2^31 to 2^31-1
    printf("Int: value=%d, type size=%lu B, @=%p , min=%d, max=%d\n", x, 
            sizeof(int), &x, INT_MIN, INT_MAX);
    x = INT_MAX;
    x++;
    printf("Int max +1: %d\n", x);
    // signed: char, short, int, long, long long
    // unsigned: unsigned char, ... , unsigned long long
    // alias de type: int8_t, uint8_t ... int64_t, uint64_t
    long xl = 8000000000L; // -2^63 to 2^63-1
    printf("Long: value=%ld, type size=%lu B, @=%p , min=%ld, max=%ld\n", 
            xl, sizeof(long), &xl, LONG_MIN, LONG_MAX);
    long long xll = 9000000000000000000LL; // -2^63 to 2^63-1
    printf("Long long: value=%lld, type size=%lu B, @=%p , min=%lld, max=%lld\n", 
            xll, sizeof(long long), &xll, LLONG_MIN, LLONG_MAX);
    uint64_t xull = 18000000000000000000LLU; // ie unsigned long long
    printf("uint64_t: value=%lu, type size=%lu B, @=%p , min=%lu, max=%lu\n", 
            xull, sizeof(uint64_t), &xull, 0LU, ULONG_MAX);
    int8_t x8 = 127; // i.e. char i.e. signed char
    printf("int8_t: value=%d, type size=%lu B, @=%p , min=%d, max=%d\n", 
            x8, sizeof(int8_t), &x8, CHAR_MIN, CHAR_MAX);
    printf("\n");
}

long long demo_stack(){
    long long x=0LL;
    playWithIntegers();
    return x+1;
}

void play_with_floats(){
    // cas du 1/10e
    float f = 0.1f;
    double d = 0.1;
    printf("%.10f %.10ff %.10f\n", f, 2*f, 3*f);
    printf("%.17ff %.17ff %.17f\n", d, 2*d, 3*d);
    printf("%d\n", 2*f == 0.2f);
    printf("%d\n", 3*f == 0.3f);
    //  limites
    double big_double = 1E308;
    double inf = big_double*2;
    printf("big double: %f %e\n", big_double, 2*big_double);
    printf("Inf: %f\n", inf);
    printf("Inf * -1: %f\n", -1 * inf);
    printf("Inf / Inf: %f\n", inf / inf);
    printf("1 / 0 (double): %f\n", 1.0 / 0.0);
    // printf("1 / 0 (int): %d\n", 1 / 0); // Floating point exception (core dumped)
    printf("0 / 0 (double): %f\n", 0.0 / 0.0);
    printf("Constantes : INF=%f, NAN=%f\n", INFINITY, NAN);
    printf("Isnan: naive=%d, ok=%d\n", (inf/inf) == NAN, isnan(inf/inf));
}

void compute_with_round(){
    double pi3dr = round(1000 * M_PI);
    double pi3dc = ceil(1000 * M_PI);
    double pi3df = floor(1000 * M_PI);
    double pi3dt = trunc(1000 * M_PI);
    double pi3dp = nearbyint(1000 * M_PI); // or rint
    show_fe_current_rounding_direction();
    printf("PI: round=%f,  ceil=%f,  floor=%f, trunc=%f, near=%f\n", pi3dr, pi3dc, pi3df, pi3dt, pi3dp);
}

void compute_with_floats(){
    // calcul trigo
    double pi = 3.14;
    double res = sin(pi);
    printf("sin(%.6f) = %.6f\n", pi, res);
    printf("PI = %.15f\n", M_PI); // M_PI constant non ISO C (gcc OK)
    // power, log, sqrt
    double res2 = pow(2.0, 10.0);
    printf("2^10 = %f, sqrt(x) = %f\n\n", res2, sqrt(res2)); 
    // round, ceil, floor
    compute_with_round();
    fesetround(FE_TOWARDZERO);
    compute_with_round();
    fesetround(FE_UPWARD);
    compute_with_round();
    fesetround(FE_DOWNWARD);
    compute_with_round();
}

int main() {
    // playWithIntegers();
    // demo_stack();
    // playWithIntegers();
    // play_with_floats();
    compute_with_floats();
    return EXIT_SUCCESS;
}