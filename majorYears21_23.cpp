/*
FILE: contains all functions for ages 21, 23
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

// NOTE: all lines containing 'fout' saves game progress in <tempfile>

/*
FUNCTION: deals with all events at Age 21
INPUT(s):
1. player stats information
2. player name
3. pass-by-reference ofstream object for writing game progress to <tempfile>
OUTPUT(s):
1. Events at Age 21
*/
void Events21 ( Stats &s, int happiness, int health, int money, string name, ofstream & fout ) {
  int * prev = new int ( 0 );
  int choice;

  for ( int i = 0; i < 2; i++ ) {
		if ( i == 0 ) {
			fout << "[ Event 1 ]" << endl;
		}
		else if ( i == 1 ) {
			fout << endl << "[ Event 2 ]" << endl;
		}

    if ( happiness == 2 && *prev != 1 ) {
      * prev = 1;

      cout << "You got an interview for an internship at your dream company tomorrow! You..." << endl;
      cout << "1. Stay up late and study for the interview " << endl;
      cout << "2. Don’t study, watch anime instead" << endl;
      cout << "3. Don’t study, hit the gym instead" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "You got an interview for an internship at your dream company tomorrow! You...";
      if ( choice == 1 ) {
        cout << "The interviewer was impressed and you got the job!" << endl;
        updateStats( s, -1, 0, 1 );
        cout << "<+1 happiness, -1 health>" << endl;

        fout << endl << "Choice: Stay up late and study for the interview" << endl;
        fout << "The interviewer was impressed and you got the job!" << endl;
      }
      else if ( choice == 2 ) {
        updateStats( s, 0, 0, -1 );
        cout << "Why would you do that? You didn’t land the job!" << endl;
        cout << "<-1 happiness>" << endl;

        fout << endl << "Choice: Don’t study, watch anime instead" << endl;
        fout << "Why would you do that? You didn’t land the job!" << endl;
      }
      else if ( choice == 3 ) {
        updateStats( s, 1, 0, 0 );
        cout << "You didn’t land the job but at least you got those sweet abs!" << endl;
        cout << "<+1 health>" << endl;

        fout << endl << "Choice: Don’t study, hit the gym instead" << endl;
        fout << "You didn’t land the job but at least you got those sweet abs!" << endl;
      }
    }
    else if ( health <= 1 && money >= 1 && * prev != 2 ) {
      * prev = 2;

      cout << "You didn’t take care of your health and fell ill! You..." << endl;
      cout << "1. See the doctor" << endl;
      cout << "2. Don't see the doctor" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "You didn’t take care of your health and fell ill! You...";
      if ( choice == 1 ) {
        cout << "The doctor gave you some medicine and soon you feel better" << endl;
        updateStats( s, 1, -1, 0 );
        cout << "<-1 money, +1 health>" << endl;

        fout << endl << "Choice: See the doctor" << endl;
        fout << "The doctor gave you some medicine and soon you feel better" << endl;
      }
      else if ( choice == 2 ) {
        updateStats( s, -1, -1, 0 );
        cout << "Your situation got worse and you had to see the doctor anyway.. Blame yourself!" << endl;
        cout << "<-1 money, -1 health>" << endl;

        fout << endl << "Choice: Don't see the doctor" << endl;
        fout << "Your situation got worse and you had to see the doctor anyway.. Blame yourself!" << endl;
      }
    }
    else if ( happiness == 0 && *prev != 3 ) {
      * prev = 3;

      cout << "You were diagnosed with depression… You…" << endl;
      cout << "1. Go for therapy" << endl;
      cout << "2. Ignore it and just keep living miserably" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "You were diagnosed with depression… You…";
      if ( choice == 1 ) {
        cout << "The therapy sessions worked out and you got out of that dark place, congrats!" << endl;
        cout << "<+1 happiness>" << endl;
        updateStats( s, 0, 0, 1 );

        fout << endl << "Choice: Go for therapy" << endl;
        fout << "The therapy sessions worked out and you got out of that dark place, congrats!" << endl;
      }
      else if ( choice == 2 ) {
        cout << "Your overwhelming misery had a chain reaction and now all your friends are miserable too..." << endl;
        cout << "<-1 health>" << endl;
        updateStats( s, -1, 0, 0 );

        fout << endl << "Choice: Ignore it and just keep living miserably"  << endl;
        fout << "Your overwhelming misery had a chain reaction and now all your friends are miserable too..." << endl;
      }
    }
    else if ( health >= 1 && *prev != 4 ) {
      * prev = 4;

      cout << "You were invited to go to the biggest music festival, Senpai-ella!" << endl;
      cout << "1. Go for it!" << endl;
      cout << "2. Don't go" << endl;
      cout << "3. Go for it, bring along tons of alcohol" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "You were invited to go to the biggest music festival, Senpai-ella!";
      if ( choice == 1 ) {
        cout << "You had a great time screaming your head off with your friends and ended up with a really bad sore throat." << endl;
        cout << "<+1 happiness, -1 health>" << endl;
        updateStats( s, -1, 0, 1 );

        fout << endl << "Choice: Go for it!" << endl;
        fout << "You had a great time screaming your head off with your friends and ended up with a really bad sore throat." << endl;
      }
      else if ( choice == 2 ) {
        cout << "But why? (bruh you don’t know how to enjoy life… )" << endl;
        cout << "<No effect>" << endl;

        fout << endl << "Choice: Don't go" << endl;
      }
      else if ( choice == 3 ) {
        cout << "You got piss drunk and didn’t remember a single thing about the event..." << endl;
        cout << "<-1 health, -1 money>" << endl;
        updateStats( s, -1, -1, 0 );

        fout << endl << "Choice: Go for it, bring along tons of alcohol" << endl;
        fout << "You got piss drunk and didn’t remember a single thing about the event..." << endl;
      }
    }
    else {
      * prev = 5;

      cout << "Your friend Mark Zuckabird pitches you an idea for a social media app called Facebook, do you invest?" << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "Your friend Mark Zuckabird pitches you an idea for a social media app called Facebook, do you invest?";
      if ( choice == 1 && money == 0 ) {
        cout << "Too bad you didn’t have any money now all your friends just think you’re dumb!" << endl;

        fout << endl << "Choice: Yes" << endl;
        fout << "Too bad you didn’t have any money now all your friends just think you’re dumb!" << endl;
      }
      else if ( choice == 1 && money == 1 ) {
        cout << "You made the investment but you need to go hungry for a few days" << endl;
        cout << "<-1 health>" << endl;
        updateStats( s, -1, 0, 0 );

        fout << endl << "Choice: Yes" << endl;
        fout << "You made the investment but you need to go hungry for a few days" << endl;
      }
      else if ( choice == 1 && money == 2 ) {
        cout << "You made the investment, confident that it will pay off" << endl;
        cout << "<+1 happiness>" << endl;
        updateStats( s, 0, 0, 1 );

        fout << endl << "Choice: Yes" << endl;
        fout << "You made the investment, confident that it will pay off" << endl;
      }
      else if ( choice == 2 ) {
        cout << "No effect" << endl;

        fout << endl << "Choice: No" << endl;
      }
    }

    printStats( s, name ); // displays current player stats
  }

  delete prev; // frees up space allocated to dynamic variable

}

