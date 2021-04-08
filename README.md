# ENGG1340_Project

Group members: 
1. Brandon Tay Jian Wei (3035767102) 
2. Yoo Yuen Yau (3035832440)

## **BitTeenLife**

#### Game description: 
Text-based life simulator from ages 13-23, based on the game 'BitLife - Life Simulator'.  

#### Game rules: 
1. Character stats will consist of 3 variables:
   - health
   - money
   - happiness
2. Each variable will have a range of 0-2 (inclusive).
3. Game starts off with character at age 13 being assigned upgradable stats. 
4. User inputs '1' to grow up and advance to the next age after each age is finished.
5. Random events will be generated each year:
   - events of 4 'major' years will be dependent on character stats 
   - events of 7 'minor' years will be randomly selected from a collection of presets
6. A list of responses to the events will be displayed for the user to choose from.
7. User inputs a number corresponding to the response of their choice to pick it. 
8. Each choice will affect 1 or more variables of the character's stats.

#### Features included according to the requirements of the project:
1. Random events generated at every age. We will use the rand() function to select a random event from an array of possible events. *<coding requirement 1>*
2. Data structures (eg: arrays) to store random events and user choices for a summary at the end of the game (TBD). We will also use structs to sture the member variables of health, money and happiness. *<coding requirement 2>*
3. Dynamic memory management when dealing with variables, where appropriate *<coding requirement 3>*
4. File I/O for saving and loading game status (the user can add a file which the game saves its progress to, continuing from the last saved point when this is loaded again) or outputting a summary at the end of the game (where the summary is output to a user-set .txt file). *<coding requirement 4>*
5. Different functions in different files (1 file for manipulating the user stats, 1 file for choosing random events, 1 file for determining the event for certain years based on the character stats, 1 main file) *<coding requirement 5>*
