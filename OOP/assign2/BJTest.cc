/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJTest.cc
   PURPOSE
     Homework assignment for simulating card game
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 5, 1998: Created.
	 Ming-Te Chi - Oct 1, 2023: revised.
***************************************************************************/

/* $Log: BJTest.cc,v $
 * */

extern "C" {
  #include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackPlayer.h"

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

// Print my id
void PrintMyID(const char* studId) {

	char* str = new char[sizeof(studId)+5];
	sprintf(str, "ID: %s", studId);
	AnsiPrint(str, yellow, red, true, true);
	cout << endl << endl;
	delete [] str;

}


//  PrintUsage
void PrintUsage(const char* progName) {

	assert(progName);
	cout << "Usage: " << progName << " [Seed] [ShowFirst(0/1)]" << endl;

}

//  Main Function Call


int main(int argc, char **argv) {
  bool showFirst = false;
  long seed = 0;

  if (argc==3) {
	  showFirst = atoi(argv[2]); // the third argument shows the first card
    seed = atoi(argv[1]);
	} 
  else if (argc>1)
    seed = atoi(argv[1]);
  else {
    PrintUsage(argv[0]);
		exit(-1);
	}

  srand(seed);

  BJackPlayer bjplayer("BJPlayer");

  // put your code here
  for(int i = 0; i < 52; ++i) CardRoutine[i] = i+1;

  Neo_shuffle(curr, NEXT);
  
  bjplayer.start(CardRoutine, showFirst);
  
  PrintMyID("110703013");
    
  return 0;
}

