#ifdef __cplusplus
 extern "C" {
#endif
#include <stdio.h>
//  also get math function
#include <math.h>
#include <string.h>    // for strlen (ONLY)
#include <stdlib.h>    // for random()


// Define constants
#define CARD_ERROR (unsigned char) 0xFF  // a value that cannot be a card
#define N_DECK 52                        // standard # of cards in a deck

// data types
typedef int           shuffle;

/***********************************************************************
                      Function prototypes
**************************************************************************/
/*******************  Prototypes for printing functions  *********************/
void print_int(int);
void print_usi(unsigned int);
void print_newl();
void print_str(const char*);
void print_chr(char);
void print_dble(double);

/*******************  Prototypes for Problem 1 functions  ********************/
void count(int);              // prob 1.1
void sums_and_squares1(int);  // prob 1.2 
void sums_and_squares2(int);  // prob 1.3
char* length_pad(char*, char*, int); // prob 1.4
void sums_and_squares3(int);  // prob 1.4

/*******************  Prototypes for Problem 2 functions  ********************/
int randN(int);                             // 2.1
void fill(shuffle[N_DECK][2]);              // 2.1
unsigned char convert(int card, int suit);  // 2.2
int valid_card(unsigned char card);         // 2.2
int gcard(unsigned char card);              // 2.2
int gsuit(unsigned char card);              // 2.2
void names(int n, int j, char *answer);     // 2.3

/*******************  Prototypes for Problem 3 functions  ********************/
void deal(int M, unsigned char hand[7], shuffle deck[N_DECK][2]);    // 3.2
void printhand(int M, unsigned char* hand, char* buff1);
int trip_s(int M, unsigned char hand[]);
int four_kind(int M, unsigned char hand[]);
int pairs(int M, unsigned char hand[]);

#ifdef __cplusplus
}
#endif