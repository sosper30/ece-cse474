/**
 * @file mathlib.h
 * @brief This file includes function prototypes for a basic math library.
 */

#ifndef MATHLIB_H
#define MATHLIB_H

/** 
 * @brief Struct that defines a complex number
 */
typedef struct {
    double real; /**< The real part of the complex number */
    double imag; /**< The imaginary part of the complex number */
} complex_t;

/** 
 * @brief Enum that defines possible operations for the math library 
 */
typedef enum {
    ADD, /**< Addition operation */
    SUB, /**< Subtraction operation */
    MUL, /**< Multiplication operation */
    DIV  /**< Division operation */
} operation_t;

/**
 * @brief Perform the specified operation on two complex numbers
 * 
 * @param a The first complex number
 * @param b The second complex number
 * @param op The operation to perform
 * @return The result of the operation
 */
complex_t perform_operation(complex_t a, complex_t b, operation_t op);

#endif // MATHLIB_H
