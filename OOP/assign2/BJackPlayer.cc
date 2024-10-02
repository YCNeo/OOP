/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackPlayer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct. 5, 1998: Created.
***************************************************************************/

/* $Log: BJackPlayer.cc,v $
 * */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <iostream>
#include <vector>
#include "AnsiPrint.h"
#include "CardPat.h"
#include "BJackPlayer.h"
#include "Card.h"

// default constructor: simply initialize the number of cards to 0

BJackPlayer::BJackPlayer(char *player_name) {
  Player_NAME = player_name;
}

// start the black jack game with a new card
void BJackPlayer::start(int arr[], bool ShowFirst) {
  for(int i = 0; subtotal <= 21 && i < 10; i++){
    subtotal = totalPoints(arr[i]);
    hand_arr.push_back(arr[i]);
  }
  BJackPlayer::showCards(hand_arr, ShowFirst);
}

// add a new card to the current hand.
// need to protect the array from overflowing
void BJackPlayer::addCard(Card newCard) {

}

// get the total points of the current hand in a black jack game
// cards with face vaules above 10 are treated as 10
// Ace's can be treated as 1 or 11 points

int BJackPlayer::totalPoints(int num) const {
  if(num <= 13){
    if(num >= 10)  return subtotal + 10;
    else  return subtotal + num;
  }
	else if(num <= 26 && num > 13){
    num = num%13;
    if(num >= 10)  return subtotal + 10;
    else  return subtotal + num;
  }
	else if(num <= 39 && num > 26){
    num = num%26;
    if(num >= 10)  return subtotal + 10;
    else  return subtotal + num;
  }
	else{
    num = num%39;
    if(num >= 10)  return subtotal + 10;
    else  return subtotal + num;
  }
}

// set the status of the first card

void BJackPlayer::openFirstCard() {

}

// print the current hand to the screen graphically

void BJackPlayer::showCards(vector<int> SC_arr, bool faceUP) const {
  Card np;
  int row, remainders;
  if(SC_arr.size() > 5){
    row = 2;
    remainders = SC_arr.size()%5;
  }
  else{
    row = 1;
    remainders = SC_arr.size();
  }

  for(int i = 0; i < row; i++){
    int ToPrint_arr[5] = {};
    if(i == 0 && row == 2){
      for(int j = 0; j < 5; j++)
        ToPrint_arr[j] = SC_arr[j];
      
      np.print(ToPrint_arr, faceUP, 5, i);
    }
    else if(i == 1 && row == 2){
      for(int j = 0; j < remainders; j++)
        ToPrint_arr[j] = SC_arr[j + 5];
      
      np.print(ToPrint_arr, faceUP, remainders, row);
    }
    else if(i == 0 && row == 1){
      for(int j = 0; j < remainders; j++)
        ToPrint_arr[j] = SC_arr[j];
      
      np.print(ToPrint_arr, faceUP, remainders, row);
    }
  }
  cout << "Total points: " << subtotal << endl;
}

