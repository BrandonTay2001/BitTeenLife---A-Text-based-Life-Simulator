/*
Author(s): 
1. Brandon Tay Jian Wei
2. Yoo Yuen Yau

UID(s): 
1. 3035767102
2. 3035832440

Project: 
<BitTeenLife>

Description: 
A game that parodies the mobile game BitLife, for ages [13, 23]

CS Academy Server tested on: 
<academy11>

How to play:
1. Go to shell terminal
2. Type 'make play'
*/

#include <iostream>
#include <fstream>
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

// declaration and initialization of arrays containing statements and events (ages 14-17)
string statements_14_to_17[15] = {
"One day after school, it was raining very heavily and you forgot to bring your umbrella. Your mom coincidentally got caught in the jam and you caught a cold…\n<-1 health>",
"You were revising for your exams when your friend invited you to play League of Legends, you were too fed up with life at that point that you agreed to play. You flunked your test and your mom cut your allowance but at least you didn’t fall into depression!\n<-1 money, +1 happiness>",
"You got nominated for president of the student council and you were so busy that you didn’t take good care of your health. It was worth it though because you became the most popular kid at school!\n<-1 health, +1 happiness>" ,
"A game called ‘Among Us’ went viral and everyone at school was raving about it. You played the game with your friends that night and you guys ended up ‘sussing’ each other ever since.\n<no effect>",
"You were in the toilet one day answering nature call no. 2 when your friends suddenly burst into your toilet stall to take photos of you. You were pissed and chased them out of the toilet while trying hard to get your pants on.\n<-1 happiness>",
"You were watching a movie with your parents when this 18+ scene came on. Both you and your parents tried acting like you guys had something else to do, and only resumed watching after the scene was over.\n<no effect>",
"You read somewhere about this magical fat-burning pill which cost a fortune and decided to buy it. Obviously it didn’t work and now you’re depressed.\n<-2 money, -2 happiness>",
"During your school field trip, you brought your Nintendo Switch which everyone wanted to play. You didn’t let them because it was way too precious to you and now you have no friends…\n<-1 happiness>",
"You received a follow request from your crush on instagram and you freaked out!\n<+2 happiness>",
"You got a free ticket to a Jay Chou concert but you weren’t allowed to go because your grades were too trash. You made a fortune selling off the ticket but you were also really disappointed that you couldn’t go.\n<+2 money, -1 happiness>",
"Your parents took you on a trip to Japan and you were really excited to try Japanese food. To your disappointment, your parents, being the typical asian parents they were, saved as much money as they could by cooking themselves the entire trip...\n<-1 happiness>",
"You argued with your mom that she was giving you too little allowance. She ended up scolding you about being ‘ungrateful and disrespectful’ and ended up cutting your allowance further.\n<-1 money, -1 happiness>",
"You found some Airpods Pro on the MTR seat and took it home, feeling like you just hit the jackpot.\n<+1 happiness>",
"You started working out at the gym everyday to impress your crush, and it worked!\n<+2 health, +1 happiness>",
"You got really good grades for your finals and your dad rewarded you with 10000 HKD!\n<+2 money, +1 happiness>"
};
string events_14_to_17[10] = {
"One day when you were crossing the road to school, a truck driver ran the red light and was driving towards you at full speed. You...",
"It is the annual sports festival at your school, and you decide to...",
"One day, during a particularly hard math class, your classmate began ripping the pages out of his math textbook, yelling profanities. You...",
"You have a really bad acne outbreak and had to get your photo taken for your ID later that day, you...",
"You and some friends were organizing an outing, you suggested going...",
"One day after school, you saw your former classmate and his friends smoking behind the school, you...",
"Your mom signed you up for tuition because you had trashy grades, you...",
"Your parents told you they had to go on a business trip for a few days and you had to stay home alone until they came back. During those few days, you...",
"Your typical asian mom wants you to pick up an instrument, you chose the...",
"Halfway through your final exams, you had a reaaally bad stomach ache. However, you still had a full page left untouched, you..."
};

