// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved
//
// Created by Aidan Lalonde-Novales on 2022-12-02
// This program prints deals cards to the user and the opponent

#include <iostream>
#include <random>
using namespace std;

int main() {
  // define card sets
  int oppCardSet[6];
  int userCardSet[6];

  // mersenne_twister
  random_device rseed;
  mt19937 rgen(rseed());
  uniform_int_distribution<int> idist(1, 11);

  // generate oppenents cards
  for (int count = 0; count < 2; count++) {
    card = idist(rgen);

  }

  cout << "Opponents Deck: \n";

  return 0;
}
