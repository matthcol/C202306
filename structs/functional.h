#pragma once

#include "smartarray.h"

double reduce(
    SmartMatrix_ptr matrix_ptr, 
    double (*reduce_function)(double, double), 
    double init_value
);