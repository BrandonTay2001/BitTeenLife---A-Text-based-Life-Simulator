/*
FILE: contains all functions for ages 13, 18
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
FUNCTION: deals with all events at Age 13
INPUT(s):
1. pass-by-reference player stats
2. player name
3. pass-by-reference ofstream object for writing game progress to <tempfile>
OUTPUT(s):
1. Events at Age 13
*/
void Events13 ( Stats &s, string name, ofstream & fout ) {
	int * choice = new int( 0 ); // dynamic variable for storing user choice

	for ( int i = 0; i < 3; ++i ) {
		// 1st event
		if ( i == 0 ) {
			fout << "[ Event 1 ]" << endl;
			if ( s.happiness == 2 ) {
				cout << "You’re high on happiness and became the class clown for the day. At the end of the day, your crush came and told you that they found you really funny. You" << endl;
				cout << "1: blushed and acted really shy." << endl;
				cout << "2: immediately confessed to them because your confidence level was boosted from all the compliments you were getting." << endl;
				cout << "3: responded casually and offered to buy them their favourite snack." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You’re high on happiness and became the class clown for the day. At the end of the day, your crush came and told you that they found you really funny. You ";

				if ( * choice == 1 ) {
					cout << "They made a disgusted face at you because they disliked shy people. Your inflated ego got deflated instantly and you became a lazy couch potato." << endl;
					cout << "<-1 health, -1 happiness>" << endl;
					updateStats( s, -1, 0, -1 );

					fout << endl << "Choice: blushed and acted really shy." << endl;
          fout << "They made a disgusted face at you because they disliked shy people. Your inflated ego got deflated instantly and you became a lazy couch potato." << endl;
				}
				else if ( * choice == 2 ) {
					cout << "They friendzoned you on the spot and now you’re just depressed..." << endl;
					cout << "<-2 happiness>" << endl;
					updateStats( s, 0, 0, -2 );

					fout << endl << "Choice: immediately confessed to them because your confidence level was boosted from all the compliments you were getting." << endl;
					fout << "They friendzoned you on the spot and now you’re just depressed..." << endl;
				}
				else if ( *choice == 3 ) {
					cout << "They accepted your offer but later bro-zoned you..." << endl;
					cout << "<-1 money, -1 happiness>" << endl;
					updateStats( s, 0, -1, -1 );

					fout << endl << "Choice: responded casually and offered to buy them their favourite snack." << endl;
					fout << "They accepted your offer but later bro-zoned you..." << endl;						
				}
			}
			else if ( s.money == 2 ) {
				cout << "You’re filthy rich because you’ve been saving up a ton of your allowance. You decided to" << endl;
				cout << "1: buy the latest limited edition Yeezy worn by Egg Sheeran to show off to your friends." << endl;
				cout << "2: take your foodie crush on a full day of food hunting even though you were borderline obese and were on a diet." << endl;
				cout << "3: save it up in your old trusty piggy bank like a responsible kid." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

         fout << "You’re filthy rich because you’ve been saving up a ton of your allowance. You decided to ";

				if ( * choice == 1 ) {
					cout << "You became more popular at school and you noticed your crush (who was secretly a gold digger) smiling at you more!" << endl;
					cout << "<-2 money, +1 happiness>" << endl;
					updateStats( s, 0, -2, 1 );

          fout << endl << "Choice: buy the latest limited edition Yeezy worn by Egg Sheeran to show off to your friends." << endl;
					fout << "You became more popular at school and you noticed your crush (who was secretly a gold digger) smiling at you more!" << endl;
					}
				else if ( * choice == 2 ) {
					cout << "At the end of the day, they told you they thought you were a reaaally good friend and now you’re just depressed..." << endl;
					cout << "<-1 health, -1 money, -1 happiness>" << endl;
					updateStats( s, -1, -1, -1 );

          fout << endl << "Choice: take your foodie crush on a full day of food hunting even though you were borderline obese and were on a diet." << endl;
					fout << "At the end of the day, they told you they thought you were a reaaally good friend and now you’re just depressed..." << endl;
					}
				else if ( * choice == 3 ) {
					cout << "One night, a thief broke into your house through your window and demanded you of your piggy bank. Now you're traumatized and broke..." << endl;
					cout << "<-2 money, -2 happiness>" << endl;
					updateStats( s, 0, -2, -2 );

          fout << endl << "Choice: save it up in your old trusty piggy bank like a responsible kid." << endl;
					fout << "One night, a thief broke into your house through your window and demanded you of your piggy bank. Now you're traumatized and broke..." << endl;
				}
			}
			else if ( s.health == 2 ) {
				cout << "You’re obsessed with running and are fit af. One day, you joined a 10k run and just before the finish line, you looked behind to see if anyone was behind you and fell into the roadside drain, twisting your ankle really badly. You" << endl;
				cout << "1: get up and fight your way to the finish line in EPIC fashion just like you see in the movies." << endl;
				cout << "2: climb out of the drain miserably and wait for medical assistance..." << endl;
				cout << "Enter choice: ";
				cin >> * choice;
          
        fout << "You’re obsessed with running and are fit af. One day, you joined a 10k run and just before the finish line, you looked behind to see if anyone was behind you and fell into the roadside drain, twisting your ankle really badly. You ";

				if ( * choice == 1 ) {
					cout << "You ended up having to rest for a month and now you’re obese because your grandma who was a typical asian grandma took the opportunity to overfeed you everyday..." << endl;
					cout << "<-2 health>" << endl;
					updateStats( s, -2, 0, 0 );

          fout << endl << "Choice: get up and fight your way to the finish line in EPIC fashion just like you see in the movies." << endl;
					fout << "You ended up having to rest for a month and now you’re obese because your grandma who was a typical asian grandma took the opportunity to overfeed you everyday..." << endl;
					}
				else if ( * choice == 2 ) {
					cout << "Your crush saw you being treated and limping away on crutches and you regretted not toughing it out." << endl;
					cout << "<-1 health, -1 happiness>" << endl;
					updateStats( s, -1, 0, -1 );

          fout << endl << "Choice: climb out of the drain miserably and wait for medical assistance..." << endl;
					fout << "Your crush saw you being treated and limping away on crutches and you regretted not toughing it out." << endl;
				}
			}
		}

		// 2nd event
		if ( i == 1 ) {
			fout << endl << "[ Event 2 ]" << endl;

			if ( s.health == 0 ) {
				cout << "Your immune system was so weak that you contracted the flu. Your mom wanted to bring you to see the doctor whom you found super creepy. You" << endl;
				cout << "1: went with her anyway." << endl;
				cout << "2: threw a tantrum (like the spoiled kid you were) and refused to go." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

        fout << "Your immune system was so weak that you contracted the flu. Your mom wanted to bring you to see the doctor whom you found super creepy. You ";

				if ( * choice == 1 ) {
					cout << "The doctor creeped you out even more by accidentally revealing his disgusting habit of eating his booger!" << endl;
					cout << "<+1 health, -1 happiness>" << endl;
					updateStats( s, 1, 0, -1 );

          fout << endl << "Choice: went with her anyway." << endl;
					fout << "The doctor creeped you out even more by accidentally revealing his disgusting habit of eating his booger!" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "Surprisingly, you got better on your own! (it’s your lucky day!)" << endl;
					cout << "<+1 health, +1 happiness>" << endl;
					updateStats( s, 1, 0, 1 );

          fout << endl << "Choice: threw a tantrum (like the spoiled kid you were) and refused to go." << endl;
					fout << "Surprisingly, you got better on your own! (it’s your lucky day!)" << endl;
				}
			}
			else if ( s.money == 0 ) {
				cout << "You’re broke and your mom forgot to give you your allowance for the week. However, you were starving during lunch break and coincidentally saw your favourite dim sum on the food counter which at the time was left unattended. You" << endl;
				cout << "1: sneak over, take the plate of dim sum and walk away casually." << endl;
				cout << "2: recall your mom telling you to always be a good kid and decide to listen to her for once." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

        fout << "You’re broke and your mom forgot to give you your allowance for the week. However, you were starving during lunch break and coincidentally saw your favourite dim sum on the food counter which at the time was left unattended. You ";

				if ( * choice == 1 ) {
					cout << "You had food poisoning a minute into the meal. (you never learn do you? INSTANT KARMA!)" << endl;
					cout << "<-1 health>" << endl;
					updateStats( s, -1, 0, 1 );

          fout << endl << "Choice: sneak over, take the plate of dim sum and walk away casually." << endl;
					fout << "You had food poisoning a minute into the meal. (you never learn do you? INSTANT KARMA!)" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "Another kid stole the plate of dim sum and now you’re depressed for being a good kid. (your mom gave you extra allowance when you told her what happened though, so...) " << endl;
					cout << "<+1 money, -1 happiness>" << endl;
					updateStats( s, 0, 1, -1 );
	
          fout << endl << "Choice: recall your mom telling you to always be a good kid and decide to listen to her for once. " << endl;
					fout << "Another kid stole the plate of dim sum and now you’re depressed for being a good kid. (your mom gave you extra allowance when you told her what happened though, so...)" << endl;
				}
			}
			else if ( s.happiness == 0 ) {
				cout << "You were being bullied and made fun of by your classmate for being depressed. You decide to fight back, and" << endl;
				cout << "1: punched them in their backside." << endl;
				cout << "2: slapped them in their fat belly." << endl;
				cout << "3: kicked them in their you know..." << endl;
				cout << "Enter choice: ";
				cin >> * choice;
				cout << "You got sent to the principal’s office for your BRUTAL actions. However, you felt really good and got cured of your depression. Congrats!" << endl;
				cout << "<+1 happiness>" << endl;
				updateStats( s, 0, 0, 1 );

				fout << "You were being bullied and made fun of by your classmate for being depressed. You decide to fight back, and ";
				if ( * choice == 1 ) {
					fout << endl << "Choice: punched them in their backside." << endl;
				}
				else if ( * choice == 2 ) {
					fout << endl << "Choice: slapped them in their fat belly." << endl;
				}
				else if ( * choice == 3 ) {
					fout << endl << "Choice: kicked them in their you know..." << endl;
				}
			
				fout << "You got sent to the principal’s office for your BRUTAL actions. However, you felt really good and got cured of your depression. Congrats!" << endl;
			}
		}

		// 3rd event
		if ( i == 2 ) {
			cout << "You just hit puberty and noticed pubic hair growing out of your armpits. You" << endl;
			cout << "1: take your dad’s shaver to shave it off." << endl;
			cout << "2: take a picture of it because you found it really interesting." << endl;
			cout << "3: brag to your friends in school about it." << endl;
			cout << "Enter choice: ";
			cin >> * choice;

      fout << endl << "[ Event 3 ]" << endl << "You just hit puberty and noticed pubic hair growing out of your armpits. You ";

			if ( * choice == 1 ) {
				cout << "You had a bad itch and couldn’t stop scratching your armpits wherever you went. Your arch enemy in school made fun of you and called you a baboon. You" << endl;
				cout << "1: had a scuffle with him." << endl;
				cout << "2: kept your calm and devised a revenge plan." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

        fout << endl << "Choice: take your dad’s shaver to shave it off." << endl;
				fout << "You had a bad itch and couldn’t stop scratching your armpits wherever you went. Your arch enemy in school made fun of you and called you a baboon. You ";

				if ( * choice == 1 ) {
					cout << "During the scuffle, you managed to get his shirt off, exposing his bare armpits to the entire class who then made fun of him. You got sent to the principal’s office for fighting in school, and had to repay him for tearing his shirt. BUT, you had absolutely no regrets because you had the time of your life!" << endl;
					cout << "<-1 money, +2 happiness>" << endl;
					updateStats( s, 0, -1, 2 );
								
          fout << endl << "Choice: had a scuffle with him." << endl;
					fout << "During the scuffle, you managed to get his shirt off, exposing his bare armpits to the entire class who then made fun of him. You got sent to the principal’s office for fighting in school, and had to repay him for tearing his shirt. BUT, you had absolutely no regrets because you had the time of your life!" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "Smart choice! You went home later that day, dug up an old deleted post of him acting like a gorilla, and shared it on instagram. Everyone made fun of him in the comments and you gained more followers." << endl;
					cout << "<+1 happiness>" << endl;
					updateStats( s, 0, 0, 1 );

          fout << endl << "Choice: kept your calm and devised a revenge plan." << endl;
					fout << "Smart choice! You went home later that day, dug up an old deleted post of him acting like a gorilla, and shared it on instagram. Everyone made fun of him in the comments and you gained more followers." << endl;
				}
			}
			else if ( * choice == 2 ) {
				cout << "Your evil brother secretly took your phone and found the photo. He then posted it on instagram and all his followers saw it. You" << endl;
				cout << "1: took revenge on him by posting a picture of him sleeping shirtless a few weeks back." << endl;
				cout << "2: told your parents about it." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << " take a picture of it because you found it really interesting." << endl;
				fout << "Your evil brother secretly took your phone and found the photo. He then posted it on instagram and all his followers saw it. You ";

				if ( * choice == 1 ) {
					cout << "He beat you up and took your money. Now you’re broke but you felt good anyways because his girlfriend broke up with him for not having sweet abs!" << endl;
					cout << "<-2 money, +1 happiness>" << endl;
					updateStats( s, 0, -2, 1 );

					fout << endl << "Choice: took revenge on him by posting a picture of him sleeping shirtless a few weeks back." << endl;
					fout << "He beat you up and took your money. Now you’re broke but you felt good anyways because his girlfriend broke up with him for not having sweet abs!" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "Your parents scolded him and made him delete the post. You laughed at him getting scolded." << endl;
					cout << "<+1 happiness>" << endl;
					updateStats( s, 0, 0, 1 );

					fout << endl << "Choice: told your parents about it." << endl;
					fout << "Your parents scolded him and made him delete the post. You laughed at him getting scolded." << endl;
				}
			}
			else if ( * choice == 3 ) {
				cout << "Your friends started showing off their armpit hair too and soon it became a competition as to who had the 'bushiest' armpits. You were really competitive and so the next day before school, you" << endl;
				cout << "1: super-glued fake hair to your armpits." << endl;
				cout << "2: decided to embarrass the other kids who were showing off their armpit hair by secretly taking photos of them in the act." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << endl << "Choice: brag to your friends in school about it." << endl;
				fout << "Your friends started showing off their armpit hair too and soon it became a competition as to who had the 'bushiest' armpits. You were really competitive and so the next day before school, you ";

				if ( * choice == 1 ) {
					cout << "CONGRATS, you won the armpit hair competition! Butttt, unfortunately you lost all your armpit hair while trying to pull out the super-glued hair and now you’re depressed :D" << endl;
					cout << "<-2 happiness>" << endl;
					updateStats( s, 0, 0, -2 );

					fout << endl << "Choice: super-glued fake hair to your armpits." << endl;
					fout << "CONGRATS, you won the armpit hair competition! Butttt, unfortunately you lost all your armpit hair while trying to pull out the super-glued hair and now you’re depressed :D" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "You got sent to the principal’s office for bringing your phone to school. Your principal was scolding your butt off and you" << endl;
					cout << "1: insulted him and called him a baldy. (because he was bald and that was the best insult you could think of at that time)" << endl;
					cout << "2: expressed regret and apologized to him." << endl;
					cout << "3: put on an epic show of an emotional breakdown." << endl;
					cout << "Enter choice: ";
					cin >> * choice;

					fout << endl << "Choice: decided to embarrass the other kids who were showing off their armpit hair by secretly taking photos of them in the act." << endl;
					fout << "You got sent to the principal’s office for bringing your phone to school. Your principal was scolding your butt off and you ";

					if ( * choice == 1 ) {
						cout << "He made you take off your pants for a caning but you couldn't care less because your popularity sky-rocketed for being the first person to dare insult the principal." << endl;
						cout << "<+2 happiness>" << endl;
						updateStats( s, 0, 0, 2 );

						fout << endl << "Choice: insulted him and called him a baldy. (because he was bald and that was the best insult you could think of at that time)" << endl;
						fout << "He made you take off your pants for a caning but you couldn't care less because your popularity sky-rocketed for being the first person to dare insult the principal." << endl;
					}
					else if ( * choice == 2 ) {
						cout << "He became more gentle but still told your mom about it, who then caned you at home. (so sometimes being a good kid doesn’t pay off huh...)" << endl;
						cout << "<-1 happiness>" << endl;
						updateStats( s, 0, 0, -1 );

						fout << endl << "Choice: expressed regret and apologized to him." << endl;
						fout << "He became more gentle but still told your mom about it, who then caned you at home. (so sometimes being a good kid doesn’t pay off huh...)" << endl;							
					}
					else if ( * choice == 3 ) {
						cout << "He started to panic and tried comforting you. (ahh, the classic fake crying worked this time...)" << endl;
						cout << "<+1 happiness>" << endl;
						updateStats( s, 0, 0, 1 );

						fout << endl << "Choice: put on an epic show of an emotional breakdown." << endl;
						fout << "He started to panic and tried comforting you. (ahh, the classic fake crying worked this time...)" << endl;		
					}
				}
			}
		}
		printStats( s, name );
	}

	delete choice; // frees memory allocated to dynamic variable

	return;
}

