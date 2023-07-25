/**
 * @file mathlib.c
 * @brief This file includes the implementation for a basic math library.
 */

#include "mathlib.h"

/**
 * @brief Perform the specified operation on two complex numbers
 * 
 * @param a The first complex number
 * @param b The second complex number
 * @param op The operation to perform
 * @return The result of the operation
 * @details This function performs an operation specified by the operation_t enum on two complex numbers.
 *          If the operation is not recognized, it returns a complex number with NaN for both real and imaginary parts.
 */
complex_t perform_operation(complex_t a, complex_t b, operation_t op) {
    complex_t result;
    switch(op) {
        case ADD:
            result.real = a.real + b.real;
            result.imag = a.imag + b.imag;
            break;
        case SUB:
            result.real = a.real - b.real;
            result.imag = a.imag - b.imag;
            break;
        case MUL:
            result.real = a.real * b.real - a.imag * b.imag;
            result.imag = a.real * b.imag + a.real * b.real;
            break;
        case DIV:
            if(b.real != 0 || b.imag != 0) {
                double denom = b.real * b.real + b.imag * b.imag;
                result.real = (a.real * b.real + a.imag * b.imag) / denom;
                result.imag = (a.imag * b.real - a.real * b.imag) / denom;
            } else {
                result.real = result.imag = 0.0/0.0; // NaN
            }
            break;
        default:
            result.real = result.imag = 0.0/0.0; // NaN
            break;
    }
    return result;
}
