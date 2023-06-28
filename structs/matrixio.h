#pragma once

#include "smartarray.h"

bool save_bigendian(SmartMatrix_ptr matrix_ptr, const char *filename);
bool save_littleendian(SmartMatrix_ptr matrix_ptr, const char *filename);
SmartMatrix_ptr read_bigendian(const char *filename);
SmartMatrix_ptr read_littleendian(const char *filename);