/*
FUNCTION: deals with all events at Age 18
INPUT(s):
1. pass-by-reference player stats
2. player name
3. pass-by-reference ofstream object for writing game progress to <tempfile>
OUTPUT(s):
1. Events at Age 18
*/
void Events18 ( Stats &s, string name, ofstream & fout ) {
	int * choice = new int( 0 ); // dynamic variable for storing user choice

	for ( int i = 0; i < 3; ++i ) {
		// 1st Event
		if ( i == 0 ) {
			cout << "Ever since you were a kid, you had EPIC plans for your 18th birthday and IT’S YOUR BIRTHDAY!" << endl;
				
			fout << "[ Event 1 ]" << endl << "Ever since you were a kid, you had EPIC plans for your 18th birthday and IT’S YOUR BIRTHDAY!" << endl;

			if ( s.money == 0 ) {
				cout << "You made terrible life decisions and spent all your money. Now you’re broke... Weirdly, your childhood rival offered you a half day job as a waiter at his dad’s restaurant ‘Ain’t Nobody Got Thai For That!’. You" << endl;
				cout << "1: accept his offer." << endl;
				cout << "2: reject his offer." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You made terrible life decisions and spent all your money. Now you’re broke... Weirdly, your childhood rival offered you a half day job as a waiter at his dad’s restaurant ‘Ain’t Nobody Got Thai For That!’. You ";				

				if ( * choice == 1 ) {
					cout << "YOU GOT TROLLED. He made you wear a fake clowney waiter uniform and invited all his friends to see you working in it. You" << endl;
					cout << "1: messed him up real bad in front of everyone and left him crying for his momma." << endl;
					cout << "2: endured the embarrassment and get your paycheck at the end of job." << endl;
					cout << "3: walk out of there casually." << endl;
					cout << "Enter choice: ";
					cin >> * choice;

					fout << endl << "Choice: accept his offer." << endl;
					fout << "YOU GOT TROLLED. He made you wear a fake clowney waiter uniform and invited all his friends to see you working in it. You ";

					if ( * choice == 1 ) {
						cout << "You got chased out of the restaurant by his momma without getting paid and ended up not having an epic birthday celebration. But hey, at least you had tons of fun making him beg for his momma to save his ass right? xD" << endl;
						cout << "<+1 happiness>" << endl;
						updateStats( s, 0, 0, 1 );

						fout << endl << "Choice: messed him up real bad in front of everyone and left him crying for his momma." << endl;
						fout << "You got chased out of the restaurant by his momma without getting paid and ended up not having an epic birthday celebration. But hey, at least you had tons of fun making him beg for his momma to save his ass right? xD" << endl;												
					}
					else if ( * choice == 2 ) {
						cout << "You threw your epic birthday party at his dad’s restaurant because he got forced by his mom to be a waiter for the next half of the day. You got back at him by treating him like your slave for the entire night." << endl;
						cout << "<+1 happiness>" << endl;
						updateStats( s, 0, 0, 1 );

						fout << endl << "Choice: endured the embarrassment and get your paycheck at the end of job." << endl;
						fout << "You threw your epic birthday party at his dad’s restaurant because he got forced by his mom to be a waiter for the next half of the day. You got back at him by treating him like your slave for the entire night." << endl;							
					}
					else if ( * choice == 3 ) {
						cout << "You were kinda regretting not having gotten your paycheck but IT’S YOUR LUCKY DAY because you found a 100 dollar note on the ground just outside the restaurant and used it to throw your epic birthday party." << endl;
						cout << "<+1 happiness>" << endl;
						updateStats( s, 0, 0, 1 );

						fout << endl << "Choice: walk out of there casually." << endl;
						fout << "You were kinda regretting not having gotten your paycheck but IT’S YOUR LUCKY DAY because you found a 100 dollar note on the ground just outside the restaurant and used it to throw your epic birthday party." << endl;		
					}
				}
				else if ( * choice == 2 ) {
					cout << "You found out later that day that he actually had good intentions and had already prepared a 1000 dollar paycheck for you. Now you’re not only broke, you’re depressed too... Sad birthday huh :')" << endl;
					cout << "<-2 happiness>" << endl;
					updateStats( s, 0, 0, -2 );

					fout << endl << "Choice: reject his offer." << endl;
					fout << "You found out later that day that he actually had good intentions and had already prepared a 1000 dollar paycheck for you. Now you’re not only broke, you’re depressed too... Sad birthday huh :')" << endl;						
				}
			}
			else if ( s.money == 1 ) {
				cout << "You only have enough money to throw a normal birthday party and you" << endl;
				cout << "1: decide to borrow money from a 'legal money lender'" << endl;
				cout << "2: decide to be a normal kid and have a humble birthday party" << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You only have enough money to throw a normal birthday party and you ";			

				if ( * choice == 1 ) {
					cout << "You threw your epic birthday party and was having a blast but halfway through it, the ‘ah long’ busted in and demanded his money back. You" << endl;
					cout << "1: signalled your friends to go to 'war'." << endl;
					cout << "2: borrowed money from your friends to pay him back." << endl;
					cout << "3: run out of the place." << endl;
					cout << "Enter choice: ";
					cin >> * choice;

					fout << endl << "Choice: decide to borrow money from a 'legal money lender'." << endl;		
					fout << "You threw your epic birthday party and was having a blast but halfway through it, the ‘ah long’ busted in and demanded his money back. You ";

					if ( * choice == 1 ) {
						cout << "Unfortunately, you had fake friends and they ran out on you. You ended up having to call your parents to settle the loan..." << endl;
						cout << "<-2 money, -1 happiness>" << endl;
						updateStats( s, 0, -2, -1 );

						fout << endl << "Choice: signalled your friends to go to 'war'." << endl;		
						fout << "Unfortunately, you had fake friends and they ran out on you. You ended up having to call your parents to settle the loan..." << endl;												
					}
					else if ( * choice == 2 ) {
						cout << "Your friends didn’t have money on them but like in the movies, you guys' minds 'clicked' and magically decided to attack him together, overwhelming him instantly. You guys then ran off 'in the night', laughing and shouting like crazy maniacs from the adrenaline rush. (ahh... what an epic ending)" << endl;
						cout << "<+1 happiness>" << endl;
						updateStats( s, 0, 0, 1 );			

						fout << endl << "Choice: borrowed money from your friends to pay him back." << endl;		
						fout << "Your friends didn’t have money on them but like in the movies, you guys' minds 'clicked' and magically decided to attack him together, overwhelming him instantly. You guys then ran off 'in the night', laughing and shouting like crazy maniacs from the adrenaline rush. (ahh... what an epic ending)" << endl;										
					}
					else if ( * choice == 3 ) {
						cout << "You lost your friends but hey, at least you didn’t lose your money right? xD" << endl;
						cout << "<-1 happiness>" << endl;
						updateStats( s, 0, 0, -1 );		

						fout << endl << "Choice: run out of the place." << endl;
						fout << "You lost your friends but hey, at least you didn’t lose your money right? xD" << endl;							
					}
				}
				else if ( * choice == 2 ) {
					cout << "Your parents noticed your miserable behaviour and decided to sponsor your epic birthday party plans! (IT’S YOUR LUCKY DAY)" << endl;
					cout << "<+1 happiness>" << endl;
					updateStats( s, 0, 0, 1 );

					fout << endl << "Choice: decide to be a normal kid and have a humble birthday party." << endl;
					fout << "Your parents noticed your miserable behaviour and decided to sponsor your epic birthday party plans! (IT’S YOUR LUCKY DAY)" << endl;				
				}
			}
			else if ( s.money == 2 ) {
				cout << "Congratulations! You were wise in managing your finances and now you’re loaded. You decide to throw your birthday party at" << endl;
				cout << "1: a club" << endl;
				cout << "2: a fancy fine-dining restaurant." << endl;
				cout << "3: your house." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "Congratulations! You were wise in managing your finances and now you’re loaded. You decide to throw your birthday party at ";					
				if ( * choice == 1 ) {
					cout << "You spent all your money clubbing and got drunk af. Your friends posted a video of your drunk self and you got in trouble with your parents. They were scolding you and you" << endl;
					cout << "1: acted like a rebellious teenager and slammed your bedroom door in their faces." << endl;
					cout << "2: apologize to them and promise it’ll never happen again. (while secretly planning the next time you’d go clubbing cos you had wayyy too much fun xD)" << endl;
					cout << "Enter choice: ";
					cin >> * choice;

					fout << endl << "Choice: a club." << endl;		
					fout << "You spent all your money clubbing and got drunk af. Your friends posted a video of your drunk self and you got in trouble with your parents. They were scolding you and you ";								

					if ( * choice == 1 ) {
						cout << "They punished you by confiscating your gym membership card and now you can’t go to the gym to get those sweet abs and biceps... (respect your parents next time ok?)" << endl;
						cout << "<-1 health, -2 money, -1 happiness>" << endl;
						updateStats( s, -1, -2, -1 );

						fout << endl << "Choice: acted like a rebellious teenager and slammed your bedroom door in their faces." << endl;		
						fout << "They punished you by confiscating your gym membership card and now you can’t go to the gym to get those sweet abs and biceps... (respect your parents next time ok?)" << endl;											
					}
					else if ( * choice == 2) {
						cout << "They commended you for listening to them for once and now you’re a happy kid." << endl;
						cout << "<-1 health, -2 money, +1 happiness>" << endl;
						updateStats( s, -1, -2, 1 );

						fout << endl << "Choice: apologize to them and promise it’ll never happen again. (while secretly planning the next time you’d go clubbing cos you had wayyy too much fun xD)" << endl;
						fout << "They commended you for listening to them for once and now you’re a happy kid." << endl;
					}
				}
				else if ( * choice == 2 ) {
					cout << "Most of your friends were broke and couldn’t join your birthday party. You" << endl;
					cout << "1: changed your plans and had your party at a fast food restaurant instead." << endl;
					cout << "2: didn’t change your plans because you thought to yourself, 'if they can’t even manage their finances well, they don't deserve to be my friends'" << endl;
					cout << "Enter choice: ";
					cin >> * choice;

					fout << endl << "Choice: a fancy fine-dining restaurant." << endl;
					fout << "Most of your friends were broke and couldn’t join your birthday party. You ";				

					if ( * choice == 1 ) {
						cout << "You had an awesome time with all your friends and saved money too! (though at the expense of your health because you ate wayy too much fried chicken)" << endl;
						cout << "<-1 health, -1 money, +1 happiness>" << endl;
						updateStats( s, -1, -1, 1 );

						fout << endl << "Choice: changed your plans and had your party at a fast food restaurant instead." << endl;
						fout << "You had an awesome time with all your friends and saved money too! (though at the expense of your health because you ate wayy too much fried chicken)" << endl;
					}
					else if ( * choice == 2 ) {
						cout << "You end up broke and without friends and now you’re depressed... (so don't ever think of your friends in that way, be nice ;D )" << endl;
						cout << "<-2 money, -2 happiness>" << endl;
						updateStats( s, 0, -2, -2 );

						fout << endl << "Choice: didn’t change your plans because you thought to yourself, 'if they can’t even manage their finances well, they don't deserve to be my friends'" << endl;
						cout << "You end up broke and without friends and now you’re depressed... (so don't ever think of your friends in that way, be nice ;D )" << endl;							
					}
				}
				else if ( * choice == 3 ) {
					cout << "All the preparations were going well but 15 minutes before the party, you suddenly realized that you forgot to invite your friends. You" << endl;
					cout << "1: had a panic attack and went crying to your mom for help." << endl;
					cout << "2: stayed calm." << endl;
					cout << "Enter choice: ";
					cin >> * choice;

					fout << endl << "Choice: your house." << endl;
					fout << "All the preparations were going well but 15 minutes before the party, you suddenly realized that you forgot to invite your friends. You ";

					if ( * choice == 1 ) {
						cout << "She scolded you for acting like a kid, but in the end helped you invite all your friends by contacting their moms. To teach you a lesson, she had you bear all the costs of throwing the birthday party and now you’re broke..." << endl;
						cout << "<-2 money, +1 happiness>" << endl;
						updateStats( s, 0, -2, 1 );

						fout << endl << "Choice: had a panic attack and went crying to your mom for help." << endl;
						fout << "She scolded you for acting like a kid, but in the end helped you invite all your friends by contacting their moms. To teach you a lesson, she had you bear all the costs of throwing the birthday party and now you’re broke..." << endl;							
					}
					else if ( * choice == 2 ) {
						cout << "GREAT CHOICE! You ended up posting an invitation on your Instagram story, and all your friends showed up! Everyone had a blast and you had a great workout later that day cleaning up the mess." << endl;
						cout << "<+1 health, -1 money, +1 happiness>" << endl;
						updateStats( s, 1, -1, 1 );

						fout << endl << "Choice: stayed calm." << endl;			
						fout << "GREAT CHOICE! You ended up posting an invitation on your Instagram story, and all your friends showed up! Everyone had a blast and you had a great workout later that day cleaning up the mess." << endl;											
					}
				}
			}
		}

		// 2nd Event
		if ( i == 1 ) {
			cout << "You can finally start taking driving lessons! However, you got a trashy driving instructor who had anger management issues and disgusting habits. One day, you accidentally forgot to start the car without pressing the clutch and it died. He was having a really bad day and started spitting out all kinds of profanity. You" << endl;
			cout << "1: remained calm and apologized nicely to him." << endl;
			cout << "2: laughed at him and got out of the car." << endl;
			cout << "3: began competing with him about who could spit the most profanity in a sentence." << endl;
			cout << "Enter choice: ";
			cin >> * choice;

			fout << endl << "[ Event 2 ]" << endl << "You can finally start taking driving lessons! However, you got a trashy driving instructor who had anger management issues and disgusting habits. One day, you accidentally forgot to start the car without pressing the clutch and it died. He was having a really bad day and started spitting out all kinds of profanity. You ";			

			if ( * choice == 1 ) {
				cout << "Were you testing out Selena Gomez's 'Kill 'Em With Kindness' tactic? Well, it worked out! He went crazy and resigned on the spot. You got assigned the best instructor ever later that day." << endl;
				cout << "<+1 happiness>" << endl;
				updateStats( s, 0, 0, 1 );

				fout << endl << "Choice: remained calm and apologized nicely to him." << endl;
				fout << "Were you testing out Selena Gomez's 'Kill 'Em With Kindness' tactic? Well, it worked out! He went crazy and resigned on the spot. You got assigned the best instructor ever later that day." << endl;					
			}
			else if ( * choice == 2 ) {
				cout << "Oh no, huge mistake because he got out of the car and came running at you with his fists clenched. You" << endl;
				cout << "1: get him running around the car like a merry go round game." << endl;
				cout << "2: take him on!" << endl;
				cout << "3: try to get in the car and drive away." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << endl << "Choice: laughed at him and got out of the car." << endl;
				fout << "Oh no, huge mistake because he got out of the car and came running at you with his fists clenched. You ";

				if ( * choice == 1 ) {
					cout << "Fortunately, he got dizzy real quick and fell to the ground exhausted from all the running. You got away this time, with improved stamina too!" << endl;
					cout << "<+1 health>" << endl;
					updateStats( s, 1, 0, 0 );

					fout << endl << "Choice: get him running around the car like a merry go round game." << endl;
					fout << "Fortunately, he got dizzy real quick and fell to the ground exhausted from all the running. You got away this time, with improved stamina too!" << endl;						
				}
				else if ( * choice == 2 ) {
					fout << endl << "Choice: take him on!" << endl;

					if ( s.health == 2 ) {
						cout << "You utilized your Muay Thai training and slapped him silly! However, you had to pay for his hospitalization expenses... You had a blast though! " << endl;
						cout << "<-1 money, +1 happiness>" << endl;
						updateStats( s, 0, -1, 1 );

						fout << "You utilized your Muay Thai training and slapped him silly! However, you had to pay for his hospitalization expenses... You had a blast though! " << endl;
					}
					else if ( s. money > 0 ) {
						cout << "You guys were about to trade blows when you suddenly backed out and offered him some cash (well, to him it was like weed) to calm him down. It worked!" << endl;
						cout << "<-1 money>" << endl;
						updateStats( s, 0, -1, 0 );

						fout << "You guys were about to trade blows when you suddenly backed out and offered him some cash (well, to him it was like weed) to calm him down. It worked!" << endl;
					}
					else if ( s.happiness > 0 ) {
						cout << "You, like the happy kid you were, started singing his favourite song \"Baby Shark\" and got him to dance to the rhythm. SMART MOVE!" << endl;
						cout << "<no effect>" << endl;

						fout << "You, like the happy kid you were, started singing his favourite song \"Baby Shark\" and got him to dance to the rhythm. SMART MOVE!" << endl;
					}
					else if ( s.health < 2 ) {
						cout << "You were in pretty ok physical condition but too bad for you, he was a former MMA champion. You got messed up real bad and got hospitalized... But hey, he got fired and you got assigned a pretty decent instructor! " << endl;
						cout << "<-2 health, +1 happiness>" << endl;
						updateStats( s, -2, 0, 1 );

						fout << "You were in pretty ok physical condition but too bad for you, he was a former MMA champion. You got messed up real bad and got hospitalized... But hey, he got fired and you got assigned a pretty decent instructor! " << endl;
					}
				}
				else if ( * choice == 3 ) {
					fout << endl << "Choice: try to get in the car and drive away." << endl;

					if ( s.health == 2 ) {
						cout << "You were in really good shape and your fast reflexes allowed you to drive away just in the nick of time. You had a good laugh when you saw him cursing and shouting like a maniac in the rearview mirror." << endl;
						cout << "<+1 happiness>" << endl;
						updateStats( s, 0, 0, 1 );

						fout << "You were in really good shape and your fast reflexes allowed you to drive away just in the nick of time. You had a good laugh when you saw him cursing and shouting like a maniac in the rearview mirror." << endl;							
						}
					else if ( s.health < 2 ) {
						cout << "Too bad for you your slow ass wasn't quick enough and you got pulled out of the car and got beaten up. You were hospitalised because he was a former MMA fighter but he got fired and you were assigned the best instructor in the driving academy. congrats (?)" << endl;
						cout << "<-1 health, +1 happiness>" << endl;
						updateStats( s, -1, 0, 1 );

						fout << "Too bad for you your slow ass wasn't quick enough and you got pulled out of the car and got beaten up. You were hospitalised because he was a former MMA fighter but he got fired and you were assigned the best instructor in the driving academy. congrats (?)" << endl;
					}
				}
			}
			else if ( * choice == 3 ) {
				fout << endl << "Choice: began competing with him about who could spit the most profanity in a sentence." << endl;

				if ( s.happiness == 2 ) {
					cout << "You were a happy kid and your happy ‘aura’ turned the hostile atmosphere around. You guys ended up creating a rap ‘masterpiece’ that was 99% profanity and 1% talent" << endl;
					cout << "<no effect>" << endl;

					fout << "You were a happy kid and your happy ‘aura’ turned the hostile atmosphere around. You guys ended up creating a rap ‘masterpiece’ that was 99% profanity and 1% talent" << endl;						
				}
				else if ( s.money == 2 ) {
					cout << "You end up offering to take him to his favourite fast food place to shut him up with fried chicken. It worked out but now you’re broke because his fat ass ate like 37 pieces of fried chicken..." << endl;
					cout << "<-2 money>" << endl;
					updateStats( s, 0, -2, 0 );

					fout << "You end up offering to take him to his favourite fast food place to shut him up with fried chicken. It worked out but now you’re broke because his fat ass ate like 37 pieces of fried chicken..." << endl;
				}
				else if ( s.happiness == 0 ) {
					cout << "You were in a bad mental state and went nuts shouting and cursing at him that he got scared shitless. It ended up being just what you needed to improve your mental health, so congrats!" << endl;
					cout << "<+1 happiness>" << endl;
					updateStats( s, 0, 0, 1 );

					fout << "You were in a bad mental state and went nuts shouting and cursing at him that he got scared shitless. It ended up being just what you needed to improve your mental health, so congrats!" << endl;
				}
				else if ( s.health == 2 ) {
					cout << "You got fed up halfway through and suggested taking it outside, to which he happily agreed. You then messed him up real bad with the ‘Wing Chun’ moves you’ve been picking up from watching ‘Ip Man’. You had a blast toying with him but you got found out by your parents and they grounded you from watching kung fu movies for a year." << endl;
					cout << "<no effect>" << endl;

					fout << "You got fed up halfway through and suggested taking it outside, to which he happily agreed. You then messed him up real bad with the ‘Wing Chun’ moves you’ve been picking up from watching ‘Ip Man’. You had a blast toying with him but you got found out by your parents and they grounded you from watching kung fu movies for a year." << endl;			
				}
				else {
					cout << "You guys got tired and stopped after an hour of screaming like maniacs in the car. You gained his respect for being on his level at using profanity in sentences, and he became a nicer instructor. Congrats!!" << endl;
					cout << "<+1 happiness>" << endl;
					updateStats( s, 0, 0, 1 );

					fout << "You guys got tired and stopped after an hour of screaming like maniacs in the car. You gained his respect for being on his level at using profanity in sentences, and he became a nicer instructor. Congrats!!" << endl;
				}
			}
		}

		// 3rd Event
		if ( i == 2 ) {
			cout << "You finally get to open a bank account! When you went to the bank that day, you witnessed a bank robbery." << endl;

			fout << endl << "[ Event 3 ]" << endl << "You finally get to open a bank account! When you went to the bank that day, you witnessed a bank robbery." << endl;
				
			if ( s.health == 2 ) {
				cout << "You decide to be a hero because you watched wayyy too much One Punch Man and thought just because you were a baldy like Saitama you could take them on. You" << endl;
				cout << "1: try drawing their attention to yourself by shouting at them and wielding your ‘epic’ kung fu moves (like Mr. Bean in Johnny English’s ferry pier scene. Sidenote: if you haven’t watched that movie, you should definitely watch it after this :D)" << endl;
				cout << "2: walk casually into the bank and stare at the robbers with Saitama’s signature dumb look." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You decide to be a hero because you watched wayyy too much One Punch Man and thought just because you were a baldy like Saitama you could take them on. You ";

				if ( * choice == 1 ) {
					cout << "You succeeded at drawing their attention but they just ignored you because you looked too dumb and unintimidating. Guess you should brush up on them moves bro!" << endl;
					cout << "<no effect>" << endl;

					fout << endl << "Choice: try drawing their attention to yourself by shouting at them and wielding your ‘epic’ kung fu moves (like Mr. Bean in Johnny English’s ferry pier scene. Sidenote: if you haven’t watched that movie, you should definitely watch it after this :D)" << endl;
					fout << "You succeeded at drawing their attention but they just ignored you because you looked too dumb and unintimidating. Guess you should brush up on them moves bro!" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "The robbers looked at you and 'at that moment, they realized, they ****** up'... (Now you may be wondering what happened. Well, in simple terms, they too were obsessed with One Punch Man. You can figure out the rest ;D )" << endl;
					cout << "<+1 happiness>" << endl;
					updateStats( s, 0, 0, 1 );

					fout << endl << "Choice: walk casually into the bank and stare at the robbers with Saitama’s signature dumb look" << endl;
					fout << "The robbers looked at you and 'at that moment, they realized, they ****** up'... (Now you may be wondering what happened. Well, in simple terms, they too were obsessed with One Punch Man. You can figure out the rest ;D )" << endl;
				}
			}
			else if ( s.money == 2 ) {
				cout << "You were wearing your Gucci Gang outfit and it caught the eye of the robbers, you" << endl;
				cout << "1: take off your clothes and run for your life." << endl;
				cout << "2: decide to take them on because well, YOLO!" << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You were wearing your Gucci Gang outfit and it caught the eye of the robbers, you ";

				if ( * choice == 1 ) {
					cout << "WISE CHOICE! You got featured on the newspaper the next day about being the ‘Naked Hero’ who managed to distract the robbers with the sight of your bare butt! And, you managed to get in a good cardio session too!" << endl;
					cout << "<+1 health, +1 happiness>" << endl;
					updateStats( s, 1, 0, 1 );

					fout << endl << "Choice: take off your clothes and run for your life." << endl;
					fout << "WISE CHOICE! You got featured on the newspaper the next day about being the ‘Naked Hero’ who managed to distract the robbers with the sight of your bare butt! And, you managed to get in a good cardio session too!" << endl;
				}
				else if ( * choice == 2 ) {
					cout << "They ended up beating you to a pulp and you had to get hospitalized... (they took all your money too)" << endl;
					cout << "<-1 health, -2 money>" << endl;
					updateStats( s, -1, -2, 0 );

					fout << endl << "Choice: decide to take them on because well, YOLO!" << endl;			
					fout << "They ended up beating you to a pulp and you had to get hospitalized... (they took all your money too)" << endl;
				} 
			}
			else if ( s.money == 0 ) {
				cout << "You looked into your wallet and realized you were a broke kid. You" << endl;
				cout << "1: join in the heist!" << endl;
				cout << "2: call the police." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You looked into your wallet and realized you were a broke kid. You ";

				if ( * choice == 1 ) {
					cout << "Two phrases: 'epic fail' + 'instant karma'. The police came and you got caught along with the robbers... Now you’re broke AND depressed!" << endl;
					cout << "<-2 happiness>" << endl;
					updateStats( s, 0, 0, -2 );

					fout << endl << "Choice: join in the heist!" << endl;
					fout << "Two phrases: 'epic fail' + 'instant karma'. The police came and you got caught along with the robbers... Now you’re broke AND depressed!" << endl;						
				}
				else if ( * choice == 2 ) {
					cout << "(sorry it had to be this cliche but...) WISE CHOICE! The police came and caught the robbers, and you got a stupendous amount of cash from the bank manager for your heroic actions!" << endl;
					cout << "<+2 money, +1 happiness>" << endl;
					updateStats( s, 0, 2, 1 );

					fout << endl << "Choice: call the police." << endl;
					fout << "(sorry it had to be this cliche but...) WISE CHOICE! The police came and caught the robbers, and you got a stupendous amount of cash from the bank manager for your heroic actions!" << endl;						
				}
			}
			else if ( s.happiness == 0 || s.health == 0 ) {
				cout << "You were having some mental issues (please take care of your character...) and so you" << endl;
				cout << "1: stood there with a depressed look watching the robbery take place." << endl;
				cout << "2: started laughing like a maniac." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "You were having some mental issues (please take care of your character...) and so you ";

				if ( * choice == 1 ) {
					cout << "Shortly after the robbers left, a kind soul who noticed your odd behaviour offered to take you to see a psychologist. (ahh, what a nice world you’re living in...) You ended up getting cured!" << endl;
					cout << "<+1 health, +1 happiness>" << endl;
					updateStats( s, 1, 0, 1 );

					fout << endl << "Choice: stood there with a depressed look watching the robbery take place." << endl;
					fout << "Shortly after the robbers left, a kind soul who noticed your odd behaviour offered to take you to see a psychologist. (ahh, what a nice world you’re living in...) You ended up getting cured!" << endl;						
				}
				else if ( * choice == 2 ) {
					cout << "The robbers watched too many DC movies and thought you were the Joker (because like i said, you had some mental issues and spread lipstick and makeup all over your face that day), so they ran off." << endl;
					cout << "<no effect>" << endl;

					fout << endl << "Choice: started laughing like a maniac." << endl;			
					fout << "The robbers watched too many DC movies and thought you were the Joker (because like i said, you had some mental issues and spread lipstick and makeup all over your face that day), so they ran off." << endl;								
				}
			}
			else {
				cout << "Your mom who was with you shrieked and fainted on the spot. You" << endl;
				cout << "1: did the same, but in more EPIC fashion." << endl;
				cout << "2: carried her in your arms and ran to the nearest hospital." << endl;
				cout << "3: stood there in shock." << endl;
				cout << "Enter choice: ";
				cin >> * choice;

				fout << "Your mom who was with you shrieked and fainted on the spot. You ";

				if ( * choice == 1 ) {
					cout << "You woke up feeling like you were in Antartica because some genius passerby poured their Starbuck's ice latte on you to wake you up. You look to your side and there lay your mom, snoring away like she was in the most comfortable 5 star hotel bed. You sighed and thought to yourself: 'Is this even happening right now?'" << endl;
					cout << "<no effect>" << endl;

					fout << endl << "Choice: did the same, but in more EPIC fashion." << endl;
					fout << "You woke up feeling like you were in Antartica because some genius passerby poured their Starbuck's ice latte on you to wake you up. You look to your side and there lay your mom, snoring away like she was in the most comfortable 5 star hotel bed. You sighed and thought to yourself: 'Is this even happening right now?'" << endl;						
				}
				else if ( * choice == 2 ) {
					cout << "HAH! So you thought you were strong? Nah fam, you had lanky arms like Woody from Toy Story and couldn't get her to budge. You eventually gave up and called the ambulance. (but not the police so the robbers managed to get away :D)" << endl;
					cout << "<no effect>" << endl;

					fout << endl << "Choice: carried her in your arms and ran to the nearest hospital." << endl;	
					fout << "HAH! So you thought you were strong? Nah fam, you had lanky arms like Woody from Toy Story and couldn't get her to budge. You eventually gave up and called the ambulance. (but not the police so the robbers managed to get away :D)" << endl;				
				}
				else if ( * choice == 3 ) {
					cout << "You watched the entire robbery unfold and because of that, got called to testify in the police station as a witness. You didn't manage to contribute anything useful though because your brain encountered \"BSoD\" the entire duration of the incident." << endl;
					cout << "<no effect>" << endl;

					fout << endl << "Choice: stood there in shock." << endl;				
					fout << "You watched the entire robbery unfold and because of that, got called to testify in the police station as a witness. You didn't manage to contribute anything useful though because your brain encountered \"BSoD\" the entire duration of the incident." << endl;							
				}
			}
		}

		printStats( s, name ); // prints current player stats
	}

	delete choice; // frees up space allocated to dynamic variable choice

	return;
}