// program that emulates resident evil's blackjack (RE7)
//
// By Aidan Lalonde-Novales
// Last Updated 1/13/2023

// files
#include "deck.cpp"

// libraries
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

// namespaces
using namespace std;

/**
 * REVEALS THE CARDS OF THE OPPONENT, SHOWS WHO WON, SUBTRACTS LIVES
 */
void revealCards(
  vector<int> userCards,
  vector<int> oppCards,
  int userLives,
  int oppLives
  ) {
  // count card totals
  int userTotal = 0;
  for (int num : userCards) {
    userTotal += num;
  }

  int oppTotal = 0;
  for (int num : oppCards) {
    oppTotal += num;
  }

  // print card totals, announce who won
  cout << "=======================================\n" << endl;
  cout << "Opponent Total: " << oppTotal
    << "     Your Total: " << userTotal << "\n" << endl;
  if (userTotal > oppTotal && userTotal <= 21) {
    oppLives--;
    cout << "You Win!" << endl;
  } else if (userTotal == oppTotal) {
    cout << "You Tied!" << endl;
  } else {
    userLives--;
    cout << "You Lost!" << endl;
  }
  cout << "" << endl;
  cout << "Opponent Lives: " << oppLives
    << "     Your Lives: " << userLives << "\n" << endl;
}

/**
 * PRINTS OUT THE CARDS AND LIVES OF THE OPPONENT AND USER
 */
void printCards(
  vector<int> userCards,
  vector<int> oppCards,
  int userLives,
  int oppLives
  ) {
  // count card totals
  int userTotal = 0;
  for (int num : userCards) {
    userTotal += num;
  }

  int oppTotal = 0;
  for (int num : oppCards) {
    oppTotal += num;
  }
  oppTotal -= oppCards[0];

  // print opponent info
  cout << "========================================\n" << endl;
  cout << "Oppenents Deck  -  Lives: " << oppLives
    << "  -  Total: ? + " << oppTotal << endl;
  cout << "\n";
  cout << "? ";
  for (int num = 1; num < oppCards.size(); num++) {
    cout << oppCards[num] << " ";
  }
  cout << "\n" << endl;
  // print user info
  cout << "Your Deck  -  Lives: " << userLives
    << "  -  Total: " << userTotal << endl;
  cout << "\n";
  for (int num : userCards) {
    cout << num << " ";
  }
  cout << "\n" << endl;
}

/**
 * MAIN STUB
 */
int main() {
  // initialize variables and classes
  vector<int> userCards;
  vector<int> oppCards;
  int userLives = 5;
  int oppLives = 5;
  string inputStr;
  int input;
  bool gameStarted = false;
  bool stayFlag = false;
  Deck deck;

  // start screen
  // cout << "\n\n\n\n\n\n" << endl;
  cout << "          -=- Welcome to Twenty-One! -=-\n" << endl;
  cout << "Enter '0' at anytime to access a list of commands.\n" << endl;

  // user input
  while (true) {
    cout << "Input: ";
    cin >> inputStr;
    try {
      input = stoi(inputStr);
      // help
      if (input == 0) {
        cout << "0 for help, 1 to start a game, 2 to hit, 3 to stay." << endl;
      // start game
      } else if (input == 1) {
	if (gameStarted) {
          cout << "Game already in progress!" << endl;
	} else {
          gameStarted = true;
	  break;
	}
      // hit
      } else if (input == 2) {
	if (gameStarted) {
          cout << "deal card" << endl; // make this actually deal a card later
	  break;
	} else {
	  cout << "Game has not started!" << endl;
	}
      // stay
      } else if (input == 3) {
        if (gameStarted) {
	  stayFlag = true;
	  break;
	} else {
          cout << "Game has not started!" << endl;
	}
      } else {
	cout << "Unrecognized Command. Enter '0' for help." << endl;
      }
    } catch (invalid_argument) {
      cout << "Unrecognized Command. Enter '0' for help." << endl;
    }
  }

  deck.shuffleCards();
  deck.printCards();

  /**
   * work on later
  while (true) {
    printCards(userCards, oppCards, userLives, oppLives);
    cout << "What would you like to do? (3 - stay, 4 - hit): ";
    cin >> playerOptionString;
  }
  printCards(userCards, oppCards, userLives, oppLives);
  revealCards(userCards, oppCards, userLives, oppLives);
  **/

  cout << "Done." << endl;

  return 0;
}
