#include <iostream>
#include <vector>

// Function to draw the Tic Tac Toe board
void drawBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j != 2)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i != 2)
            std::cout << "   ---------\n";
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to play the Tic Tac Toe game
void playGame() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';

    // Main game loop
    while (true) {
        std::cout << "Current Board:\n";
        drawBoard(board);

        // Get player input
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;

        // Validate input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Please try again.\n";
            continue;
        }

        // Update the board
        board[row - 1][col - 1] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!\n";
            drawBoard(board);
            break;
        }

        // Check if it's a draw
        bool isDraw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    isDraw = false;
                    break;
                }
            }
        }
        if (isDraw) {
            std::cout << "It's a draw!\n";
            drawBoard(board);
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    std::cout << "Welcome to Tic Tac Toe!\n";
    playGame();
    return 0;
}