/*
FUNCTION: deals with all events at Age 23
INPUT(s):
1. player stats information
2. player name
3. pass-by-reference ofstream object for writing game progress to <tempfile>
OUTPUT(s):
1. Events at Age 23
*/
void Events23 ( Stats &s, int happiness, int health, int money, string name, ofstream & fout ) {
  int * prev = new int ( 0 );
  int choice;

  for ( int i = 0; i < 2; i++ ) {
		if ( i == 0 ) {
			fout << "[ Event 1 ]" << endl;
		}
		else if ( i == 1 ) {
			fout << endl << "[ Event 2 ]" << endl;
		}

    if ( happiness >= 1 && *prev != 1 ) {
      * prev = 1;

      cout << "Congratulations! You graduated from university!" << endl;
      cout << "1. Get a job " << endl;
      cout << "2. Travel the world" << endl;
      cout << "3. Party in the club all day" << endl;
      cout << "4. Start a business" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "Congratulations! You graduated from university!";
      if ( choice == 1 ) {
        cout << "You got that sweet 6-figure salary as a fresh grad and you’re making bank!" << endl;
        updateStats( s, 0, 1, 0 );
        cout << "<+1 money>" << endl;

        fout << endl << "Choice: Get a job" << endl;
        fout << "You got that sweet 6-figure salary as a fresh grad and you’re making bank!" << endl;
      }
      else if ( choice == 2 ) {
        updateStats( s, 1, -1, 1 );
        cout << "Wow, unconventional route huh? You used some hard-earned money but at least you found some ‘inner peace’!" << endl;
        cout << "<-1 money, +1 happiness +1 health>" << endl;

        fout << endl << "Choice: Travel the world" << endl;
        fout << "Wow, unconventional route huh? You used some hard-earned money but at least you found some ‘inner peace’!" << endl;
      }
      else if ( choice == 3 ) {
        updateStats( s, -1, -1, 0 );
        cout << "Nothing wrong with having a bit of fun after 4 years of torture I guess…" << endl;
        cout << "<-1 money, -1 health>" << endl;

        fout << endl << "Choice: Party in the club all day" << endl;
        fout << "Nothing wrong with having a bit of fun after 4 years of torture I guess…" << endl;
      }
      else if ( choice == 4 ) {
        updateStats( s, -1, 1, 0 );
        cout << "Entrepreneurial life is hard, you lost some sleep over the business but at least you’re on your way to making the big bucks!" << endl;
        cout << "<+1 money, -1 health>" << endl;

        fout << endl << "Choice: Start a business" << endl;
        fout << "Entrepreneurial life is hard, you lost some sleep over the business but at least you’re on your way to making the big bucks!" << endl;
      }
    }
    else if ( happiness == 0 && *prev != 2 ) {
      * prev = 2;

      cout << "Aw man, you had to extend your time in university as your grades slipped!" << endl;
      cout << "1. Study hard!!" << endl;
      cout << "2. Party hard! Uni doesn't matter!" << endl;
      cout << "3. Doesn’t matter, I’m taking a year off." << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "Aw man, you had to extend your time in university as your grades slipped!";
      if ( choice == 1 ) {
        cout << "Nice! You finally graduated a while later!" << endl;
        updateStats( s, 0, 0, 1 );
        cout << "<+1 happiness>" << endl;

        fout << endl << "Choice: Study hard!!" << endl;
        fout << "Nice! You finally graduated a while later!" << endl;
      }
      else if ( choice == 2 ) {
        updateStats( s, -1, -1, 0 );
        cout << "Didn’t learn anything, eh? You would have to stay back another year!" << endl;
        cout << "<-1 money, -1 health>" << endl;

        fout << endl << "Choice: Party hard! Uni doesn't matter!" << endl;
        fout << "Didn’t learn anything, eh? You would have to stay back another year!" << endl;
      }
      else if ( choice == 3 ) {
        updateStats( s, 1, 0, 1 );
        cout << "You managed to find another purpose in life during the break, congrats! " << endl;
        cout << "<+1 happiness, -1 health>" << endl;

        fout << endl << "Choice: Doesn’t matter, I’m taking a year off." << endl;
        fout << "You managed to find another purpose in life during the break, congrats! " << endl;
      }
    }
    else if ( money <= 1 && *prev != 3 ) {
      * prev = 3;

      cout << "You hit a small jackpot in the lottery!" << endl;
      cout << "1. Spend it all!" << endl;
      cout << "2. Save like a responsible human being" << endl;
      cout << "3. Gamble on penny stocks!" << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "You hit a small jackpot in the lottery!";
      if ( choice == 1 ) {
        cout << "Why...?" << endl;
        cout << "<-1 money, +1 happiness>" << endl;
        updateStats( s, 0, -1, 1 );

        fout << endl << "Choice: Spend it all!" << endl;
        fout << "Why...?" << endl;
      }
      else if ( choice == 2 ) {
        cout << "Wow, how responsible!" << endl;
        cout << "<-1 money>" << endl;
        updateStats( s, 0, -1, 0 );

        fout << endl << "Choice: Save like a responsible human being" << endl;
        fout << "Wow, how responsible!" << endl;
      }
      else if ( choice == 3 ) {
        cout << "Your stocks tanked. Unfortunately you were a noob and accidentally bought on margin. You’re broke now…" << endl;
        cout << "<-2 money>" << endl;
        updateStats( s, 0, -2, 0 );

        fout << endl << "Choice: Gamble on penny stocks!" << endl;
        fout << "Your stocks tanked. Unfortunately you were a noob and accidentally bought on margin. You’re broke now…" << endl;
      }
    }
    else if ( health >= 1 && money >= 1 && *prev != 4 ) {
      * prev = 4;

      cout << "Oh no! Your doctor diagnosed you with a serious disease and said you will die if you don’t treat it!" << endl;
      cout << "1. Get it treated, I'm not dying young!" << endl;
      cout << "2. Don't do anything about it, I've lived a good life... " << endl;

      cout << "Enter choice: ";
      cin >> choice;

      fout << "Oh no! Your doctor diagnosed you with a serious disease and said you will die if you don’t treat it!";
      if ( choice == 1 ) {
        cout << "All is good, it seems your doctor just scammed you! (You still have to pay the hospital fees tho..)" << endl;
        cout << "<-1 money>" << endl;
        updateStats( s, 0, -1, 0 );

        fout << endl << "Choice: Get it treated, I'm not dying young!" << endl;
        fout << "All is good, it seems your doctor just scammed you! (You still have to pay the hospital fees tho..)" << endl;
      }
      else if ( choice == 2 ) {
        cout << "You doctor screamed at you telling you how stupid you were, but it seems he was just trying to scam you.. Guess who’s the smart one now?" << endl;
        cout << "<+1 happiness>" << endl;
        updateStats( s, 0, 0, 1 );

        fout << endl << "Choice: Don't do anything about it, I've lived a good life... " << endl;
        fout << "You doctor screamed at you telling you how stupid you were, but it seems he was just trying to scam you.. Guess who’s the smart one now?" << endl;
      }
    }
    else if ( health == 0 && *prev != 5 ) {
      *prev = 5;

      cout << "Your unhealthy living habits means that you had to take vitamins everyday to maintain your health.." << endl;
      cout << "1. Take those pills diligently " << endl;
      cout << "2. ‘I don’t need no pills, I’m perfectly fit!’ *continues to eat junk food and drink boba tea*" << endl;
      cout <<  "3. Don’t take the pills but fix your unhealthy living habits" << endl;

      cout << "Enter choice: ";
      cin >> choice;
      
      fout << "Your unhealthy living habits means that you had to take vitamins everyday to maintain your health..";
      if ( choice == 1 ) {
        cout << "For your responsible actions, you have been rewarded with better health (and a smaller wallet)!" << endl;
        updateStats( s, 1, -1, 0 );
        cout << "<+1 health, -1 money>" << endl;

        fout << endl << "Choice: Take those pills diligently " << endl;
        fout << "For your responsible actions, you have been rewarded with better health (and a smaller wallet)!" << endl;
      }
      else if ( choice == 2 ) {
        cout << "Congratulations, you played yourself! Now you need a stay in the hospital!" << endl;
        cout << "<-2 money, -2 happiness>" << endl;
        updateStats( s, 0, -2, -2 );

        fout << endl << "Choice: ‘I don’t need no pills, I’m perfectly fit!’ *continues to eat junk food and drink boba tea*" << endl;
        fout << "Congratulations, you played yourself! Now you need a stay in the hospital!" << endl;
      }
      else if ( choice == 3 ) {
        cout << "Hmm.. not bad! You got the best of both worlds!" << endl;
        cout << "<+1 happiness, +1 health>" << endl;
        updateStats( s, 1, 0, 1 );

        fout << endl << "Choice: Don’t take the pills but fix your unhealthy living habits" << endl;
        fout << "Hmm.. not bad! You got the best of both worlds!" << endl;
      }
    }

    printStats( s, name ); // displays current player stats
  }

  delete prev; // free memory allocated to dynamic variable prev
}