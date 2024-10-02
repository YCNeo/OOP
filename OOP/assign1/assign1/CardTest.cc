/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
}

#include <iostream>
#include <algorithm>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

int CardRoutine[52] = {0};	
int curr = 0, NEXT = rand()%52;

int PlusRand(int x){
	x += rand()%52;
	x = x%52;
	return x;
}

/*
 *	shuffle the 52 cards
 */
void Neo_shuffle(int curr, int NEXT){
	int count = 0;
	while(count < 100){
		if(curr == NEXT)	NEXT = curr+1;
    	curr = PlusRand(curr);
		  NEXT = PlusRand(NEXT);
		
    	swap(CardRoutine[curr], CardRoutine[NEXT]);
		
		++count;
	}
}


/**
 * Print my id 
 */
void PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  // we put string in a buffer first 
  sprintf(str,"ID: %s",studId);
  // print the buffer out with color
  AnsiPrint(str, yellow, red, true, true);
  cout << endl << endl;
  delete [] str;

}


/**
 * PrintUsage
 */
void PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " NCards [Seed]" << endl;

}


/**
 * Main Function Call
 */
int main(int argc, char **argv) {

  int ncards=0;  // number of cards to draw 
  if (argc==3) {
    long seed=atoi(argv[2]); // the third argument is the seed
    srand(seed);
    ncards=atoi(argv[1]); // the second argument is the number of cards
  }
  else if (argc==2) {
    ncards=atoi(argv[1]);
  }
  else {
    PrintUsage(argv[0]);
    exit(-1);
  }

  // You are asked to fill in a few missing statements here
  if(ncards > 52){
	  cout << "Sorry, number of cards can not exceed 52."<<endl;
		exit(-1);
  }
  
  
  for(int i = 0; i < 52; ++i) CardRoutine[i] = i+1;
  
  Neo_shuffle(curr, NEXT);
  
  // for(int i = 0; i < 52; ++i)	printf("%d ", CardRoutine[i]);
  // printf("\n");
  PrintPokerCard(ncards, CardRoutine);
  
  // Print my id at the end of the program
  PrintMyID("110703013");
  

  // Wanted Black cards' color: AnsiPrint(str, black, white, false, false);
  // Wanted Red cards' color: AnsiPrint(str, black, white, false, false);


  return 0;

}
