#mastermind

two folders: terminal version of playable mastermind, and mastermind solver

Both were written for a discrete structures class in fall 2024

##mastermind_game

A terminal based mastermind game written by Jacob Kwiat. Includes settings for number of marbles and repeat colors. 

###instructions
Mastermind involves a "code" which is a series of colored marbles.The objective of the player is to guess both the colors and order of the code. 

upon running the program the user will be prompted for the number of marbles, and then prompted to choose whether the code will contain repeat colors.

After submitting the settings, the code will be generated and the user will be prompted to enter their guesses one by one

after entering a guess for each marble, the user will be shown the results for their guesses. They can be read as follows: 0 = wrong color, 1 = right color but wrong spot, 2 = right color, right spot

The user may then begin entering their next guess

##mastermind_solver

A mastermind solver written by Jacob Kwiat that runs for a version of mastermind Written by  Dr.Mark Lehr

outputs the number of guesses the program took to solve the code as well as the code
