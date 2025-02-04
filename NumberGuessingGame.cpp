/*
    Number Guessing Game with Multiplayer Functionality
    Developed by: Huzaifa Farooq (GitHub: codifyhuzaifa)
    
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int main() {
    // Variable declarations and intizalizations for first game
    char choice;
    int left = 0;
    int player1attemptsleft = 0;
    int player2attemptsleft = 0;
    int size = 2;
    int same = 2;
    string players[size];
    int singlestreak = 0;
    int player1WinStreak = 0;
    int player2WinStreak = 0;
    int player1WinCount = 0;
    int player2WinCount = 0;
    int player1attempts, player2attempts;
    string *playerturn = &players[0];
    int *currentattempts = &player1attempts;
    int *attemptsleft = &player1attemptsleft;
    bool won = false;
    
    // Game instructions
    cout << "---------- Welcome to my number guessing game! ----------" << endl;
    cout << endl;
    cout << "How to Play: " << endl;
    cout << "1. Choose between Single Player or Multiplayer mode." << endl;
    cout << "2. Select a difficulty level (Easy, Medium, Hard) to set the number range and attempts." << endl;
    cout << "3. Guess the secret number within the given attempts." << endl;
    cout << "4. Hints will be given for Medium and Hard difficulty levels." << endl;
    cout << "5. Win streaks are tracked in both Single Player and Multiplayer modes." << endl;
    cout << "6. After each game, you will be asked if you want to play again." << endl;
    cout << "7. In Multiplayer mode, players take turns guessing. The first to guess the number wins and can carry leftover attempts to the next game only if the same two players continue." << endl;
    cout << "8. Switching between Single Player and Multiplayer modes will reset win counts, streaks, and leftover attempts." << endl;
    cout << endl;
    cout << "Enjoy the game and good luck!" << endl;
    cout << endl;

    do {
        int multiplayer;
        int difficulty;
        bool execution = false;
        
        // Select Game mode
        if (same == 2) {
            cout << "Game Mode: " << endl;
            cout << "1. Single Player " << endl;
            cout << "2. Multiplayer" << endl;
            cout << "Enter your choice by number: ";
            cin >> multiplayer;
            
        // Validation check
            while(multiplayer!= 1 && multiplayer!= 2){
            	cout << "Invalid entry! Please choose a valid game mode (1 or 2): ";
            	cin >> multiplayer;
			}
        }
        
        // Difficulty Levels selection according to game mode.
        if (multiplayer == 1) {
            cout << "Difficulty levels: " << endl;
            cout << "1. Easy: Range 1-100, 10 Attempts" << endl;
            cout << "2. Medium: Range 1-150, 8 Attempts" << endl;
            cout << "3. Hard: Range 1-200, 6 Attempts" << endl;
        } else {
        	 /* Take new players only if the user chose to at the end of the game or if you are playing
        	 a new game */
            if (same == 2) { 
                players[0] = "";
                players[1] = "";
                player1attemptsleft = 0;
                player2attemptsleft = 0;
                player1WinStreak = 0;
                player2WinStreak = 0;
                player1WinCount = 0;
                player2WinCount = 0;
                cin.ignore();
                for (int i = 0; i < size; i++) {
                    cout << "Enter the name of player " << i + 1 << ": ";
                    getline(cin, players[i]);
                }
            }
            cout << "Difficulty levels: " << endl;
            cout << "1. Easy: Range 1-100, 8 Attempts per player" << endl;
            cout << "2. Medium: Range 1-150, 6 Attempts per player" << endl;
            cout << "3. Hard: Range 1-200, 4 Attempts per player" << endl;
        }

        cout << "Choose a difficulty level (1-3): ";
        cin >> difficulty;
        
        // Validation check
        while (difficulty > 3 || difficulty < 1) {
            cout << "Invalid entry! Please choose a difficulty level between 1 and 3: ";
            cin >> difficulty;
        }
        
        int guess;
        int attempts;
        int range;
        
        // Setting difficulty-based values using switch
        if (multiplayer == 2) {
            switch (difficulty) {
                case 1: {
                    range = 100;
                    player1attempts = 8;
                    player2attempts = 8;
                    break;
                }
                case 2: {
                    range = 150;
                    player1attempts = 6;
                    player2attempts = 6;
                    break;
                }
                case 3: {
                    range = 200;
                    player1attempts = 4;
                    player2attempts = 4;
                    break;
                }
            }
            // Displaying total attempts after adding the leftover attempts
            if (playerturn == &players[0] && won == true) {
                player1attempts = player1attempts + *attemptsleft;
                cout << players[0] << "'s total attempts: " << player1attempts << endl;
                cout << players[1] << "'s total attempts: " << player2attempts << endl;
            } else if (playerturn == &players[1] && won == true) {
                player2attempts = player2attempts + *attemptsleft;
                cout << players[0] << "'s total attempts: " << player1attempts << endl;
                cout << players[1] << "'s total attempts: " << player2attempts << endl;
            }
			else {
                cout << "Each player will have " << player1attempts << " attempts. Range: 1 to " << range << endl;
            }
        }
		 
		// For single player
		else {
            switch (difficulty) {
                case 1: {
                    range = 100;
                    attempts = 10;
                    break;
                }
                case 2: {
                    range = 150;
                    attempts = 8;
                    break;
                }
                case 3: {
                    range = 200;
                    attempts = 6;
                    break;
                }
            }
            cout << "Total Attempts: " << attempts << ". Range: 1 to " << range << endl;
        }
        
        // Using bool to track when the game is won
        won = false;
        if (left > 0 && multiplayer == 1) {
            cout << "You'll also have " << left << " leftover attempts from previous games!" << endl;
            attempts = attempts + left; // Adding leftover attempts from the previous game for single player
            cout << "Total Attempts: " << attempts << endl;
        }
        
        // Generating a random number within the selected range
        srand(time(0));
        int num = (rand() % range) + 1;
        
        // Hints for Medium and Hard difficulty levels
        if (difficulty >= 2) {
            if (num % 2 == 0) {
                cout << "Hint: The number is even!" << endl;
            } else {
                cout << "Hint: The number is odd!" << endl;
            }
        }
        
        // Tracking players' turns, attempts, and leftover attempts using pointers
        playerturn = &players[0];
        currentattempts = &player1attempts;
        attemptsleft = &player1attemptsleft;
        
        // Multiplayer Mode
        if (multiplayer == 2) {
            while (!won && (player1attempts > 0 || player2attempts > 0)) {
                int playersguess;
                cout << *playerturn << "'s turn (" << *currentattempts << " attempts left): ";
                cout << "Enter your guess: ";
                cin >> playersguess;
                
                // Validation check for guess
                while (playersguess < 1 || playersguess > range) {
                    cout << "Guess is out of range. Please enter a number between 1 and " << range << ": ";
                    cin >> playersguess;
                }
                
                // If the number is guessed correctly
                if (playersguess == num) {
                    cout << "Congratulations! You guessed the number correctly!" << endl;
                    cout << "Winner: " << *playerturn << endl;
                    (*currentattempts)--;
                    *attemptsleft = *currentattempts;
                    
                    // Updating Win streaks and counts for the players
                    if (playerturn == &players[0]) {
                        player1WinStreak++;
                        player2WinStreak = 0;
                        player1WinCount++;
                        if (player1WinStreak >= 2) {
                            cout << players[0] << " is on a " << player1WinStreak << "-game win streak!" << endl;
                        }
                    } else if (playerturn == &players[1]) {
                        player2WinStreak++;
                        player1WinStreak = 0;
                        player2WinCount++;
                        if (player2WinStreak >= 2) {
                            cout << players[1] << " is on a " << player2WinStreak << "-game win streak!" << endl;
                        }
                    }
                    cout << *playerturn << "'s leftover attempts will carry over to the next game!" << endl;
                    cout << *playerturn << "'s attempts left: " << *currentattempts << endl;
                    
                    // To take the program out of while loop
                    won = true;
                    
                    cout << players[0] << "'s total wins: " << player1WinCount << endl;
                    cout << players[1] << "'s total wins: " << player2WinCount << endl;
                }
				 
				// If the guess was greater
				else if (playersguess > num) {
                    cout << "Your guess is greater than the number!" << endl;
                    (*currentattempts)--;
                } 
                
				// If the guess was less
				else if (playersguess < num) {
                    cout << "Your guess is less than the number!" << endl;
                    (*currentattempts)--;
                }
                
                // Avoiding multiple executions by bool
                if (!execution) {
                    if (player1attempts == 0) {
                        cout << players[0] << " has run out of attempts!" << endl;
                        execution = true;
                    } else if (player2attempts == 0) {
                        cout << players[1] << " has run out of attempts!" << endl;
                        execution = true;
                    }
                }
                if (player1attempts == 0 && player2attempts == 0) {
                    cout << "Both players have run out of attempts!" << endl;
                }
                
                // Swapping player turns after each guess in multiplayer mode
                if (playerturn == &players[0] && !won && player2attempts != 0) {
                    playerturn = &players[1];
                    currentattempts = &player2attempts;
                } else if (playerturn == &players[1] && !won && player1attempts != 0) {
                    playerturn = &players[0];
                    currentattempts = &player1attempts;
                }
            }
        }
        
		 // Single Player Mode
		 else if (multiplayer == 1) {
            while (!won && attempts > 0) {
                cout << "Enter your guess: ";
                cin >> guess;
                
                // Validation check for guess
                while (guess < 1 || guess > range) {
                    cout << "Guess is out of range. Please enter a number between 1 and " << range << ": ";
                    cin >> guess;
                }
                
                // If the number is guessed correctly
                if (guess == num) {
                    cout << "Congratulations! You guessed the number correctly!" << endl;
                    attempts--;
                    left = attempts;
                    singlestreak++;
                    won = true;
                }
				 
				// If the guess was greater.
				else if (guess > num) {
                    cout << "Your guess is greater than the number!" << endl;
                    attempts--;
                    cout << "Attempts left: " << attempts << endl;
                } 
                
				// If the guess was less
				else if (guess < num) {
                    cout << "Your guess is less than the number!" << endl;
                    attempts--;
                    cout << "Attempts left: " << attempts << endl;
                }
                
                // If the player runs out of attempts
                if (attempts == 0) {
                    cout << "You've run out of attempts!" << endl;
                    cout << "The number was: " << num << endl;
                    singlestreak = 0;
                    left = 0;
                }
            }
        }
        
        // Displaying streak and leftover attempts for single player mode
        if (multiplayer == 1) {
            if (singlestreak >= 2) {
                cout << "You're on a " << singlestreak << "-game win streak!" << endl;
            }
            if (attempts > 0) {
                cout << "Your leftover attempts will carry over to the next game!" << endl;
                cout << "Attempts left: " << attempts << endl;
            }
        }
        
        // Asking the user if they want to play again
        cout << "Do you want to play again? (Enter Y for yes and N for no): ";
        cin >> choice;
        while(choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n'){
        	cout << "Invalid Choice! Please choose a valid choice: ";
        	cin >> choice;
		}
        if (attempts > 0) {
            cout << "Note: Leftover attempts cannot be carried forward in multiplayer mode." << endl;
        }
        
        // Displaying Conditions
        if (multiplayer == 2 && (choice == 'Y' || choice == 'y')) {
            if (*currentattempts > 0) {
                cout << "Leftover attempts can only be carried forward if you play with the same players." << endl;
            }
            if (player1WinStreak >= 2 || player2WinStreak >= 2) {
                cout << "Note: Win streaks will reset if you switch players or modes." << endl;
            }
            
            // Asking the user if they want to play again with the same players.
            cout << "Do you want to play with the same two players? (1 for Yes, 2 for No): ";
            cin >> same;
            
            while(same != 1 && same != 2){
            	cout << "Invalid entry! Please choose (1 or 2): ";
            	cin >> same;
			}
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}
