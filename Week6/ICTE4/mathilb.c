#include "mathlib.h"

int perform_operation(int a, int b, operation_t op) {
    int result;
    switch(op) {
        case ADD:
            result = a + b;
            break;
        case SUB:
            result = a - b;
            break;
        case MUL:
            result = a * b;
            break;
        case DIV:
            if(b != 0) {
                result = a / b;
            } else {
                result = 0;
            }
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

complex_t perform_complex_operation(complex_t a, complex_t b, operation_t op) {
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
                result.real = result.imag = 0.0/0.0;
            }
            break;
        default:
            result.real = result.imag = 0.0/0.0;
            break;
    }
    return result;
}
