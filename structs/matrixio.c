#include "matrixio.h"
#include <stdio.h>
#include <errno.h>

bool save_bigendian(SmartMatrix_ptr matrix_ptr, const char *filename)
{   
    size_t buffer_size;
    double buffer_double;
    FILE *f = fopen(filename, "wb");
    if (!f) { // or f == NULL
        switch (errno){
            case EEXIST:
                fprintf(stderr, "Error file %s: already exist\n", filename);
                break;
            case EACCES:
                fprintf(stderr, "Error file %s: permission denied\n", filename);
                break;
            case EFAULT:
                fprintf(stderr, "Error file %s: bad path\n", filename);
                break;
            default:
                fprintf(stderr, "Error file %s: code %d\n", filename, errno);
        }
        return false;
    }
    size_t bytes;
    swap_endianness(&matrix_ptr->rows, &buffer_size, sizeof(size_t));
    bytes = fwrite(&buffer_size, sizeof(matrix_ptr->rows), 1, f);
    if (bytes == 0) {
        fprintf(stderr, "Error file %s: writing data\n", filename);
        fclose(f);
        return false;
    }
    swap_endianness(&matrix_ptr->cols, &buffer_size, sizeof(size_t));
    bytes = fwrite(&buffer_size, sizeof(matrix_ptr->cols), 1, f);
    if (bytes == 0) {
        fprintf(stderr, "Error file %s: writing data\n", filename);
        fclose(f);
        return false;
    }
    bytes = fwrite(&matrix_ptr->flags, sizeof(matrix_ptr->flags), 1, f);
    if (bytes == 0) {
        fprintf(stderr, "Error file %s: writing data\n", filename);
        fclose(f);
        return false;
    }
    for (size_t i=0; i < matrix_ptr->rows * matrix_ptr->cols; i++) {
        swap_endianness(matrix_ptr->data + i, &buffer_double, sizeof(double));
        bytes = fwrite(&buffer_double, sizeof(double), 1, f);
        if (bytes == 0) {
            fprintf(stderr, "Error file %s: writing data\n", filename);
            fclose(f);
            return false;
        }   
    }
    fclose(f);
    return true;
}

bool save_littleendian(SmartMatrix_ptr matrix_ptr, const char *filename)
{
    FILE *f = fopen(filename, "wb");
    if (!f) { // or f == NULL
        switch (errno){
            case EEXIST:
                fprintf(stderr, "Error file %s: already exist\n", filename);
                break;
            case EACCES:
                fprintf(stderr, "Error file %s: permission denied\n", filename);
                break;
            case EFAULT:
                fprintf(stderr, "Error file %s: bad path\n", filename);
                break;
            default:
                fprintf(stderr, "Error file %s: code %d\n", filename, errno);
        }
        return false;
    }
    size_t bytes;
    bytes = fwrite(&matrix_ptr->rows, sizeof(matrix_ptr->rows), 1, f);
    if (bytes == 0) {
        fprintf(stderr, "Error file %s: writing data\n", filename);
        fclose(f);
        return false;
    }
    bytes = fwrite(&matrix_ptr->cols, sizeof(matrix_ptr->cols), 1, f);
    if (bytes == 0) {
        fprintf(stderr, "Error file %s: writing data\n", filename);
        fclose(f);
        return false;
    }
    bytes = fwrite(&matrix_ptr->flags, sizeof(matrix_ptr->flags), 1, f);
    if (bytes == 0) {
        fprintf(stderr, "Error file %s: writing data\n", filename);
        fclose(f);
        return false;
    }
    for (size_t i=0; i < matrix_ptr->rows * matrix_ptr->cols; i++) {
        bytes = fwrite(matrix_ptr->data + i, sizeof(double), 1, f);
        if (bytes == 0) {
            fprintf(stderr, "Error file %s: writing data\n", filename);
            fclose(f);
            return false;
        }   
    }
    fclose(f);
    return true;
}

SmartMatrix_ptr read_bigendian(const char *filename)
{
    return NULL;
}

SmartMatrix_ptr read_littleendian(const char *filename)
{
    return NULL;
}

void swap_endianness(const void *buffer_in, void *buffer_out, size_t size)
{
    unsigned char *buffer_bytes_in = (unsigned char *) buffer_in;
    unsigned char *buffer_bytes_out = (unsigned char *) buffer_out; 
    for (size_t i=0; i<size; i++) {
        buffer_bytes_out[size-i-1] = buffer_bytes_in[i];
    }
}