// declaration and initialization of arrays containing statements and events (age 19, 20, 22)
string statements_19_20_22[6] = {
"Oof, you got hit by a car and now you’re in the hospital\n<-1 money, -1 happiness, -1 health>",
"You got the chance to get an autograph from your favourite singer, Kanye East!\n<+1 happiness>",
"You randomly bought this stock but it turned out that you doubled your money, wow! (you’re still broke tho)\n<+1 money>",
"You started streaming on Twitch and you got a $420.69 donation from Pewdiepie!\n<+1 money, +1 happiness>",
"You made a weird face and your friend posted it online - you’re now a meme...\n<+1 happiness>",
"You took a course called ENGG1340 and you had to make a game - you had way too much fun with it!\n<+1 happiness>"
};
string events_19_20_22[6] = {
"Now that you’re in university, you intend to join a club",
"You have an exam but didn’t study for it, what do you do?",
"You have a really bad stomach ache, what do you do?",
"Your crush just confessed to you, what do you do?",
"You and your friends made a bet on what will happen in the new movie, Avengers: Infinity War. You bet that...",
"This rich hot dude named Elongated Mask wants to be your friend!"
};

// NOTE: functions that print stuff are defined here as they involve manipulating the global arrays above

/*
FUNCTION: prints statement-based events for ages 14-17
INPUT(s): 
1. pass-by-reference player stats
2. pass-by-reference output file stream (for saving game progress in temporary file)
OUTPUT(s): 
1. a random statement for ages 14-17
*/
void printStatements14_to_17( Stats &s, ofstream & fout ) {
	cout << endl;
	cout << "[ Random Statement ]";
	fout << "[ Random Statement ]" << endl;
	cout << endl;

	int selection;

	while ( true ) {
		selection = rand() % 15;
		if ( statements_14_to_17[selection] != "Taken" ) {
			cout << statements_14_to_17[selection] << endl;
			
			// saves game progress in temporary file
			int index = statements_14_to_17[selection].find( "\n" );
			string substring = statements_14_to_17[selection].substr( 0, index );
			fout << substring << endl << endl;

			// changes the element to "Taken" so the same event won't be outputted twice
			statements_14_to_17[selection] = "Taken"; 

			break;
		}
	}

	resultsStatements14_to_17( selection, s );

	return;
}

/*
FUNCTION: prints statement-based events for ages 19, 20, 22
INPUT(s): 
1. pass-by-reference player stats
2. pass-by-reference output file stream (for saving game progress in temporary file)
OUTPUT(s): 
1. a random statement for ages 19, 20, 22
*/
void printStatements19_20_22( Stats &s, ofstream & fout ) {
  cout << endl;
  cout << "[ Random Statement ]";
	fout << "[ Random Statement ]" << endl;
  cout << endl;

  int selection;

  while ( true ) {
    selection = rand() % 6;
    if ( statements_19_20_22[selection] != "Taken" ) {
      cout << statements_19_20_22[selection] << endl;

			// saves game progress in temporary file
			int index = statements_19_20_22[selection].find( "\n" );
			string substring = statements_19_20_22[selection].substr( 0, index );
			fout << substring << endl << endl;

			// changes the element to "Taken" so the same event won't be outputted twice
      statements_19_20_22[selection] = "Taken";

      break;
    }
  }

  resultsStatements19_20_22( selection, s );

	return;
}

/*
FUNCTION: prints choice-based events for ages 14-17
INPUT(s): 
1. pass-by-reference player stats
2. pass-by-reference output file stream (for saving game progress in temporary file)
OUTPUT(s): 
1. a random event for ages 14-17
*/
void printEvents14_17( Stats &s, ofstream & fout ) {
	cout << endl;
	cout << "[ Random Event ]";
	fout << "[ Random Event ]" << endl;
	cout << endl;

	int selection;

	while ( true ) {
		selection = rand() % 10;
		if ( events_14_to_17[selection] != "Taken" ) {
			cout << events_14_to_17[selection] << endl;

			// saves game progress in temporary file
			fout << events_14_to_17[selection];
			
      // changes the element to "Taken" so the same event won't be outputted twice
			events_14_to_17[selection] = "Taken";

			break;
		}
	}

	resultsEvents14_to_17( selection, s, fout );

	return;
}

