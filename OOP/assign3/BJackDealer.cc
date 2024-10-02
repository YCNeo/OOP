/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
    BJackDealer.cc
    PURPOSE

  NOTES

  AUTHOR
    Tsai-Yen Li (li@cs.nccu.edu.tw)
  HISTORY
    Tsai-Yen Li - Oct 12, 1998: Created.
 ***************************************************************************/

/* $Log:$ */

extern "C" {
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;

#include <iostream>
#include <vector>

#include "AnsiPrint.h"
#include "BJackDealer.h"
#include "BJackPlayer.h"
#include "Card.h"
#include "CardPat.h"

int PlusRand(int nSet) {
    return rand() % (nSet * kMaxNCards);
}

inline int Min(int i, int j) {
    return (i < j) ? i : j;
}

// constructor
// nDeck is the number of standard decks that the dealer will deal with
BJackDealer::BJackDealer(int nSet) : num_Set(nSet) {
    CardRoutineInit();
}

// distribute a card to the player
int BJackDealer::giveCard() {
    return CardRoutine[0];
}

// give the dealer one card unconditionally
void BJackDealer::addCard() {
    Card newCard(CardRoutine[0]);
    if (nCards < kMaxCards)
        cards[nCards++] = newCard;
    RemoveUsed();
}

// give the dealer as many cards as necessary to exceed the player
// of the given total points
// A special case happen when both of them have 21 points.
// It is a tie game and therefore the dealer does not get more cards.

void BJackDealer::addCards(int oppTotal) {
    while (1) {
        if (totalPoints() < 17)
            addCard();
        else if (totalPoints() < oppTotal && oppTotal <= 21)
            addCard();
        else
            break;
    }
}

int BJackDealer::totalPoints(void) const {
    int total = 0;
    int point;
    int credit = 0;

    for (int i = 0; i < nCards; i++) {
        point = cards[i].getPip() + 1;
        if (point == 1) {
            credit++;
        } else if (point > 10)
            point = 10;
        total += point;
    }

    // add points depending on how many aces we have
    for (int i = 0; i < credit; i++) {
        if (total + 10 <= 21) {
            total += 10;
        } else {
            break;
        }
    }

    return total;
}

// Determine who has win the game.
// The total points that the dealer has should be greater than
// the player at the point this function is called.

result BJackDealer::judge(int oppTotal, int betCredit) {
    int point = totalPoints();
    if ((point > 21 && oppTotal > 21) || (point == oppTotal)) {
        cout << "It's a Tie.(You have " << Loan_P << " Credits, I have "
             << Loan_D << " Credits.)" << endl;
    } else if ((point > 21 && oppTotal <= 21) ||
               (point < oppTotal && oppTotal <= 21)) {
        Loan_D -= betCredit;
        Loan_P += betCredit;
        cout << "You win. Good job.(You have " << Loan_P << " Credits, I have "
             << Loan_D << " Credits.)" << endl;
    } else if ((point <= 21 && oppTotal > 21) ||
               (point > oppTotal && point <= 21)) {
        Loan_D += betCredit;
        Loan_P -= betCredit;
        cout << "I win. Try again.(You have " << Loan_P << " Credits, I have "
             << Loan_D << " Credits.)" << endl;
    }

    // judge whether run is continue
    if (Loan_D == 0 || Loan_P == 0)
        return ::tie;
    return win;
}

// start a new game
// before starting a new game, check if there are enough cards left for
// the next game.

void BJackDealer::start(int initLoan) {
    if ((int)CardRoutine.size() < (num_Set * 17))
        CardRoutineInit();

    // initialize loan
    if (Loan_D == Loan_P && Loan_D == 0)
        Loan_D = Loan_P = initLoan;
}

void BJackDealer::CardRoutineInit() {
    // clear CardRoutine
    CardRoutine.clear();

    // reassign the CardRoutine
    for (int i = 0; i < num_Set; i++)
        for (int j = 0; j < kMaxNCards; j++)
            CardRoutine.push_back(j);

    // shuffle
    shuffle();
}

// shuffle the deck of cards
void BJackDealer::shuffle(void) {
    int count = 0;
    while (count < num_Set * 300) {
        int curr = PlusRand(num_Set), NEXT = PlusRand(num_Set);
        if (curr == NEXT) {
            if (curr == num_Set * kMaxNCards - 1)
                NEXT = 1;
            else
                NEXT = curr + 1;
        }
        swap(CardRoutine[curr], CardRoutine[NEXT]);
        ++count;
    }
}

// reset the seed before shuffling
void BJackDealer::shuffle(long seed) {}

// open the dealer's first card
void BJackDealer::openFirstCard(void) {
    showAll = true;
}

// show the dealer's hand to the screen
void BJackDealer::showCards(void) const {
    unsigned char s, p;
    char line[kCardWidth + 1];
    int curCard = 0, lastCard;

    while (curCard < nCards) {
        for (int i = 0; i < kCardHeight; i++) {
            lastCard = Min(curCard + kNCardPerRow, nCards);
            if (i < (int)strlen(name)) {
                cout << name[i] << " ";
            } else {
                cout << "  ";
            }
            for (int j = curCard; j < lastCard; j++) {
                s = cards[j].getID() % kNSuit;
                p = cards[j].getID() / kNSuit;
                if ((j == 0) && (showAll == false))
                    p = 13;
                for (int k = 0; k < kCardWidth; k++) {
                    line[k] = card[p][i][k];
                    if (line[k] == 'x')
                        line[k] = cardAbbrev[s];
                }
                line[kCardWidth] = '\0';
                AnsiPrint(line, cardColor[s], white);
                cout << " ";
            }
            cout << endl;
        }
        curCard = lastCard;
    }
}

void BJackDealer::RemoveUsed(void) {
    CardRoutine.erase(CardRoutine.begin());
}

void BJackDealer::initialize(void) {
    nCards = 0;
    showAll = false;
}