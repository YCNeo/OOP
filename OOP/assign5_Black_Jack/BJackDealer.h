/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  BJackDealer.h
  PURPOSE
  class for simulating the dealer in a Black Jack card game
  NOTES
  You need to add some private stuff in this file.
  AUTHOR
  Tsai-Yen Li (li@cs.nccu.edu.tw)
  HISTORY
  Tsai-Yen Li - Oct 12, 1998: Created.
 ***************************************************************************/

/* $Log:$ */

#ifndef _BJACKDEALER_H
#define _BJACKDEALER_H

#include <string.h>
#include <vector>

#include "BJackPlayer.h"
#include "Card.h"

using namespace std;

// number of cards in a standard deck
const int kMaxNCards = 52;
// result of a game
enum result { tie, win, lose };

// foreward declaration of class PokerPlayer
class BJackPlayer;

/**
 * The Dealer class simulate the dealer in a poker game.
 * It is responsible for
 * 1. shuffling the cards,
 * 2. draw and distribute a hand to a player and
 * 3. check if there is enough cards left for user request
 */

class BJackDealer : public BJackPlayer {
    public:
        /**
         * constructor:
         * nSet is the number of decks of cards that you want the dealer
         * to handle
         */
        BJackDealer(int nSet = 1);

        /**
         * return a valid card ID to the player
         */
        int giveCard(void);

        /**
         * Give myself (the dealer) more cards in order to win the player
         * Input argument is the current points that the player has.
         */
        void addCards(int oppTotal);

        /**
         * Determine who has won the game
         * Input argument is the current points that the player has.
         */
        result judge(int curOppTotal, int betCredit);

        /**
         * starting a new game
         */
        void start(int initLoan);

        /**
         * retain the whole set of cards and shuffle
         */
        void shuffle(void);

        /**
         * same as shuffle except for using a different seed for RNG
         */
        void shuffle(long seed);

        /*
         * initialize the Card Routine
         */
        void CardRoutineInit(void);

        /*
         * Pop the first one
         */
        void RemoveUsed(void);

    private:
        // TODO: your private or internal stuff goes here ...
        vector<int> CardRoutine;

        int num_Set;

        int Loan_P = 0;
        int Loan_D = 0;
};

#endif        // _BJACKDEALER_H
