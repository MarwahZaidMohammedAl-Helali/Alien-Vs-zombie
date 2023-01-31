# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo]([https://youtube.com](https://www.youtube.com/watch?v=YhtRhMHp1H4)).

## Minimum Requirements

### Completed

List all the features completed.

1. Game Initialization: The game starts with a default setting, but the player has the option to change the game settings such as the number of rows and columns in the game board, as well as the number of zombies.
2. Alien  Control: The player can control the alien and make it move up, down, left, and right on the game board. The player can also check the alien's health and look for health pods and rocks.
3. Zombie Management: The game generates a specified number of zombies and gives each zombie a life, attack, and range value. The player can view the details of all the zombies in the game such as their life, attack, and range.
4. Help and Quit: The player can access a help menu to get information about the game's commands and features, and can also quit the game at any time. Game Board: The game board is generated using a helper class and is updated with the player's movements and actions. The game board is displayed after each move.
5. Object Positions: We have created a vector "POS" to store the positions of every object on the board, such as the Alien, health packs, pods, and zombies, to ensure no overlaps occur when the "object_pos" function randomly generates their positions.

### To Do

List all the features not yet done. Remove this section if there are no incomplete requirements.

1. Giving the player the ability to change the direction of the arrows before moving the alien.
2. Resolve the stack overflow error that occurs when the Alien encounters an arrow.
3. make the Pods function properly when encountered by the Alien.
4. give the zombies the ability to move around the board as well as inflict damage on the alien whenever the alien is within their range.
5. fix usability issues like Input Validation to insure a smooth operation.
6. switch the controls of the game to w, a, s, d to provide a more familiar and natural experience.
7. Add additional features and objects to the game to make it more interesting and unique.

## Additional Features

Describe the additional features that has been implemented.

## Contributions

List down the contribution of each group members.

### Marwah

1. Creating the control functions for the alien
2. Helping with confifuring the game default settings.
3. Generating and managing the zombies on the game board as well as their stats like their life and attack.

### Thabit

1. Generating the game board according to the specified number of rows and columns.
2. fixing any problems with the random placment of the objects on the board.
3. making sure that the correct cordenats of the Alien is always displayed even when it moves.

### Khalid

1. Configuring the game's default settings.
2. Making sure that the zombies are printed correctly and each according to its number.
3. Creating the help menu and quit function.

## Problems Encountered & Solutions

1. Responsible for configuring the game's default settings and zombie output, as well as creating the help menu and quit function.
2. We had difficulty implementing the ability to move the alien around the game board, as it was difficult to determine the exact coordinates for each move. We fixed this problem by writing a function to determine the coordinates for each movement, and by keeping track of the alien’s current position.
3. We encountered a problem when trying to prevent the overlapping of objects on the board, as it was difficult to determine the exact positions of objects since all the objects are randomly placed. We fixed this problem by creating a vector “POS” that stores the positions of each object on the board, and by using an “object_pos” function it checks whether the randomly generate position is empty or not.
