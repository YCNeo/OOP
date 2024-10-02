/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Cards.h
   PURPOSE
     Bitmaps for the poker cards
   NOTES
     Sample solution
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>
#include <string>
#include <iomanip>
#include "AnsiPrint.h"

using namespace std;

const int kNPip=13;
const int kNSuit=4;
const int kNCards=52;
const int kCardWidth=11;
const int kCardHeight=11;

/* 'x's are special characters that will be replaced in printing */
static char card[kNPip][kCardHeight][kCardWidth+1]={{
  "***********",
  "*1x       *",
  "*         *",
  "*         *",
  "*         *",
  "*    x    *",
  "*         *",
  "*         *",
  "*         *",
  "*        1*",
  "***********"
}, {
  "***********",
  "*2x       *",
  "*         *",
  "*    x    *",
  "*         *",
  "*         *",
  "*         *",
  "*    x    *",
  "*         *",
  "*        2*",
  "***********"
}, {
  "***********",
  "*3x       *",
  "*         *",
  "*    x    *",
  "*         *",
  "*    x    *",
  "*         *",
  "*    x    *",
  "*         *",
  "*        3*",
  "***********"
}, {
  "***********",
  "*4x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*         *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        4*",
  "***********"
}, {
  "***********",
  "*5x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*    x    *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        5*",
  "***********"
}, {
  "***********",
  "*6x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        6*",
  "***********"
}, {
  "***********",
  "*7x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x x x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        7*",
  "***********"
}, {
  "***********",
  "*8x       *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*        8*",
  "***********"
}, {
  "***********",
  "*9x       *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*        9*",
  "***********"
}, {
  "***********",
  "*10x      *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*       10*",
  "***********"
}, {
  "***********",
  "*Jx       *",
  "*  xxxxx  *",
  "*     x   *",
  "*     x   *",
  "*     x   *",
  "*     x   *",
  "*  x  x   *",
  "*   xxx   *",
  "*        J*",
  "***********"
}, {
  "***********",
  "*Qx       *",
  "*   xxx   *",
  "*  x   x  *",
  "*  x   x  *",
  "*  x   x  *",
  "*  x  xx  *",
  "*   xxxx  *",
  "*       x *",
  "*        Q*",
  "***********"
}, {
  "***********",
  "*Kx       *",
  "*  x   xx *",
  "*  x  x   *",
  "*  x x    *",
  "*  xx     *",
  "*  x x    *",
  "*  x  x   *",
  "*  x   xx *",
  "*        K*",
  "***********"
}};


int check(int number, int h, int w){
	if(number < 13){
		if(card[number][h][w] == 'x')	return 'C';
		else 	return card[number][h][w];
	}
	else if(number < 26 && number >= 13){
		if(card[number%13][h][w] == 'x')	return 'D';
		else 	return card[number%13][h][w];
	}
	else if(number < 39 && number >= 26){
		if(card[number%26][h][w] == 'x')	return 'H';
		else 	return card[number%26][h][w];
	}
	else if(number < 52 && number >= 39){
		if(card[number%39][h][w] == 'x')	return 'S';
		else 	return card[number%39][h][w];
	}
}


void PrintLayer(int num, int arr_PL[]){	
	for(int height = 0; height < 11; ++height){
		for(int cards_num = 0; cards_num < num; ++cards_num){
			for(int width = 0; width < 11; ++width){
				if(arr_PL[cards_num] > 13 && arr_PL[cards_num] <= 39){
					char *output = new char[256];
					sprintf(output, "%c", static_cast<char>(check(arr_PL[cards_num] - 1, height, width)));
					AnsiPrint(output, red, white, true, false);
				}
				else{
					char *output = new char[256];
					sprintf(output, "%c", static_cast<char>(check(arr_PL[cards_num] - 1, height, width)));
					AnsiPrint(output, black, white, false, false);
				}
			}
			printf(" ");
		}
		printf("\n");
	}
}


void PrintPokerCard(int ncards_Print, int arr_PPC[]){
	// for(int i = 0; i < 52; ++i)		cout << arr_PPC[i] << " ";
	// cout << "\n";

	int row_num, ncards_remainder;
	
	if(ncards_Print < 5)  row_num = 1;
  	else  row_num = (ncards_Print - (ncards_Print%5))/5 + 1;
  
  	ncards_remainder = ncards_Print%5;
	// printf("ncards_Print = %d, row_num = %d, ncards_remainder = %d\n", ncards_Print, row_num, ncards_remainder);

  	int TPL_arr[5] = {0}, counter;
	for(int layer = 1; layer <= row_num; ++layer){	
		if(layer < row_num)		counter = 5;
		else 	counter = ncards_remainder;
		
		for(int count = 0; count < counter; ++count){
			TPL_arr[count] = arr_PPC[(layer-1)*5 + count];
		}
		if(counter != 0)	PrintLayer(counter, TPL_arr);
	}
}

/*
 *	ncards_Print: number of cards
 *	arr[]: shuffled array of cards 
 *	row_num: ex. ncards_Print = 29, then row_num = 6, ncards_remainder = 4
 *	TPL_arr: to_print_layer_array
 *	
 *	layer should be like:
 *	0  1  2  3  4
 *	5  6  7  8  9
 *	10 11 12 13 14
 *	15 16 17 18 19 
 *	20 21 22 23 24 
 *	25 26 27 28
 *
 */
