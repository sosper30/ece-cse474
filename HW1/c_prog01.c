/*c_prog01.c
 *
 *      ECE474 introductory C programming assignment Part1
 *
 *     Student Name: ____
 *     Student ID#:  _____
 *
 */

/*  Objectives:
       Gain experience and proficiency with C programming.


Format of assignment:
1)  Enter your name into the space above
2)  Read through the comments below and edit code into this file to solve the 
    problems.
3)  Check your results against posted solution
4)  Upload this file only (c_prog01.c) to Canvas

Printing:   Use the following functions to print:
  print_int(int x)                prints out an integer
  print_usi(unsigned int x)       prints out an unsigned int
  print_newl()                    prints a "newline" character
  print_str(char *x)              prints a string (pointed to by x)
  print_dble(double)              prints out a double precision floating point number
*/

#include "c_prog1.h"

/**********************************************************************
                 All variable declarations
**********************************************************************/

int i,j,k,l;      // these make good loop iterators.
int card, suit;

// Part 1.2
int t1, t2;

// Part 1.4
// HINT: Does this need to be modified?
char* st_buffer;

// Part 2.0
shuffle cards[N_DECK][2];

//  Part 2.2
unsigned char testhand[7]={0};

// Part 3.1
char * card_names[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen",
                        "King"};
char * suit_names[]={"Hearts","Diamonds","Clubs","Spades"};

// Part 3.2
int dealer_deck_count = 0;  // how many cards have been dealt from a deck

/******************************************************************************
 * 1.1  Write code to print out integers between 1 and N on separate lines
 *      
 *      SAMPLE OUTPUT:
 *       1 
 *       2 
 *       3 
 *       (continued)...
 *****************************************************************************/

void count(int N){
    // YOUR CODE HERE ...
}

/******************************************************************************
 * 1.2  Write code to print out integers between 1 and N on separate lines
 *      
 *      SAMPLE OUTPUT:
 *       1 
 *       2 
 *       3 
 *       (continued)...
 *       [sum(1,2,3 ... N)] [sum(1^2,2^2,3^2 ... N^2)]
 *****************************************************************************/

void sums_and_squares1(int N){   
    t1 = 0 ; t2 = 0;

    // YOUR CODE HERE ...

    print_int(t1) ;  print_int(t2) ;   print_newl();
}

/******************************************************************************
 * 1.3  Write code to print out integers between 1 and N on separate lines
 *      
 *      SAMPLE OUTPUT:
 *      sum: [sum(1,2,3 ... N)] 
 *      sum of squares: [sum(1^2,2^2,3^2 ... N^2)] 
 *****************************************************************************/
void sums_and_squares2(int N){
    char *l1;
    char *l2;

    // YOUR CODE HERE ...
}

/******************************************************************************
 * 1.4  Write a function, char* length_pad(char *st, char* st_buffer, int n), 
 *      which takes a string and adds the right amount of spaces so that it's 
 *      length is n. It should return a pointer the new string.  If the length 
 *      of st is greater than n, truncate the string. 
 *      Note: Check the variable definitions above.
 * 
 *      Modify 1.3 to use length_pad() so that the numbers are all starting in 
 *      col 21 (i.e. all labels have length 20). 
 *     
 *      SAMPLE OUTPUT:
 *      sum:               [sum(1,2,3 ... N)] 
 *      sum of squares:    [sum(1^2,2^2,3^2 ... N^2)]
 *****************************************************************************/

char* length_pad(char *st, char* st_buffer, int n) {
    
    // YOUR CODE HERE ...

    return st_buffer;
}

void sums_and_squares3(int N){
    char *l1;
    char *l2;

    // YOUR CODE HERE ...

    print_str(length_pad(l1,st_buffer, 20)) ; print_int(t1) ; print_newl();
    print_str(length_pad(l2,st_buffer, 20)) ; print_int(t2) ; print_newl();
}



