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
3. New game starts off with character at age 13 being assigned upgradable stats. 
4. User inputs '1' to grow up and advance to the next age after each age is finished.
5. Random events will be generated each year:
   - events of 4 'major' years will be dependent on character stats, and consists only of choice-based events.
   - events of 7 'minor' years will be randomly selected from a collection of presets, and consist of statement- and choice-based events (1 each per year).
6. A list of responses to choice-based events will be displayed for the user to choose from.
7. User inputs a number corresponding to the response of their choice to pick it. 
8. Each choice may affect 1 or more variables of the character's stats.

#### Features included according to the requirements of the project:
1. Random events generated at every age. We will use the rand() function to select a random event from an array of possible events. *<coding requirement 1>*
2. Data structures (eg: arrays) to store random events. We will also use structs to store the member variables: health, money, and happiness. *<coding requirement 2>*
3. Dynamic memory management when dealing with variables, where appropriate *<coding requirement 3>*
4. File I/O for saving and loading game status (the user can add a file to which the game progress is written and saved, and from which previous game progress can be read and loaded) or outputting a summary at the end of the game (summary is stored in a user-set .txt file). *<coding requirement 4>*
5. Different functions in different files (file for manipulating player stats, files for choosing random events, files for determining the event for certain years based on the character stats, file for main program) *<coding requirement 5>*
