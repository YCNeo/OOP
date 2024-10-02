/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Card.h
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 5, 1998: Created.
***************************************************************************/

/* $Log: Card.h,v $
 *
 * */

#ifndef _CARD_H
#define _CARD_H

// a few card related constants
const int kNPip = 13;
const int kNSuit = 4;
// total number of cards for a standard deck of poker cards
const int kNCards = 52;
// four different suit names
const char* const suitName[] = { "spade", "heart", "diamond", "club" };
// data for use with the card printing
const char cardAbbrev[] = "SHDC";
// data for use with the card printing
const color cardColor[] = {black, red, red, black};
// maximal number of cards to be print in a row before wrapping
const int kNCardPerRow = 5;
// suit types
enum suit {spare, heart, diamond, club};

class Card {

public:
    // Constructor
    Card();
    
    // accessors
    int getUnit(int num, int x, int y) const;
    int getPip(int PipNum) const; 
    int getSuit(int SuitNum) const;
    
    // modifiers
    void setID(int newid);
    
    // print the face value and suit of the card
    void print(int PrintArr[], bool faceUP, int count, int which_row) const;

private:

    // your private or internal stuff goes here
    
};

#endif
