#include "functional.h"

double reduce(SmartMatrix_ptr matrix_ptr, double (*reduce_function)(double, double), double init_value)
{
    double res = init_value;
    for (size_t i=0; i < matrix_ptr->rows*matrix_ptr->cols; i++) {
        res = reduce_function(res, matrix_ptr->data[i]);
        // res = (*reduce_function)(res, matrix_ptr->data[i]); // call C puriste
        
        // printf("DEBUG! #%d add %f => %f\n", i, matrix_ptr->data[i], res);
    }
    return res;
}