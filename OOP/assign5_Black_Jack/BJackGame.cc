/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  BJackGame.cc
  PURPOSE

  NOTES

  AUTHOR
  Tsai-Yen Li (li@cs.nccu.edu.tw)
  HISTORY
  Tsai-Yen Li - Oct 12, 1998: Created.
 ***************************************************************************/

/* $Log:$ */

#include "BJackGame.h"

#include <iostream>
#include <vector>

#include "AnsiPrint.h"
#include "BJackDealer.h"
#include "BJackPlayer.h"
#include "Card.h"
#include "ConsoleMenu.h"

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
BJackGame::BJackGame(BJackPlayer& bjp, BJackDealer& bjd)
    : menu(sizeof(menuItems) / sizeof(char*), menuItems),
      bjplayer(bjp),
      bjdealer(bjd) {}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool BJackGame::oneRun() {
    menu.print();                         // output choices
    int choice = menu.getAnswer();        // input choice

    // The dealer deals the cards and loans
    bjdealer.start(initCredit);

    switch (choice) {
        case 1:
            moreCard();
            break;
        case 2:
            enough();
            break;
        case 3:
            restart();
            break;
        case 4:
            quit();
            return IsContinue;
        default:
            break;
    }

    bjplayer.openFirstCard();
    bjplayer.showCards();
    bjdealer.showCards();

    return IsContinue;
}

// give the player one more card
// check if we can do that first
void BJackGame::moreCard() {
    if (IsOver)
        cout << "Game Over" << endl;
    else {
        int now = bjplayer.totalPoints();
        if (now > 21)
            cout << "You are over 21 already" << endl;
        else {
            Card temp(bjdealer.giveCard());
            bjplayer.addCard(temp);
            bjdealer.RemoveUsed();
        }
    }
}

// give the dealer enough cards to try to win the player
// determine who win the game at the end
void BJackGame::enough() {
    if (IsOver)
        cout << "Game Over" << endl;
    else {
        IsOver = true;
        bjdealer.openFirstCard();
        bjdealer.addCards(bjplayer.totalPoints());
        HaveLoan = bjdealer.judge(bjplayer.totalPoints(), betCredit);
    }
}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void BJackGame::restart() {
    if (!IsOver)
        cout << "Game is not over yet. Choose 'enough' to end a game" << endl;
    else if (!HaveLoan)
        cout << "Sorry. Game over. No loan here." << endl;
    else {
        bjdealer.BJackPlayer::start();        // bjdealer initializes
        bjplayer.start();                     // bjplayer initializes
        assignCard();                         // assign init 4 Cards
        IsOver = false;
    }
}

void BJackGame::quit() {
    IsContinue = false;
}

void BJackGame::assignCard() {
    for (int i = 0; i < 2; i++) {
        Card temp(bjdealer.giveCard());
        bjplayer.addCard(temp);
        bjdealer.RemoveUsed();

        Card temp1(bjdealer.giveCard());
        bjdealer.addCard(temp1);
        bjdealer.RemoveUsed();
    }
}