/******************************************************************************
 * 2.1 A 'shuffle' is an array of N_DECK pairs of integers. The first of the 
 *     pair is the card type (0-13 representing ace, 2, 3, .... King) and the 
 *     second representing the suit (hearts, diamonds, clubs, spades).   Thus a 
 *     pair of numbers (1-13)(1-4) describes a unique card in the deck.
 * 
 *     Write a function to fill a shuffle with N_DECK random integer pairs, 
 *     BUT, as with your playing cards, there must be EXACTLY one of each pair 
 *     in the shuffle. Use your function to print out all the "cards" of the 
 *     shuffle, with 7 cards per line.
 * 
 *     To generate a random number use the helper function int randN(int n)
 *     defined at the bottom of this file that returns a random integer between 
 *     1 and N.
 *
 *     SAMPLE OUTPUT:
 [ 11   2 ]  [ 11   4 ]  [ 12   1 ]  [ 5   4 ]  [ 4   3 ]  [ 7   3 ]  [ 5   3 ] 
 [ 13   4 ]  [ 9   3 ]  [ 2   3 ]  [ 1   1 ]  [ 2   4 ]  [ 3   2 ]  [ 2   1 ] 
 [ 13   1 ]  [ 7   4 ]  [ 8   2 ]  [ 4   4 ]  [ 6   4 ]  [ 4   2 ]  [ 1   4 ] 
 [ 7   1 ]  [ 3   3 ]  [ 12   2 ]  [ 6   1 ]  [ 12   4 ]  [ 13   3 ]  [ 9   2 ] 
 [ 9   1 ]  [ 3   4 ]  [ 9   4 ]  [ 10   2 ]  [ 4   1 ]  [ 8   1 ]  [ 1   3 ] 
 [ 3   1 ]  [ 11   3 ]  [ 8   4 ]  [ 10   3 ]  [ 5   1 ]  [ 10   1 ]  [ 13   2 ] 
 [ 11   1 ]  [ 7   2 ]  [ 6   3 ]  [ 8   3 ]  [ 12   3 ]  [ 2   2 ]  [ 5   2 ] 
 [ 1   2 ]  [ 10   4 ]  [ 6   2 ]
 *****************************************************************************/

void fill(shuffle deck[N_DECK][2]) {
    
    // YOUR CODE HERE ...
    
}

/******************************************************************************
 * 2.2 A 'hand' is an array of seven unsigned chars.  Each char represents one 
 *     card.  We use a four bit field in the char for each of the two numbers 
 *     above: the four most significant bits [7...4] represent the card number 
 *     (1-13) and the lower four [3...0] represent the suit.
 * 
 *     Write functions to:  
 *     a) Convert two integers (from  a shuffle for example) into a char as 
 *        above. If the ints are invalid (e.g. convert(294802984,138142) is not 
 *        a card) return CARD_ERROR
 *     b) Test if a char equals a valid integer pair
 *     c) Get the integer suit from a char
 *     d) Get the integer card from a char
 * 
 *     Both functions a and b must return CARD_ERROR if they get invalid input 
 *     (such as suit > 4).
 * 
 *     Write code for the functions convert(), valid_card(), gcard(), and 
 *     gsuit() below.
 *****************************************************************************/
unsigned char  convert(int card, int suit) {
   
    // YOUR CODE HERE ...

    return 0;
}

// Test if a card byte is a valid card
int valid_card(unsigned char card){
    
    // YOUR CODE HERE ...

    return 1;
}
// your code for gsuit and gcard here

int gcard(unsigned char card) {
    
    // YOUR CODE HERE ...
    
    return 1;
}

int gsuit(unsigned char card) {
    
    // YOUR CODE HERE ...
    
    return 1;
}

/******************************************************************************
 * 3.1 Write a function names(int card, int suit, char answer[]) which places a 
 *     string of the name and suit of a card in the array answer[]. For 
 *     example: name(11,1) → “Jack of Hearts” name(8,2) → “8 of Diamonds”. Use 
 *     the arrays defined above card_names[] and suit_names[]
 *     
 *     Hint: Use pointers to copy the characters one-by-one into the array 
 *     answer[] to build up the final string.
 *****************************************************************************/

void names(int card, int suit, char *answer) {
    
    // YOUR CODE HERE ...

}

/******************************************************************************
 * 3.2 Write a function to deal a hand of M (0<M<8) cards from a shuffle. Use a 
 *     global variable int dealer deck count to keep track of how many cards 
 *     have been dealt from the deck.
 * 
 *     To test this write a function printhand() that prints out a hand of 
 *     cards
 *     
 *     SAMPLE OUTPUT:
 * 
 *     ----testing deal: hand:  0 
 *     Deck count:  0 
 *     --------dealt hand: 
 *     the hand: 
 *         Jack of Diamonds
 *         Jack of Spades
 *         Queen of Hearts
 *         5 of Spades
 *         4 of Clubs
 *         7 of Clubs
 *         5 of Clubs
 * 
 *****************************************************************************/

void deal(int M, unsigned char hand[7], int deck[N_DECK][2]) {
    
    // YOUR CODE HERE ...

}

void printhand(int M, unsigned char* hand, char* buff1) {
    
    // YOUR CODE HERE ...

}

/******************************************************************************
 * 3.3 Write functions to identify pairs of cards in a hand (two cards with the
 *     same number), three-of-a-kind (three cards with the same number), and 
 *     four-of-a-kind (four cards with the same number).
 *****************************************************************************/
int pairs(int M, unsigned char hand[]) {
    
    // YOUR CODE HERE ...

    return 0;
}

int trip_s(int M, unsigned char hand[]) {
    
    // YOUR CODE HERE ...

    return 0;
}

int four_kind(int M, unsigned char hand[]) {
  
    // YOUR CODE HERE ...

    return 0;
}

//  Predefined helper function to return a random integer between 1 and n
int randN(int n) { 
    double x;
    x = 1.0 + (double) n * rand() / RAND_MAX;
    return((int)x);
}