# ENGG1340_Project

Group members: 
1. Brandon Tay Jian Wei (3035767102) 
2. Yoo Yuen Yau (3035832440)

## **BitTeenLife**
### (PLEASE READ THROUGH THE WHOLE FILE)

#### Game description: 
Text-based life simulator from ages 13-23, based on the game 'BitLife - Life Simulator'. 

#### Compilation and Execution:
Use the terminal in the directory where the game files (ie. the gameFiles folder) are located and type 'make play' in the command line.

#### Game rules: 
1. Character stats will consist of 3 variables:
   - health
   - money
   - happiness
2. Each variable will have a range of 0-2 (inclusive).
3. At the start of the game, the user will choose whether to load a new game (by inputting '1') or load a saved game (by inputting '2'). 
   - If the user chooses to load a new game, they would have to input the name of either an empty .txt file or a .txt file that does not exist in the current directory (eg: save.txt). This will be the file to be loaded from if the user chooses to load a saved game in another run.
   - If the user chooses to load a saved game, they would have to input the name of a .txt file where the game progress was previously saved.
4. New game starts off with character at age 13 being assigned upgradable stats. 
5. At the end of every year, the user inputs '1' to grow up and advance to the next age after each age is finished. The user can also input '2' to quit and save the game.
6. Random events will be generated each year:
   - events of 4 'major' years will be dependent on character stats, and consists only of choice-based events.
   - events of 7 'minor' years will be randomly selected from a collection of presets, and consist of statement- and choice-based events (1 each per year).
7. A list of responses to choice-based events will be displayed for the user to choose from.
8. User inputs a number corresponding to the response of their choice to pick it. 
9. Each choice may affect 1 or more variables of the character's stats.

#### Features included according to the requirements of the project:
1. Random events generated at every age. We will use the rand() function to select a random event from an array of possible events. *<coding requirement 1>*
2. Data structures (eg: arrays) to store random events. We will also use structs to store the member variables: health, money, and happiness. *<coding requirement 2>*
3. Dynamic memory management when dealing with variables, where appropriate *<coding requirement 3>*
4. File I/O for saving and loading game status (the user can add a file to which the game progress is written and saved, and from which previous game progress can be read and loaded) or outputting a summary at the end of the game (summary is stored in a user-set .txt file). *<coding requirement 4>*
5. Different functions in different files (file for manipulating player stats, files for choosing random events, files for determining the event for certain years based on the character stats, file for main program) *<coding requirement 5>*

### Problem Statement:
#### Assumptions with inputs:
1. All inputs are valid.
2. The name inputted by the user must be of a single word.
3. .txt file that user inputs when prompted during loading a saved game exists and is valid.
#### Settings to be played on:
1. Set the terminal window to full screen to prevent too many cut off words.
#### Other things to take note of:
1. The sample input and output files are for reference only. Due to the random nature of our game, it is highly unlikely that the same inputs will generate the same outputs.
2. Our code has lines which are very long due to us dealing with raw string literals. According to https://google.github.io/styleguide/cppguide.html#Line_Length, this is acceptable.
3. During compilation and execution, there will be a file called tempfile.txt that will be created. Please ignore this file (don't do anything about it) as it is just an empty file to store any unfinished game states (if any).