/*
FUNCTION: prints choice-based events for ages 19, 20, 22
INPUT(s): 
1. pass-by-reference player stats
2. pass-by-reference output file stream (for saving game progress in temporary file)
OUTPUT(s): 
1. a random event for ages 19, 20, 22
*/
void printEvents19_20_22( Stats &s, ofstream & fout ) {
  cout << endl;
  cout << "[ Random Event ]";
	fout << "[ Random Event ]" << endl;
  cout << endl;

  int selection;

  while ( true ) {
    selection = rand() % 6;
    if ( events_19_20_22[selection] != "Taken" ) {
      cout << events_19_20_22[selection] << endl;

			// saves game progress in temporary file
			fout << events_19_20_22[selection];

      // changes the element to "Taken" so the same event won't be outputted twice
      events_19_20_22[selection] = "Taken";

      break;
    }
  }

  resultsEvents19_20_22( selection, s, fout );

	return;
}

/* 
FUNCTION: 
Gives player choice to: 
1. continue game
2. save + quit the game
INPUT(s):
1. pass-by-reference dynamic variable age
2. user-provided file for saving game progress
3. temporary file for saving game progress temporarily
4. player stats
5. player name
OUTPUT(s):
1. Prompts player to choose between:
	a) continue
	b) save and quit 
RETURN VALUE:
1. bool variable indicating player's choice to continue / quit game.
*/
bool growUpOrQuit( int * &age, string filename, string tempfile, Stats player, string name ) {
	// declaration of string and bool variables for storing user choice
  string truefalse; 
	bool choice; 

	//prompt user for choice
  cout << "You're all done for this year. Grow up or quit?" << endl;
  cout << "Enter:" << endl << "<1> grow up" << endl << "<2> save and quit game" << endl;

	// store user choice in string variable
  cin >> truefalse;

	// continue playing
  if ( truefalse == "1" ) {
		// increment age and store user choice
    * age += 1; 
		choice = true; 
  }

	// save and quit game
	else if ( truefalse == "2" ) {
		// increment age and store user choice
		* age += 1;
		choice = false;
		// declare ofstream object for copying game progress in temporary file <tempfile> to user-provided file <filename>
		ofstream save; 
		save.open( filename.c_str() );
		if ( save.fail() ) {
			cout << "Error opening file for saving!" << endl;
			exit( 1 );
		}

		// saves player name, age, and stats in the first 5 lines of the file (purpose: for loading game)
		save << "[ FILE I/O INFORMATION ]" << endl;
		save << name << endl;
		save << * age << endl;
		save << player.health << endl;
		save << player.money << endl;
		save << player.happiness << endl << endl;

		// declare ifstream object for reading game progress in temporary file <tempfile> 
		ifstream copy;
		copy.open( tempfile.c_str() );
		if ( copy.fail() ) {
			cout << "Error opening file for copying!" << endl;
			exit( 1 );
		}

		// copy game progress in <tempfile> to <filename> line by line
		save << "[ GAME PROGRESS ]" << endl;
		string linecopy;
		while( getline( copy, linecopy ) ) {
			save << linecopy << endl;
		}
			
		// close files 
		save.close();
		copy.close();
  }

	return choice;
}

