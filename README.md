# Number Guessing Game (Single Player & Multiplayer) 🎮

Welcome to the **Number Guessing Game**, one of the most feature-packed and engaging number guessing games on GitHub! This game is designed for both **single-player** and **multiplayer** modes, featuring difficulty levels, win streak tracking, and even a carry-forward attempt system for multiplayer mode. Whether you're challenging yourself or competing against a friend, this game offers a thrilling experience!

## ⭐ Features

### 🎮 Game Modes
- **Single Player Mode**: Play against the computer and try to guess the randomly generated number.
- **Multiplayer Mode**: Compete against a friend, taking turns to guess the correct number.

### 🏆 Difficulty Levels
- **Easy**: Range **1-100**, **10 attempts** (Single Player) / **8 attempts** (Multiplayer)
- **Medium**: Range **1-150**, **8 attempts** (Single Player) / **6 attempts** (Multiplayer) *(Hints included)*
- **Hard**: Range **1-200**, **6 attempts** (Single Player) / **4 attempts** (Multiplayer) *(Hints included)*

### 🔥 Enhanced Features
- **Win Streak System**: Tracks and displays winning streaks for both single and multiplayer modes.
- **Leftover Attempts Carry-Forward (for both modes)**: Players can carry their remaining attempts to the next round if the same players continue.
- **Comprehensive Input Validation**: Ensures that users enter valid choices to prevent crashes and errors.
- **Random Number Generation**: Generates a unique number within the selected difficulty range.
- **Dynamic Hints**: Available in Medium and Hard modes, providing **odd/even hints**.
- **Statistics Tracking**: Displays total wins and streaks after each round.

## 📚 Libraries Used
This game is built using **C++** and utilizes the following libraries:

```cpp
#include<iostream>   // For input and output operations  
#include<cstdlib>    // For random number generation  
#include<ctime>      // For seeding the random number generator  
#include<string>     // For handling player names and inputs  
```

## 📜 How to Play

### 🎲 Single Player Mode
1. Choose **Single Player** mode.
2. Select a **difficulty level**.
3. Try to **guess the number** within the allowed attempts.
4. Receive **hints** in Medium and Hard modes.
5. If you **win**, your remaining attempts **carry over** to the next game!

### 👥 Multiplayer Mode
1. Choose **Multiplayer** mode.
2. Enter the **names** of two players.
3. Select a **difficulty level**.
4. Players **take turns** guessing the secret number.
5. The **first player to guess correctly wins**, and their remaining attempts **carry over** if the same players continue.
6. **Win streaks and total wins** are tracked.

## ⚡ Installation & Usage

### Clone this repository:
```sh
git clone https://github.com/codifyhuzaifa/Ultimate-Number-Guessing-Game.git
```

### Navigate to the directory:
```sh
cd Ultimate-Number-Guessing-Game
```

### Compile and run the game (for C++ compilers like g++):
```sh
g++ number_guessing_game.cpp -o game
./game
```

## 📌 Repository Information
- **Programmer**: Huzaifa Farooq (GitHub: [codifyhuzaifa](https://github.com/codifyhuzaifa))
- **Language**: C++

## 🚀 Why This is One of the Best Number Guessing Games on GitHub

This project showcases my strong grasp of C++ fundamentals, including loops, conditionals, and game logic.

✅ **Multiplayer Mode with Dynamic Player Switching**  
✅ **Win Streak and Statistics Tracking**  
✅ **Leftover Attempt System for Multiplayer**  
✅ **Robust Input Validation**  
✅ **Engaging Difficulty Levels with Hints**  
✅ **Clean and Well-Structured Code**  
✅ **Bug-Free and Smooth Execution**  

If you're looking for a **fun, interactive, and well-coded number guessing game**, this is the one for you!

## 🏆 Contribution & Support
Feel free to **fork** the repository, contribute new features, or report issues. If you like this game, don't forget to **⭐ star this repository**!

Enjoy the **Ultimate Number Guessing Game** and challenge your friends! 🎉
