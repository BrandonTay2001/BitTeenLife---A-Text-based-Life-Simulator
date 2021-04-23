// This file contains functions related to the 7 minor years

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

// MINOR YEARS FUNCTIONS (ages 14 - 17, 19 - 20, 22)
// deals with updating the stats after each statement at age 14-17
// inputs: chosen index, player's stats as a pass-by reference
// no outputs
void resultsStatements14_to_17( int index, Stats &s ) {
	switch ( index ) {
		case 0:
			updateStats( s, -1, 0, 0 );
			break;
		case 1:
			updateStats( s, 0, -1, 1 );
			break;
		case 2:
			updateStats( s, -1, 0, 1 );
			break;
		case 3:
		case 5:
			updateStats( s, 0, 0, 0 );
			break;
		case 4:
		case 7:
		case 10:
			updateStats( s, 0, 0, -1 );
			break;
		case 6:
			updateStats( s, 0, -2, -2 );
			break;
		case 8:
			updateStats( s, 0, 0, 2 );
			break;
		case 9:
			updateStats( s, 0, 2, -1 );
			break;
		case 11:
			updateStats( s, 0, -1, -1 );
			break;
		case 12:
			updateStats( s, 0, 0, 1 );
			break;
		case 13:
			updateStats( s, 2, 0, 1 );
			break;
		case 14:
			updateStats( s, 0, 2, 1 );
			break;
	}

	return;
}

// deals with updating the stats after each statement at age 19, 20 & 22
// inputs: chosen index, player's stats as a pass-by reference
// no outputs
void resultsStatements19_20_22( int index, Stats &s ) {
  switch ( index ) {
    case 0:
      updateStats( s, -1, -1, -1);
      break;
    case 1:
		case 4:
		case 5:
      updateStats( s, 0, 0, 1 );
      break;
    case 2:
      updateStats( s, 0, 1, 0 );
      break;
    case 3:
      updateStats( s, 0, 1, 1 );
      break;
  }

	return;
}

