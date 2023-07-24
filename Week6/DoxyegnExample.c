/**
 * @file main.c
 * @author Your Name
 * @date July 23, 2023
 * @brief A simple program to demonstrate the use of Doxygen.
 *
 * Detailed description starts here.
 * This program has two functions, add and distance, as well as a Point struct.
 * All of these elements are documented with Doxygen comments.
 */

#include <stdio.h>
#include <math.h>

/**
 * @defgroup group1 The Point Struct
 * This is Group 1
 * @{
 */

/** 
 * @struct Point
 * @brief Struct representing a point in 2D space.
 *
 * This structure is used throughout the program to represent points.
 */
typedef struct {
    int x; ///< The x-coordinate.
    int y; ///< The y-coordinate.
} Point;

/** @} */ // end of group1

/**
 * @defgroup group2 The Functions
 * This is Group 2
 * @{
 */

/** 
 * @brief Adds two integers.
 * 
 * This function adds the integer @p a and the integer @p b.
 *
 * @param a The first integer to add.
 * @param b The second integer to add.
 * @return The sum of a and b.
 * @see distance()
 */
int add(int a, int b) {
    return a + b;
}

/** 
 * @brief Calculates the distance between two points in 2D space.
 * 
 * This function calculates the Euclidean distance between the point @p p1 and the point @p p2.
 * It uses the formula sqrt((x2-x1)^2 + (y2-y1)^2).
 *
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The distance between p1 and p2.
 * @see add()
 */
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/** @} */ // end of group2

/** 
 * @brief The main function of the program.
 * 
 * The main function calls the add and distance functions and prints their results.
 * @return Exit status.
 */
int main() {
    /** @brief Define two points */
    Point p1 = {0, 0};
    Point p2 = {3, 4};

    /** @brief Add two numbers and print the result */
    int result = add(2, 3);
    printf("2 + 3 = %d\n", result);

    /** @brief Calculate the distance between two points and print the result */
    double dist = distance(p1, p2);
    printf("The distance between p1 and p2 is %f\n", dist);

    return 0;
}
