// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved
//
// Created by Aidan Lalonde-Novales on 2022-12-02
// This program prints deals cards to the user and the opponent

#include <iostream>
#include <random>
#include <list>
using namespace std;

int main() {
  // define card sets
  list<int> oppCardSet;
  list<int> userCardSet;

  // mersenne_twister
  random_device rseed;
  mt19937 rgen(rseed());
  uniform_int_distribution<int> idist(1, 11);

  // generate oppenents cards
  for (int count = 0; count < 2; count++) {
    int card = idist(rgen);
    oppCardSet.push_back(card);
  }

  // generate users cards
  for (int count = 0; count < 2; count++) {
    int card = idist(rgen);
    userCardSet.push_back(card);
  }

  // print opponents deck
  cout << "Opponents Deck:" << endl;
  for (auto const &count: oppCardSet) {
    cout << count << " ";
  }
  cout << "\n";

  cout << "Your Deck:" << endl;
  for (auto const &count: userCardSet) {
    cout << count << " ";
  }
  cout << "\n";

  return 0;
}