int main() {
  // print out game to-knows 
  cout << "Welcome to BitTeenLife, a short parody of BitLife! " << endl; 
  cout << "For optimal experience, play with your terminal maximized to Fullscreen!" << endl;
  cout << "Various assumptions on input:" << endl;
  cout << "1. All inputs must be VALID" << endl;
  cout << "2. Name must be a SINGLE word" << endl << endl;

	srand( time( NULL ) ); // initiates the random seed
	string name; // declare string variable for player name
	Stats player; // declare struct variable for player stats
	int * age = new int( 0 ); // declare and initialize dynamic variable for age

	// file I/O requirement 
	ofstream fout; // writes game progress to temporary file
	string newOrLoad; // for storing user choice to load new or previously saved game
	string filename; //for storing name of user-provided file

	// temporary file for writing game progress to
	string tempfile = "tempfile.txt";
	fout.open( tempfile.c_str() );
	if ( fout.fail() ) {
		cout << "Error opening file!" << endl;
		exit( 1 );
	}

	// prompts user for choice to load new or previously saved game
	cout << "Enter:" << endl << "<1> to load new game" << endl << "<2> to load saved game" << endl;
	cin >> newOrLoad;

	// new game 
	if ( newOrLoad == "1" ) {
		cout << "Enter name of .txt file to save game progress: ";
		cin >> filename;

		cout << "Enter your character's name: ";

		// input of name
		cin >> name;
		fout << "Name: " << name << endl; // write to game progress file
		cout << endl;

		// initialization of the struct variable
		player = { 1, 1, 1 };
		printStats( player, name );

		
		string * upgrade = new string;  // initialization of dynamic variable for storing upgrade choice

		// prompt user for upgrade choice
		cout << "You get to upgrade one of your stats! " << endl;
		cout << "<1> health" << endl << "<2> money" << endl << "<3> happiness" << endl;

		// facilitates the upgrade of a single stat
		cout << "Enter choice: ";
		cin >> * upgrade;
		if ( * upgrade == "1" ) {
			updateStats( player, 1, 0, 0 );
		}
		else if ( * upgrade == "2" ) {
			updateStats( player, 0, 1, 0 );
		}
		else if ( * upgrade == "3" ) { 
			updateStats( player, 0, 0, 1 );
		}

		delete upgrade; // frees the upgrade dynamic variable

		cout << endl;

		printStats( player , name );

		// initialization of age 
		* age = 13;
	}	

	// load saved game
	else if ( newOrLoad == "2" ) {
		// prompt user for filename to load + save game progress and store it in the previously declared variable <filename>
		cout << "Enter name of .txt file to load game progress: ";
		cin >> filename;

		// declare ifstream object to read file 
		ifstream fin;
		fin.open( filename.c_str() );
		if ( fin.fail() ) {
			cout << "Error opening file!" << endl;
			exit( 1 );
		}

		string resume; // declare string variable for reading lines in file
		int linecount = 0; // declare int variable to track line number
		
		while ( getline( fin, resume ) ) {
			// line 1 contains player name
			if ( linecount == 1 ) {
				name = resume;
			}
			// line 2 contains player age
			else if ( linecount == 2 ) {
				* age = stoi( resume );
			}
			// line 3 contains player health stat
			else if ( linecount == 3 ) {
				player.health = stoi( resume );
			}
			// line 4 contains player money stat
			else if ( linecount == 4 ) {
				player.money = stoi( resume );
			}
			// line 5 contains player happiness stat
			else if ( linecount == 5 ) {
				player.happiness = stoi( resume ); 
			}
			// remaining lines contain previous game progress
			else if ( linecount > 6 ) {
				fout << resume << endl;
			}

			linecount++; // increment linecount after reading a line
		}

		fin.close();
	}

  // main structure of the entire game
	while ( * age != 24 ) {
		fout << endl;

		switch ( * age ) {
			case 13:
        cout << "Age: 13" << endl;
        cout << "-------" << endl;

				fout << "Age: 13" << endl;
        fout << "-------" << endl;

				Events13( player, name, fout );
        break;

			case 14:
        cout << "Age: 14" << endl;
        cout << "-------" << endl;

        fout << "Age: 14" << endl;
        fout << "-------" << endl;

				printStatements14_to_17( player, fout );
        printStats( player, name );
        printEvents14_17( player, fout );
        printStats( player, name );
				break;

      case 15:
        cout << "Age: 15" << endl;
        cout << "-------" << endl;

        fout << "Age: 15" << endl;
        fout << "-------" << endl;

				printStatements14_to_17( player, fout );
        printStats( player, name );
        printEvents14_17( player, fout );
        printStats( player, name );		
				break;

      case 16:
        cout << "Age: 16" << endl;
        cout << "-------" << endl;

        fout << "Age: 16" << endl;
        fout << "-------" << endl;		

				printStatements14_to_17( player, fout );
        printStats( player, name );
        printEvents14_17( player, fout );
        printStats( player, name );
				break;

      case 17:
        cout << "Age: 17" << endl;
        cout << "-------" << endl;

        fout << "Age: 17" << endl;
        fout << "-------" << endl;

				printStatements14_to_17( player, fout );
        printStats( player, name );
        printEvents14_17( player, fout );
        printStats( player, name );	
				break;

      case 18:
        cout << "Age: 18" << endl;
        cout << "-------" << endl;
				
        fout << "Age: 18" << endl;
        fout << "-------" << endl;		

				Events18( player, name, fout );
				break;

      case 19:
        cout << "Age: 19" << endl;
        cout << "-------" << endl;

        fout << "Age: 19" << endl;
        fout << "-------" << endl;

        printStatements19_20_22( player, fout );
        printStats( player, name );
        printEvents19_20_22( player, fout );
        printStats( player, name );	
        break;

      case 20:
        cout << "Age: 20" << endl;
        cout << "-------" << endl;

        fout << "Age: 20" << endl;
        fout << "-------" << endl;

        printStatements19_20_22( player, fout );
        printStats( player, name );
        printEvents19_20_22( player, fout );
        printStats( player, name );
        break;

      case 21:
        cout << "Age: 21" << endl;
        cout << "-------" << endl;

        fout << "Age: 21" << endl;
        fout << "-------" << endl;

        Events21( player, player.happiness, player.health, player.money, name, fout );
        break;

      case 22:
        cout << "Age: 22" << endl;
        cout << "-------" << endl;

        fout << "Age: 22" << endl;
        fout << "-------" << endl;

        printStatements19_20_22( player, fout );
        printStats( player, name );
        printEvents19_20_22( player, fout );
        printStats( player, name );	
        break;

      case 23:
        cout << "Age: 23" << endl;
        cout << "-------" << endl;

        fout << "Age: 23" << endl;
        fout << "-------" << endl;

        Events23( player, player.happiness, player.health, player.money, name, fout );
        break;
		}

		// call function to determine whether player wants to continue or quit game
		bool continuePlaying = growUpOrQuit( age, filename, tempfile, player, name );

		// save amd quit game procedures
    if ( !continuePlaying ) {
			fout.close(); // close temporary file 
			delete age; // delete age dynamic variable
			return 0; // exit game
		}
  }

  delete age; // delete dynamic variable
	fout.close(); // close temporary file

	// declare ofstream object for copying contents in <tempfile> to <filename>
	ofstream save;
	save.open( filename.c_str() ); // open user-provided file <filename> for saving game progress 
	if ( save.fail() ) {
		cout << "Error opening file for saving!" << endl;
		exit( 1 );
	}

	// declare ifstream object for reading from <tempfile>
	ifstream copy;
	copy.open( tempfile.c_str() ); // open temporary file containing game progress 
	if ( copy.fail() ) {
		cout << "Error opening file for copying!" << endl;
		exit( 1 );
	}

	string linecopy; // string variable for storing file lines while reading <tempfile>
	while( getline( copy, linecopy ) ) {
		save << linecopy << endl; // saves game summary by copying from temporary file
		cout << linecopy << endl; // displays summary of game
	}

	// close all files
	save.close();
	copy.close();

  // calls the final function to output a summary of the game
	printStats( player, name );
  finalFunc( player.health, player.money, player.happiness );
	
	// informs player that a summary of their game can be viewed in the file they provided
	cout << endl << "To view your game summary, open the <.txt> file you provided at the start of the game!" << endl;

  return 0;
}