// outputs the results of events at ages 14-17
// inputs: chosen index, player's stats as a pass-by reference
void resultsEvents14_to_17( int index, Stats &s, ofstream & fout ) {
	int choice;
	cout << "Please enter the choice number when prompted!" << endl;
  cout << "--------------------------------------------------" << endl;
	switch ( index ) {
		case 0:
			cout << "1. dodge to your right." << endl;
			cout << "2. dodge to your left." << endl;
			cout << "3. accept your fate and prepare to die." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "You narrowly avoided getting hit, congrats!" << endl;
				cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: dodge to your right." << endl;
				fout << "You narrowly avoided getting hit, congrats!" << endl;
			}
			else if ( choice == 2 ) {
				cout << "Unfortunately, the truck driver swerved to your left along with you and ran over your right foot. You had to get hospitalized for a month..." << endl;
				cout << "<-1 health>" << endl;
				updateStats( s, -1, 0, 0 );

				//save game
				fout << endl << "Choice: dodge to your left." << endl;
				fout << "Unfortunately, the truck driver swerved to your left along with you and ran over your right foot. You had to get hospitalized for a month..." << endl;
			}
			else if ( choice == 3 ) {
				cout << "The truck driver managed to swerve out of the way at the last minute and you lived! However, you were permanently traumatized by the incident..." << endl;
				cout << "<-1 happiness>" << endl;
				updateStats( s, 0, 0, -1 );

				//save game
				fout << endl << "Choice: accept your fate and prepare to die." << endl;
				fout << "The truck driver managed to swerve out of the way at the last minute and you lived! However, you were permanently traumatized by the incident..." << endl;
			}
			break;

		case 1:
			cout << "1: take part as a cheerleader." << endl;
			cout << "2: take part as a sprinter." << endl;
			cout << "3: not to take part." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "Your epic cheerleading skills caught your crush's attention and she started glancing at you more!" << endl;
				cout << "<+1 happiness>" << endl;
				updateStats( s, 0, 0, 1 );

				// save game
				fout << endl << "Choice: take part as a cheerleader." << endl;
				fout << "Your epic cheerleading skills caught your crush's attention and she started glancing at you more!" << endl;				
			}
			else if ( choice == 2 ) {
				cout << "You had a cramp halfway through the 100m race and collapsed to the ground. Your friends mocked you and now you’re just depressed..." << endl;
				cout << "<-2 happiness>" << endl;
				updateStats( s, 0, 0, -2 );

				// save game
				fout << endl << "Choice: take part as a sprinter." << endl;
				fout << "You had a cramp halfway through the 100m race and collapsed to the ground. Your friends mocked you and now you’re just depressed..." << endl;				
			}
			else if ( choice == 3 ) {
				cout << "Your typical asian mom scolded you for being incompetent and banned you from using wifi at home for a week..." << endl;
				cout << "<-1 happiness>" << endl;
				updateStats( s, 0, 0, -1 );

				// save game
				fout << endl << "Choice: not to take part." << endl;
				fout << "Your typical asian mom scolded you for being incompetent and banned you from using wifi at home for a week..." << endl;
			}
			break;

		case 2:
			cout << "1: begin doing the same to relieve your stress." << endl;
			cout << "2: tried calming him down." << endl;
			cout << "3: laugh at him!" << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "You both got sent to the principal’s office and received warnings for your behaviors. However, you got rid of all your stress!" << endl;
				cout << "<+1 happiness>" << endl;
				updateStats( s, 0, 0, 1 );

				// save game
				fout << endl << "Choice: begin doing the same to relieve your stress." << endl;
				fout << "You both got sent to the principal’s office and received warnings for your behaviors. However, you got rid of all your stress!" << endl;				
			}
			else if ( choice == 2 ) {
				cout << "Surprisingly, he calmed down. (because he was secretly attracted to you) You got commended by your teacher for helping out!" << endl;
				cout << "<+1 happiness>" << endl;
				updateStats( s, 0, 0, 1 );

				// save game
				fout << endl << "Choice: tried calming him down." << endl;
				fout << "Surprisingly, he calmed down. (because he was secretly attracted to you) You got commended by your teacher for helping out!" << endl;				
			}
			else if ( choice == 3 ) {
				cout << "Oh no, he lost his mind and started swinging wildly at you! You sustained minor injuries..." << endl;
				cout << "<-1 health>" << endl;
				updateStats( s, -1, 0, 0 );

				// save game
				fout << endl << "Choice: laugh at him!" << endl;
				fout << "Oh no, he lost his mind and started swinging wildly at you! You sustained minor injuries..." << endl;
			}
			break;
		
		case 3:
			cout << "1: secretly use your mom's makeup to cover up the acne." << endl;
			cout << "2: didn’t do anything about it because you wanted to be able to look back at your ID photo in the future and have nostalgic memories of your days of puberty." << endl;
			cout << "3: cancelled the photoshoot appointment at the last minute." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "You ended up looking like a vampire in the photo because you overdid the makeup... (so do you prefer acne now?)" << endl;
				cout << "<-1 happiness>" << endl;
				updateStats( s, 0, 0, -1 );

				// save game
				fout << endl << "Choice: secretly use your mom's makeup to cover up the acne." << endl;
				fout << "You ended up looking like a vampire in the photo because you overdid the makeup... (so do you prefer acne now?)" << endl;	
			}
			else if ( choice == 2 ) {
				cout << "You got your wish and ended up with an ultra HD photo of your acne-infested face on your ID." << endl;
				cout << "<+1 happiness>" << endl;
				updateStats( s, 0, 0, 1 );

				// save game
				fout << endl << "Choice: didn’t do anything about it because you wanted to be able to look back at your ID photo in the future and have nostalgic memories of your days of puberty." << endl;
				fout << "You got your wish and ended up with an ultra HD photo of your acne-infested face on your ID." << endl;
			}
			else if ( choice == 3 ) {
				cout << "Your typical asian mom went nuts and started blabbering about how irresponsible you were and how ‘money doesn’t grow on trees’. You ended up having to pay for the photoshoot the next time you went..." << endl;
				cout << "<-1 money>" << endl;
				updateStats( s, 0, -1, 0 );

				// save game
				fout << endl << "Choice: cancelled the photoshoot appointment at the last minute." << endl;
				fout << "Your typical asian mom went nuts and started blabbering about how irresponsible you were and how ‘money doesn’t grow on trees’. You ended up having to pay for the photoshoot the next time you went..." << endl;				
			}
			break;
		
		case 4:
			cout << "1: to the mall." << endl;
			cout << "2: food hunting!" << endl;
			cout << "3: hiking." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "It was just a normal outing with the classic shopping and boring stuff... (why'd you choose the most cliche choice?)" << endl;
				cout << "<-1 money>" << endl;
				updateStats( s, 0, -1, 0 );

				// save game
				fout << endl << "Choice: to the mall." << endl;
				fout << "It was just a normal outing with the classic shopping and boring stuff... (why'd you choose the most cliche choice?)" << endl;
			}
			else if ( choice == 2 ) {
				cout << "You guys had a blast tasting the best Hong Kong street foods around Hong Kong Island! (HI THERE FELLOW FOODIEE :D)" << endl;
				cout << "<-1 money, +1 happiness>" << endl;
				updateStats( s, 0, -1, 1 );

				// save game
				fout << endl << "Choice: food hunting!" << endl;
				fout << "You guys had a blast tasting the best Hong Kong street foods around Hong Kong Island! (HI THERE FELLOW FOODIEE :D)" << endl;
			}
			else if ( choice == 3 ) {
				cout << "You guys had an amazing time watching the sunrise and scenic views at Dragon’s Back!" << endl;
				cout << "<+1 health, -1 money, +1 happiness>" << endl;
				updateStats( s, 1, -1, 1 );

				// save game
				fout << endl << "Choice: hiking." << endl;
				fout << "You guys had an amazing time watching the sunrise and scenic views at Dragon’s Back!" << endl;				
			}
			break;

		case 5:
			cout << "1: join them!" << endl;
			cout << "2: threaten to report them to the principal." << endl;
			cout << "3: ignore them and keep walking..." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "When you got home, your typical asian mom’s ULTRA sensitive smelling senses picked up the smokey smell exuding from your clothes. You had a rough beating and got grounded from video games for a YEAR... (HAHA serves you right!)" << endl;
				cout << "<-2 health, -1 happiness>" << endl;
				updateStats( s, -2, 0, -1 );

				// save game
				fout << endl << "Choice: join them!" << endl;
				fout << "When you got home, your typical asian mom’s ULTRA sensitive smelling senses picked up the smokey smell exuding from your clothes. You had a rough beating and got grounded from video games for a YEAR... (HAHA serves you right!)" << endl;								
			}
			else if ( choice == 2 ) {
				cout << "They beat you up and extorted your money. (why in the world would you do that?!)" << endl;
				cout << "<-1 health, -1 money>" << endl;
				updateStats( s, -1, -1, 0 );

				// save game
				fout << endl << "Choice: threaten to report them to the principal." << endl;
				fout << "They beat you up and extorted your money. (why in the world would you do that?!)" << endl;
			}
			else if ( choice == 3 ) {
				cout << "Well, nothing happened :D" << endl;
				cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: ignore them and keep walking..." << endl;
				fout << "Well, nothing happened :D" << endl;
			}
			break;

		case 6:
			cout << "1: sighed and obeyed..." << endl;
			cout << "2: yelled at her and told her that she had to drag you there to get you to go." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "She was really happy you didn’t act up and increased your allowance!" << endl;
				cout << "<+1 money, +1 happiness>" << endl;
				updateStats( s, 0, 1, 1 );

				// save game 
				fout << endl << "Choice: sighed and obeyed..." << endl;
				fout << "She was really happy you didn’t act up and increased your allowance!" << endl;
			}
			else if ( choice == 2 ) {
				cout << "She got really mad and threatened to disown you if you didn’t go. Also, she confiscated your laptop and you couldn’t play Fortnite for a week." << endl;
				cout << "<-1 happiness>" << endl;
				updateStats( s, 0, 0, -1 );

				// save game 
				fout << endl << "Choice: yelled at her and told her that she had to drag you there to get you to go." << endl;
				fout << "She got really mad and threatened to disown you if you didn’t go. Also, she confiscated your laptop and you couldn’t play Fortnite for a week." << endl;				
			}
			break;

		case 7:
			cout << "1: gamed all day on your computer." << endl;
			cout << "2: went to your friend's house for sleepovers!" << endl;
			cout << "3: locked yourself in your bedroom because you were paranoid of thieves breaking in and kidnapping you." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "You ended up gaining 5 pounds because you basically didn’t budge from your seat except to get instant noodles from the kitchen. It was the best few days of your life though!" << endl;
				cout << "<-1 health, +2 happiness>" << endl;
				updateStats( s, -1, 0, 2 );

				// save game
				fout << endl << "Choice: gamed all day on your computer." << endl;
				fout << "You ended up gaining 5 pounds because you basically didn’t budge from your seat except to get instant noodles from the kitchen. It was the best few days of your life though!" << endl;				
			}
			else if ( choice == 2 ) {
				cout << "You had a blast playing and going out with your friend, but ended up broke..." << endl;
				cout << "<-2 money, +2 happiness>" << endl;
				updateStats( s, 0, -2, 2 );

				// save game
				fout << endl << "Choice: went to your friend's house for sleepovers!" << endl;
				fout << "You had a blast playing and going out with your friend, but ended up broke..." << endl;				
			}
			else if ( choice == 3 ) {
				cout << "You fell into depression because you had zero social interaction with anyone..." << endl;
				cout << "<-2 happiness>" << endl;
				updateStats( s, 0, 0, -2 );

				// save game
				fout << endl << "Choice: locked yourself in your bedroom because you were paranoid of thieves breaking in and kidnapping you." << endl;
				fout << "You fell into depression because you had zero social interaction with anyone..." << endl;				
			}
			break;

		case 8:
			cout << "1: piano." << endl;
			cout << "2: guitar." << endl;
			cout << "3: violin." << endl;
			cout << "4: drums." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "Wow! Typical asian choice huh?" << endl;
				cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: piano." << endl;
				fout << "Wow! Typical asian choice huh?" << endl;				
			}
			else if ( choice == 2 ) {
				cout << "Dangg, so you're already thinking of serenading your future partner... SMART CHOICE!" << endl;
				cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: guitar." << endl;
				fout << "Dangg, so you're already thinking of serenading your future partner... SMART CHOICE!" << endl;
			}
			else if ( choice == 3 ) {
				cout << "Unconventional choice, but I respect that!" << endl;
				cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: violin." << endl;
				fout << "Unconventional choice, but I respect that!" << endl;
			}
			else if ( choice == 4 ) {
				cout << "Are you by any chance a fan of Hard Rock or Metal music?? xD" << endl;
				cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: drums." << endl;
				fout << "Are you by any chance a fan of Hard Rock or Metal music?? xD" << endl;
			}
			break;

		case 9:
			cout << "1: run to the toilet." << endl;
			cout << "2: stay put and hope for the best." << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if ( choice == 1 ) {
				cout << "You ended up relieving yourself but unfortunately left the last page of your paper blank. Your mom blamed you for eating 'rubbish' food and gave you a huge life lesson talk..." << endl;
				cout << "<-1 happiness>" << endl;
				updateStats( s, 0, 0, -1 );

				// save game
				fout << endl << "Choice: run to the toilet." << endl;
				fout << "You ended up relieving yourself but unfortunately left the last page of your paper blank. Your mom blamed you for eating 'rubbish' food and gave you a huge life lesson talk..." << endl;
			}
			else if ( choice == 2 ) {
				cout << "You managed to finish the paper but unfortunately you couldn’t hold it in. Your friends made fun of you but to be fair, your mom rewarded you for getting full marks." << endl;
				cout << "<+1 money, -1 happiness>" << endl;
				updateStats( s, 0, 1, -1 );

				// save game
				fout << endl << "Choice: stay put and hope for the best." << endl;
				fout << "You managed to finish the paper but unfortunately you couldn’t hold it in. Your friends made fun of you but to be fair, your mom rewarded you for getting full marks." << endl;				
			}
			break;
	}

	return;
}

