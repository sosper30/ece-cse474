#ifndef MATHLIB_H
#define MATHLIB_H

typedef struct {
    double real;
    double imag;
} complex_t;

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV
} operation_t;

int perform_operation(int a, int b, operation_t op);
complex_t perform_complex_operation(complex_t a, complex_t b, operation_t op);

#endif // MATHLIB_H
