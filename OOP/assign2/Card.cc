/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Card.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 5, 1998: Created.
***************************************************************************/

/* $Log: Card.cc,v $
 * */

using namespace std;
#include <iostream>
#include <assert.h>
#include "AnsiPrint.h"
#include "CardPat.h"
#include "Card.h"
#include "BJackPlayer.h"


// constructor
Card::Card() {

}


// Accessor: card id is an integer between 0 and 51.
// Cards of the same pips are together.
// In other words, cards are in the following order:
//    1S 1H 1D 1C 2S 2H ...

int Card::getUnit(int num, int x, int y) const {
  if(num == -1) return card[13][x][y];
  
  if(card[Card::getPip(num)][x][y] == 'x')
    return Card::getSuit(num);
  return card[Card::getPip(num)][x][y];
}

// get the pip of the card (0-12)
int Card::getPip(int PipNum) const {
  if(PipNum <= 13) return PipNum - 1;
	else if(PipNum <= 26 && PipNum > 13)  return PipNum%13 - 1;
	else if(PipNum <= 39 && PipNum > 26)  return PipNum%26 - 1;
	return PipNum%39 - 1;
}

// get the suit of the card (0-3)
int Card::getSuit(int SuitNum) const {
  if(SuitNum <= 13) return 'C';
	else if(SuitNum <= 26 && SuitNum > 13)  return 'D';
	else if(SuitNum <= 39 && SuitNum > 26)  return 'H';
	return 'S';
}

// modifier: set id directly
void Card::setID(int newId) {

}

// print the suit name and face value of the card
void Card::print(int PrintArr[], bool faceUP, int count, int which_row) const {
  for(int height = 0; height < 11; height++){
    char tempName[11] = {'B','J','P','l','a','y','e','r',' ',' ',' '};
    printf("%c ", tempName[height]);

    for(int row_num = 0; row_num < count; row_num++){
      for(int width = 0; width < 11; width++){
        if(faceUP == false && which_row == 1) PrintArr[0] = -1;

        char *output = new char[256];
        sprintf(output, "%c", static_cast<char>(Card::getUnit(PrintArr[row_num], height, width)));
        if(PrintArr[0] == -1)
          AnsiPrint(output, red, white, true, false);
        else if(Card::getSuit(PrintArr[row_num]) == 'H' || Card::getSuit(PrintArr[row_num]) == 'D')
          AnsiPrint(output, red, white, true, false);
        else if(Card::getSuit(PrintArr[row_num]) == 'S' || Card::getSuit(PrintArr[row_num]) == 'C')
          AnsiPrint(output, black, white, false, false);
      }
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}