// outputs the results of events at ages 19, 20 & 22
// inputs: chosen index, player's stats as a pass-by reference
void resultsEvents19_20_22( int index, Stats &s, ofstream & fout ) {
  int choice;
  cout << "Please enter the choice number when prompted!" << endl;
  cout << "--------------------------------------------------" << endl;
  switch ( index ) {
    case 0:
      cout << "1. Basketball club." << endl; 
      cout << "2. Book club." << endl;
      cout << "3. Don't join anything." << endl;
      cout << "4. Use the time to go “club”-bing." << endl;
      cout << "Enter choice: ";
      cin >> choice;

      if ( choice == 1 ) {
        updateStats( s, 1, 0, 0 );
        cout << "<+1 health>" << endl;

				// save game
				fout << "You chose the basketball club." << endl; 
      }
      else if ( choice == 2 ) {
        updateStats( s, 0, 0, 1 );
        cout << "<+1 happiness>" << endl;

				// save game
				fout << "You chose the book club." << endl;
      }
      else if ( choice == 3 ) {
        cout << "<no effect>" << endl;

				// save game
				fout << "You didn't join any clubs." << endl;
      }
      else if ( choice == 4 ) {
        cout << "<-1 health, -1 money>" << endl;
        updateStats(s, -1, -1, 0);

				//save game
				fout << "You chose to go clubbing instead." << endl;
      }
      break;

    case 1:
      cout << "1. Skip the exam." << endl;
      cout << "2. Cheat." << endl;
      cout << "3. Pay someone to do it for you." << endl;
      cout << "4. Do it anyway." << endl;
      cout << "Enter choice: ";
      cin >> choice;

      if ( choice == 1 ) {
        cout << "You got 0 for the exam... obviously.." << endl;
        updateStats( s, 0, 0, -1 );
        cout << "<-1 happiness>" << endl;

				// save game
				fout << endl << "Choice: Skip the exam." << endl;
				fout << "You got 0 for the exam... obviously.." << endl;
      }
      else if ( choice == 2 ) {
        cout << "You got found out and got suspended!" << endl;
        updateStats( s, 0, 0, -1 );
        cout << "<-1 happiness>" << endl;

				// save game
				fout << endl << "Choice: Cheat." << endl;
				fout << "You got found out and got suspended!" << endl;
      }
      else if ( choice == 3 ) {
        cout << "Wow! You got an A* (although it wasn't your work)!" << endl;
        updateStats( s, 0, -1, 0 );
        cout << "<-1 money>" << endl;

				// save game
				fout << endl << "Choice: Pay someone to do it for you." << endl;
				fout << "Wow! You got an A* (although it wasn't your work)!" << endl;
      }
      else if ( choice == 4 ) {
        cout << "Turns out you did okay and barely passed!" << endl;
        cout << "<no effect>" << endl;

				// save game
				fout << endl << "Choice: Do it anyway." << endl;
				fout << "Turns out you did okay and barely passed!" << endl;
      }
      break;

    case 2:
      cout << "1. See the doctor." << endl;
      cout << "2. Search Google for a treatment." << endl;
      cout << "3. Ignore it." << endl;
      cout << "4. Take some medicine on your own." << endl;
      cout << "Enter choice: ";
      cin >> choice;

      if ( choice == 1 ) {
        cout << "The doctor treated you, but it turns out his services were way too expensive!" << endl;
        updateStats( s, 1, -1, 0 );
        cout << "<+1 health, -1 money>" << endl;

				// save game
				fout << endl << "Choice: See the doctor." << endl;
				fout << "The doctor treated you, but it turns out his services were way too expensive!" << endl;
      }
      else if ( choice == 2 ) {
        cout << "Google said you have cancer and will die in 2 days, now you’re just depressed.." << endl;
        updateStats( s, 0, 0, -1 );
        cout << "<-1 happiness>" << endl;

				// save game
				fout << endl << "Choice: Search Google for a treatment." << endl;
				fout << "Google said you have cancer and will die in 2 days, now you’re just depressed.." << endl;
      }
      else if ( choice == 3 ) {
        cout << "Your stomach ache got worse and now you’re just depressed.." << endl;
        updateStats( s, 0, 0, -1 );
        cout << "<-1 happiness>" << endl;

				// save game
				fout << endl << "Choice: Ignore it." << endl;
				fout << "Your stomach ache got worse and now you’re just depressed.." << endl;
      }
      else if ( choice == 4 ) {
        cout << "You’re fine now, but you had to buy more medicine.." << endl;
        updateStats( s, 0, -1, 0 );
        cout << "<-1 money>" << endl;

				// save game
				fout << endl << "Choice: Take some medicine on your own." << endl;
				fout << "You’re fine now, but you had to buy more medicine.." << endl;
      }
      break;

    case 3:
      cout << "1. Reject her, they’re too good for me." << endl;
      cout << "2. Accept and start dating." << endl;
      cout << "Enter choice: ";
      cin >> choice;

      if ( choice == 1 ) {
        cout << "Dude.. seriously??" << endl;
        updateStats( s, 0, 0, -1 );
        cout << "<-1 happiness but you deserve -100 for your stupidity..>" << endl;

				// save game
				fout << endl  << "Choice: Reject her, they’re too good for me." << endl;
				fout << "Dude.. seriously??" << endl;
      }
      else if ( choice == 2 ) {
        cout << "Great choice! I thought you were gonna pick 1 for a second there.." << endl;
        updateStats( s, 0, 0, 1 );
        cout << "<+1 happiness, you feel like you're on top of the world!>" << endl;

				// save game
				fout << endl << "Choice: Accept and start dating." << endl;
				fout << "Great choice! I thought you were gonna pick 1 for a second there.." << endl;
      }
      break;

    case 4:
      cout << "1. Thanos dies!" << endl;
      cout << "2. Thanos lives and he makes friends with the Avengers." << endl;
      cout << "3. Thanos made Black Widow and Scarlet Witch his girlfriends." << endl;
      cout << "4. Thor comes in with a new weapon and tries to cut Thanos’s head off but misses. Thanos snaps and wins." << endl;
      cout << "Enter choice: ";
      cin >> choice;

      if ( choice == 1 ) {
        cout << "Nah fam he lives, but good guess!" << endl;
        updateStats( s, 0, -1, 0 );
        cout << "<-1 money>" << endl;

				// save game
				fout << endl << "Choice: Thanos dies!" << endl;
				fout << "Nah fam he lives, but good guess!" << endl;
      }
      else if ( choice == 2 ) {
        cout << "Wow! You actually got it right!" << endl;
        updateStats( s, 0, 1, 0 );
        cout << "<+1 money>" << endl;

				// save game
				fout << endl << "Choice: Thanos lives and he makes friends with the Avengers." << endl;
				fout << "Wow! You actually got it right!" << endl;
      }
      else if ( choice == 3 ) {
        cout << "Bruh what..?" << endl;
        updateStats( s, 0, -1, 0 );
        cout << "<-1 money, and all your friends think you're weird>" << endl;

				// save game
				fout << endl << "Choice: Thanos made Black Widow and Scarlet Witch his girlfriends." << endl;
				fout << "Bruh what..? All your friends think you're weird." << endl;
      }
      else if ( choice == 4 ) {
        cout << "Sike! That didn't happen in this world!" << endl;
        updateStats( s, 0, -1, 0 );
        cout << "<-1 money>" << endl;

				// save game
				fout << endl << "Choice: Thor comes in with a new weapon and tries to cut Thanos’s head off but misses. Thanos snaps and wins." << endl;
				fout << "Sike! That didn't happen in this world!" << endl;
      }
      break;

    case 5:
      cout << "1. Befriend him as a casual friend." << endl;
      cout << "2. Nah, I have enough friends. Also, what kinda name is that??" << endl;
      cout << "3. Befriend him and make him your best friend." << endl;
      cout << "Enter choice: ";
      cin >> choice;

      if ( choice == 1 ) {
        cout << "Wise choice, but I can’t tell you why yet…" << endl;
        updateStats( s, 0, 0, 1 );
        cout << "<+1 happiness>" << endl;

				// save game
				fout << endl << "Choice: Befriend him as a casual friend." << endl;
				fout << "Wise choice, but I can’t tell you why yet…" << endl;
      }
      else if ( choice == 2 ) {
        cout << "You’ll regret that decision…" << endl;
        updateStats( s, 0, 0, -1 );
        cout << "<-1 happiness>" << endl;

				// save game
				fout << endl << "Choice: Nah, I have enough friends. Also, what kinda name is that??" << endl;
        fout << "You’ll regret that decision…" << endl;
				
      }
      else if ( choice == 3 ) {
        cout << "You guys are great friends and one day Elongated tells you that he wants to start 2 companies - one for electric cars " << endl;
        cout << "and another space company. You tell him he’s crazy but you invest some money anyways." << endl;
        updateStats( s, 0, 0, 1 );
        cout << "<+1 happiness, and more to come!>" << endl;

				// save game
				fout << endl << "Choice: Befriend him and make him your best friend." << endl;
        fout << "You guys are great friends and one day Elongated tells you that he wants to start 2 companies - one for electric cars " << endl;
        fout << "and another space company. You tell him he’s crazy but you invest some money anyways." << endl;
      }
      break;
  }

	return;
}