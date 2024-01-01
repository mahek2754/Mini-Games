# Battleship Console Game

## Overview

This is a simple console-based implementation of the classic game Battleship using C++. The game supports two players taking turns to place ships on a grid and then guess the locations of each other's ships.

## Instructions

1. **Planning Phase:**
   - Player 1 places five ships: Aircraft carrier (5 spaces), Battleship (4 spaces), Destroyer (3 spaces), Corvette (2 spaces), and Frigate (1 space).
   - Player 2 does the same.

2. **Guessing Phase:**
   - Players take turns guessing the coordinates of the opponent's ships.
   - The grid displays hits ('H'), misses ('*'), and unguessed cells ('.'). 

3. **Winning:**
   - The game ends when one player successfully sinks all five of the opponent's ships.

## How to Run

Compile the code and run the executable. Follow the on-screen instructions to play the game.

## Game Symbols
- `.`: Unguessed cell
- `H`: Hit
- `*`: Miss

## Gameplay Notes

- Ships cannot overlap or hang off the grid.
- Diagonal ship placement is not allowed.
- Players are prompted to enter coordinates in the format (e.g., A1).

Enjoy playing Battleship in the console!

# Connect Four Console Game

## Overview

This is a console-based implementation of the game Connect Four using Python. Connect Four is a two-player connection game in which the players first choose a color and then take turns dropping one colored disc from the top into a vertically suspended grid. The pieces fall straight down, occupying the lowest available space within the column. The game objective is to connect four of one's own discs in a row vertically, horizontally, or diagonally before the opponent.

## Instructions

1. **Game Board:**
   - The game board is a grid with 6 rows and 7 columns, represented as a NumPy array.
   - Players take turns choosing a column to drop their colored disc.

2. **Winning:**
   - The game ends when a player successfully connects four of their colored discs in a row vertically, horizontally, or diagonally.

3. **Tie Game:**
   - If the entire board is filled and no player has connected four discs, the game is a tie.

## How to Play

- Run the script, and players will take turns entering the column where they want to drop their disc.
- Enter a number from 0 to 6 to choose the column.

## Game Symbols

- `1`: Disc of Player 1
- `2`: Disc of Player 2
- `0`: Empty cell

Enjoy playing Connect Four in the console!
