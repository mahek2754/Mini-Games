#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

const int GRID_SIZE = 10;
vector<vector<char>> playerGrid(GRID_SIZE, vector<char>(GRID_SIZE, '.'));
vector<vector<char>> opponentGrid(GRID_SIZE, vector<char>(GRID_SIZE, '.'));
vector<vector<char>> playerGridGuess(GRID_SIZE, vector<char>(GRID_SIZE, '.'));
vector<vector<char>> opponentGridGuess(GRID_SIZE, vector<char>(GRID_SIZE, '.'));
vector<string> ships = {"Aircraft carrier", "Battleship", "Destroyer", "Corvette", "Frigate"};
vector<pair<char, int>> shipSymbol = {{'A', 1}, {'B', 2}, {'D', 3}, {'C', 4}, {'F', 5}};
vector<int> v(5, 0);
vector<int> p(5, 0);
int player1 = 0;
int player2 = 0;

// Function to display the grid
void displayGrid(vector<vector<char>> &grid)
{
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        cout << setw(2) << i << " ";
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void update_grid_2(string guess)
{
    int a = guess[0] - 'A';
    int b = guess[1] - '0';
    if (opponentGrid[b][a] == '.')
    {
        cout << " MISS " << endl;
        playerGridGuess[b][a] = '*';
    }
    else
    {
        cout << "HIT" << endl;
        if (opponentGrid[b][a] == 'A')
        {
            v[4]++;
            if (v[4] == 5)
            {
                cout << "HIT AND SINK" << endl;
                player2++;
            }
            playerGridGuess[b][a] = 'H';
        }
        else if (opponentGrid[b][a] == 'F')
        {
            v[0]++;
            if (v[0] == 1)
            {
                cout << "HIT AND SINK" << endl;
                player2++;
            }
            playerGridGuess[b][a] = 'H';
        }
        else if (opponentGrid[b][a] == 'B')
        {
            v[3]++;
            if (v[3] == 4)
            {
                cout << "HIT AND SINK" << endl;
                player2++;
            }
            playerGridGuess[b][a] = 'H';
        }
        else if (opponentGrid[b][a] == 'D')
        {
            v[2]++;
            if (v[2] == 3)
            {
                cout << "HIT AND SINK" << endl;
                player2++;
            }
            playerGridGuess[b][a] = 'H';
        }
        else
        {
            v[1]++;
            if (v[1] == 2)
            {
                cout << "HIT AND SINK" << endl;
                player2++;
            }
            playerGridGuess[b][a] = 'H';
        }
    }
}

void update_grid_1(string guess)
{
    int a = guess[0] - 'A';
    int b = guess[1] - '0';
    if (playerGrid[b][a] == '.')
    {
        cout << " MISS " << endl;
        opponentGridGuess[b][a] = '*';
    }
    else
    {
        cout << "HIT" << endl;
        if (playerGrid[b][a] == 'A')
        {
            p[4]++;
            if (p[4] == 5)
            {
                cout << "HIT AND SINK" << endl;
                player1++;
            }
            opponentGridGuess[b][a] = 'H';
        }
        else if (playerGrid[b][a] == 'F')
        {
            p[0]++;
            if (p[0] == 1)
            {
                cout << "HIT AND SINK" << endl;
                player1++;
            }
            opponentGridGuess[b][a] = 'H';
        }
        else if (playerGrid[b][a] == 'B')
        {
            p[3]++;
            if (p[3] == 4)
            {
                cout << "HIT AND SINK" << endl;
                player1++;
            }
            opponentGridGuess[b][a] = 'H';
        }
        else if (playerGrid[b][a] == 'D')
        {
            p[2]++;
            if (p[2] == 3)
            {
                cout << "HIT AND SINK" << endl;
                player1++;
            }
            opponentGridGuess[b][a] = 'H';
        }
        else
        {
            p[1]++;
            if (p[1] == 2)
            {
                cout << "HIT AND SINK" << endl;
                player1++;
            }
            opponentGridGuess[b][a] = 'H';
        }
    }
}

bool valid_guess1(string cord)
{
    char a = cord[0];
    int b = cord[1] - '0';
    if (!(a >= 'A' && a <= 'J'))
    {
        cout << "Entered coordinates are out of bounds choose between A - J" << endl;
        return 0;
    }
    if (b > 9 || b < 0)
    {
        cout << "Entered coordinates are out of bounds choose between 0 - 9" << endl;
        return 0;
    }
    if (playerGridGuess[b][a - 'A'] != '.')
    {
        cout << "Already made a guess on this cell" << endl;
        return 0;
    }
    return 1;
}

bool valid_guess2(string cord)
{
    char a = cord[0];
    int b = cord[1] - '0';
    if (!(a >= 'A' && a <= 'J'))
    {
        cout << "Entered coordinates are out of bounds choose between A - J" << endl;
        return 0;
    }
    if (b > 9 || b < 0)
    {
        cout << "Entered coordinates are out of bounds choose between 0 - 9" << endl;
        return 0;
    }
    if (opponentGridGuess[b][a - 'A'] != '.')
    {
        cout << "Already made a guess on this cell" << endl;
        return 0;
    }
    return 1;
}

bool valid_move(int player, int move, string cord, int size)
{
    char a = cord[0];
    int b = cord[1] - '0';
    if (!(a >= 'A' && a <= 'J'))
    {
        cout << "Entered coordinates are out of bounds choose between A - J" << endl;
        return 0;
    }
    if (b > 9 || b < 0)
    {
        cout << "Entered coordinates are out of bounds choose between 0 - 9" << endl;
        return 0;
    }

    if (move == 1)
    {
        size = 5 - size;
        if (a > 'J' - size + 1)
        {
            cout << "Entered coordinates make the ship hang off board" << endl;
            return 0;
        }
        // bool flag=1;
        if (player == 1)
        {
            for (int i = 0; i < size; i++)
            {
                if (playerGrid[b][a - 'A' + i] != '.')
                {
                    cout << "A ship already placed" << endl;
                    return 0;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (opponentGrid[b][a - 'A' + i] != '.')
                {
                    cout << "A ship already placed" << endl;
                    return 0;
                }
            }
        }
    }
    else
    {
        size = 5 - size;
        if (b > 10 - size)
        {
            cout << "Entered coordinates make the ship hang off board" << endl;
            return 0;
        }
        if (player == 1)
        {
            for (int i = 0; i < size; i++)
            {
                if (playerGrid[b + i][a - 'A'] != '.')
                {
                    cout << "A ship already placed" << endl;
                    return 0;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (opponentGrid[b + i][a - 'A'] != '.')
                {
                    cout << "A ship already placed" << endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Function to place ships on the grid during the planning phase
void placeShips1(int move, string cord, int shipSize, char shipSymbol)
{
    int a = cord[0] - 'A';
    int b = cord[1] - '0';

    for (int i = 0; i < shipSize; ++i)
    {
        if (move == 1)
        {
            playerGrid[b][a + i] = shipSymbol;
        }
        else
        {
            playerGrid[b + i][a] = shipSymbol;
        }
    }
}

void placeShips2(int move, string cord, int shipSize, char shipSymbol)
{

    int a = cord[0] - 'A';
    int b = cord[1] - '0';

    for (int i = 0; i < shipSize; ++i)
    {
        if (move == 1)
        {
            opponentGrid[b][a + i] = shipSymbol;
        }
        else
        {
            opponentGrid[b + i][a] = shipSymbol;
        }
    }
}

// Function to play the Battleship game
void playBattleship()
{

    // Planning Phase - Player 1 places ships
    displayGrid(playerGrid);
    cout << "Player 1, it's the planning phase." << endl;
    cout << "Player 1, you have 5 ships : Aircraft carrier (occupies 5 spaces), Battleship (4 spaces), Destroyer (3 spaces), Corvette (2 spaces) and Frigate (1 space)." << endl;
    cout << "The ships can only be placed vertically or horizontally. Diagonal placement is not allowed. Ships cannot hang off the board, nor can they be placed one over another." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Choose orientation for " << ships[i] << " (1 for horizontal 2 for vertical) : ";
        int move;
        cin >> move;
        string cord;
        if (move == 1)
        {
            cout << "Enter the leftmost cordinate of your " << ships[i] << "(e.g., A1): ";

            cin >> cord;
        }
        else if (move == 2)
        {
            cout << "Enter the topmost cordinate of your " << ships[i] << "(e.g., A1): ";
            cin >> cord;
        }
        else
        {
            i--;
            continue;
        }
        if (valid_move(1, move, cord, i))
        {
            placeShips1(move, cord, 5 - i, shipSymbol[i].first);
            displayGrid(playerGrid);
        }
        else {
            i--;
        }
    }
    system("pause");
    system("cls");

    // Planning Phase - Player 2 places ships
    displayGrid(opponentGrid);
    cout << "Player 2, it's the planning phase." << endl;
    cout << "Player 2, you have 5 ships : Aircraft carrier (occupies 5 spaces), Battleship (4 spaces), Destroyer (3 spaces), Corvette (2 spaces) and Frigate (1 space)." << endl;
    cout << "The ships can only be placed vertically or horizontally. Diagonal placement is not allowed. Ships cannot hang off the board, nor can they be placed one over another." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Choose orientation for " << ships[i] << " (1 for horizontal 2 for vertical) : ";
        int move;
        cin >> move;
        string cord;
        if (move == 1)
        {
            cout << "Enter the leftmost cordinate of your " << ships[i] << "(e.g., A1): ";
            cin >> cord;
        }
        else if (move == 2)
        {
            cout << "Enter the topmost cordinate of your " << ships[i] << "(e.g., A1): ";
            cin >> cord;
        }
        else
        {
            i--;
            continue;
        }
        if (valid_move(2, move, cord, i))
        {
            placeShips2(move, cord, 5 - i, shipSymbol[i].first);
            displayGrid(opponentGrid);
        }
        else{
            i--;
        }
    }
    system("pause");
    system("cls");

    // Guessing Phase
    for (int turn = 1;; ++turn)
    {
        cout << "Turn " << turn << endl;

        // Player 1's turn
        cout << "Player 1, it's your turn to guess." << endl;
        displayGrid(playerGridGuess);
        cout << "Enter the coordinates (e.g., A1): ";
        string guess1;
        cin >> guess1;
        while (!valid_guess1(guess1))
        {
            cin >> guess1;
        }
        update_grid_2(guess1);
        cout << "Player 1 own grid" << endl;
        displayGrid(playerGrid);
        cout << "Player 1 guess grid(* means miss, H means hit, . means no guess made for the cell yet)" << endl;
        displayGrid(playerGridGuess);
        system("pause");
        system("cls");

        // Player 2's turn
        cout << "Player 2, it's your turn to guess." << endl;
        displayGrid(opponentGridGuess);
        cout << "Enter the coordinates (e.g., A1): ";
        string guess2;
        cin >> guess2;
        while (!valid_guess2(guess2))
        {
            cin >> guess2;
        }
        update_grid_1(guess2);
        cout << "Player 2 own grid" << endl;
        displayGrid(opponentGrid);
        cout << "Player 2 guess grid(* means miss, H means hit, . means no guess made for the cell yet)" << endl;
        displayGrid(opponentGridGuess);

        system("pause");
        system("cls");

        // Check for game end conditions and break the loop if necessary
        if (player2 == 5)
        {
            cout << "Player 1 won! " << endl;
            break;
        }
        else if (player1 == 5)
        {
            cout << "Player 2 won! " << endl;
            break;
        }
    }
}

int main()
{
    playBattleship();
    return 0;
}
