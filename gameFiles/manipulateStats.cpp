// This file contains code related to functions that manipulate player stats

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "struct.h"
#include "manipulateStats.h"
#include "majorYears13_18.h"
#include "majorYears21_23.h"
#include "minorYears.h"

using namespace std;

// STATS RELATED FUNCTIONS 
/* 
[Display Player Stats]
Inputs: 
1. Data structure on player stats
2. Character name
Outputs:
1. Player's current stats
*/
void printStats( Stats s, string name ) {
	cout << endl;
  cout << name << "'s stats: " << endl;
  cout << "--------------------------------------------------" << endl;
  cout << setw( 34 ) << "| RANGE = [0, 2] |" << endl;
	cout << "--------------------------------------------------" << endl;
  cout << "MONEY: " << s.money << setw( 20 );
  cout << "HEALTH: " << s.health << setw( 20 );
  cout << "HAPPINESS: " << s.happiness;
  cout << endl;
  cout << "--------------------------------------------------" << endl;
	cout << endl;

  return;
}

/* 
[Update Player Stats]
Inputs:
1. Data structure on player stats
2. Effects of events on player stats
Outputs:
-
note: range = [0, 2]: increment stats only if they're < 2, decrement stats only if they're > 1; effects which max/min out stats considered separately.
*/
void updateStats( Stats &s, int health, int money, int happiness ) {
	if ( health == 1 && s.health < 2) {
		s.health++;
	}
	else if ( health == -1 && s.health > 0) {
		s.health--;
	}
	else if ( health == 2 ) {
		s.health = 2;
	}
	else if ( health == -2 ) {
		s.health = 0;
	}

	if ( money == 1 && s.money < 2) {
		s.money++;
	}
	else if ( money == -1 && s.money > 0) {
		s.money--;
	}
	else if ( money == 2 ) {
		s.money = 2;
	}
	else if ( money == -2 ) {
		s.money = 0;
	}

	if ( happiness == 1 && s.happiness < 2) {
		s.happiness++;
	}
	else if ( happiness == -1 && s.happiness > 0) {
		s.happiness--;
	}
	else if ( happiness == 2 ) {
		s.happiness = 2;
	}
	else if ( happiness == -2 ) {
		s.happiness = 0;
	}	

	return;
}

/*
[Game Summary]
Inputs: 
1. Data structure on player stats.
Outputs:
1. Summary of the game based on player stats
note: to be called at the end of the game
*/
void finalFunc( int health, int money, int happiness ) {
  cout << endl;
  cout << "You've reached the end of the game..." << endl;

  if ( happiness == 2 && money == 2 && health == 2 ) {
    cout << "Congratulations, you lived your best teenage life!" << endl;
  }
  else if ( happiness == 1 && money == 1 && health == 1 ) {
    cout << "Hmm.. Not too bad! You lived a pretty decent teenage life!" << endl;
  }
  else if ( happiness == 0 && money == 0 && health == 0 ) {
    cout << "How do you mess up that bad??" << endl;
  }
  else if ( happiness == 2 && money == 0 && health == 0 ) {
    cout << "You're broke and obese.. but at least you had fun, right?" << endl;
  }
  else if ( happiness == 0 && money == 2 && health == 0 ) {
    cout << "You're rich, but was it worth all the sacrifices? (damn right it was!)" << endl;
  }
  else {
    cout << "You lived a.. pretty normal teenage life, I guess?" << endl;
  }

  cout << "Feel free to replay the game as many times as you want, we have many more possible outcomes for you to discover!" << endl;

	return;
}