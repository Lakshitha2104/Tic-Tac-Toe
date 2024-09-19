#include <iostream>
using namespace std;

void displayboard(char board[3][3]);
bool checkwin(char board[3][3], char player);
bool checktie(char board[3][3]);
bool isvalidmove(char board[3][3], int move);
void makemove(char board[3][3], int move, char player);

int main() {
    char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    char currentplayer = 'X';
    bool gameEnd = false;
    int move;
    
    while (!gameEnd) {
        displayboard(board);
        cout << "Player " << currentplayer << ", enter your move (1-9): ";
        cin >> move;

        while (!isvalidmove(board, move)) {
            cout << "Invalid move. Try again: ";
            cin >> move;
        }

        makemove(board, move, currentplayer);

        if (checkwin(board, currentplayer)) {
            displayboard(board);
            cout << "Player " << currentplayer << " wins!" << endl;
            gameEnd = true;
        }
        else if (checktie(board)) {
            displayboard(board);
            cout << "The game is a tie!" << endl;
            gameEnd = true;
        }
        else {
            currentplayer = (currentplayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void displayboard(char board[3][3]) {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkwin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checktie(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool isvalidmove(char board[3][3], int move) {
    if (move < 1 || move > 9) {
        return false;
    }
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

void makemove(char board[3][3], int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = player;
}