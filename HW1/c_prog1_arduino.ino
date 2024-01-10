#include <stdio.h>
//  also get math function
#include <math.h>
#include <string.h>    // for strlen (ONLY)
#include <stdlib.h>    // for random()

#include "c_prog1.h"

//  Random number seed.
int seed = 100;

// Variables defined in c_prog1
extern int i, j, k, l;
extern int card, suit;
extern int t1, t2;
extern char* st_buffer;
extern shuffle cards[][2];
extern unsigned char testhand[];
extern char card_names[];
extern char suit_names[];
extern int dealer_deck_count;

/*******************  Prototypes for printing functions  *********************/
void print_int(int);
void print_usi(unsigned int);
void print_newl();
void print_str(const char*);
void print_chr(char);
void print_dble(double);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  randomSeed(seed);

  print_str("Random seed: "); print_int(seed); print_newl();
  print_str("Problem 1.1 Test Results: \n");
  count(10);

  print_str("Problem 1.2 Test Results: \n");
  sums_and_squares1(10);

  print_str("Problem 1.3 Test Results:\n");
  sums_and_squares2(10);

  print_str("Problem 1.4 Test Results: \n");
  sums_and_squares3(10);

  print_str("Problem 2.1 Test Results: "); print_newl();

  fill(cards);

  // Print out the random cards.
  for (i = 0; i < N_DECK; i++) {
    print_str(" [");
    print_int(cards[i][0]); print_str(" "); print_int(cards[i][1]) ;
    print_str("] ");
    if (!((i + 1) % 7)) print_newl();
  }
  print_newl();

  print_str("Problem 2.2  Test Results: ");  print_newl();

  //  Write your convert() function (2.2.a) below
  print_str("   2.2.a"); print_newl();

  // To test, lets fill a hand up with some cards:
  testhand[0] = convert(5, 2);
  testhand[1] = convert(15, 2); // Oops!   15 is invalid card #
  testhand[2] = convert(12, 1);
  testhand[3] = convert(6, 3);
  testhand[4] = convert(-1, 7); // Hey!  both -1 and 7 are invalid
  testhand[5] = convert(10, 4);
  testhand[6] = convert(3, 3);

  // Let's check them carefully!
  for (i = 0; i < 7; i++) {
    if (testhand[i] == CARD_ERROR) {
      print_str(" check 1 card error: ");
      print_int(i);
      print_newl();
    }
  }

  // New test hand
  testhand[0] = convert(1, 1); // Ace of Hearts
  testhand[1] = convert(1, 2); // Ace of Diamonds
  testhand[2] = convert(1, 3); // Ace of Clubs
  testhand[3] = convert(1, 4); // Ace of Spades
  testhand[4] = convert(11, 2); // Jack of Diamonds
  testhand[5] = convert(12, 2); // Queen of Diamonds
  testhand[6] = convert(13, 4); // King of Spades

  int i;
  for (i = 0; i < 7; i++) {
    if (testhand[i] == CARD_ERROR) {
      print_str(" check 2 card error: ");
      print_int(i); print_newl();
      exit(0);
    }
  }

  //  Test 2.2.c
  print_str("   2.2.b"); print_newl();

  unsigned char card1, card2;

  card1 = 0xFF;  // an invalid card
  card2 = convert(1, 4); // ace of spades

  if (valid_card(card1) == CARD_ERROR)
    print_str(" 0xFF is not a valid card\n");
  else print_str(" Somethings wrong with 2.2.b\n");
  if (valid_card(card2) == CARD_ERROR)
    print_str(" Somethings wrong with 2.2.b\n");
  else print_str("8-bit version of Ace of Spades is a VALID card.\n");

  //  Test 2.2.c
  print_str("   2.2.c,d"); print_newl();

  for (i = 0; i < 7; i++) {
    int card = gcard(testhand[i]);  //  This part tests 2.2c,d
    int suit = gsuit(testhand[i]);
    print_str("card: "); print_int(card);
    print_str("   suit: "); print_int(suit);
    print_newl();
  }
  char buffer[] = "   *empty*       ";

  print_str("Part 3.1 Test Results:"); print_newl();

  for (i = 0; i < 7; i++) {
    card = gcard(testhand[i]);  // This part tests 2.2c,d
    suit = gsuit(testhand[i]);
    print_str(" >>>>");
    print_int(i); print_str(": "); print_int(card); print_int(suit) ;
    names(card, suit, buffer); // convert card,suit to string name in buffer
    print_str(buffer);
    print_newl();
  }
  print_newl();

  /*
         Test Part 3.2
  */

  print_str("Part 3.2 Test Results:"); print_newl();
  print_str("Test the deal() function\n");
  char buff[20] = "";
  for (i = 0; i < 3; i++) {
    print_str("\n\n----testing deal: hand: "); print_int(i); print_newl();
    print_str("Deck count: "); print_int(dealer_deck_count); print_newl();
    deal(7, testhand, cards); // see Prob 2.1 for "cards"
    print_str("--------dealt hand: \n");
    printhand(7, testhand, buff);
    print_newl();
  }


  /*
         Test Part 3.3
  */

  print_str("Part 3.3 Test Results:"); print_newl();
  print_str("Test the finding pokerhands function(s).\n");
  unsigned char hands[10][7];   //array of 10 hands


  dealer_deck_count = 0; // reset to full deck (hands should reappear)

  int n_hands = 7;

  for (i = 0; i < n_hands; i++) {
    deal(7, hands[i], cards);
  }
  print_str(" I have "); print_int(n_hands); print_str(" new hands\n");
  for (i = 0; i < n_hands; i++) {
    int pct = pairs(7, hands[i]);
    int trips = trip_s(7, hands[i]);
    int fourk = four_kind(7, hands[i]);
    print_str("I found"); print_int(pct); 
    print_str("pairs in hand"); print_int(i); print_newl();
    
    print_str("I found"); print_int(trips); 
    print_str("three-of-a-kinds in hand"); print_int(i); print_newl();
    
    print_str("I found"); print_int(fourk); 
    print_str("four-of-a-kinds in hand"); print_int(i);print_newl();
    
    print_str("Hand"); print_int(i);
    printhand(7, hands[i], buff);
    print_newl();
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}

/**************************************************************************
  simplified I/O and other functions for this assignment
***************************************************************************/
void print_int(int x) {
  Serial.print(" "); Serial.print(x); Serial.print(" ");
}

void print_usi(unsigned int x) {
  Serial.print(" "); Serial.print(x);
}

void print_dble(double x) {
  Serial.print(" "); Serial.print(x);
}

void print_newl() {
  Serial.println();
}

void print_str(const char *x) {
  Serial.print(x);
}

void print_chr(char x) {
  Serial.print(x);
}