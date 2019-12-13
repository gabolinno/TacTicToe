#pragma once
#include<iostream>

using namespace std;

const int MAX_SIZE = 3;

class Board {
private:
	int board[MAX_SIZE][MAX_SIZE];

public:
	Board() {
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				board[i][j] = ' ';
			}
		}
	}

	void print() {
		for (int i = 0; i < MAX_SIZE; i++) {
			cout << "     |     |     " << endl;
			for (int j = 0; j < MAX_SIZE; j++) {
				if (j == 0) {
					cout << "  ";
				}
				cout << (char)board[i][j];
				if (j != 2) {
					cout << "  |  ";
				}
			}
			cout << endl;

			if (i != 2) {
				cout << "_____|_____|_____" << endl;
			}
			else {
				cout << "     |     |     " << endl << endl;
			}
		}
	}

	bool validCoords(int x, int y) {
		return x >= 1 && x <= MAX_SIZE && y >= 1 && y <= MAX_SIZE;
	}

	bool isCellEmpty(int x, int y) {
		if (board[x - 1][y - 1] == ' ') {
			return true;
		}
		return false;
	}


	bool isFull() {
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				if (board[i][j] == ' ') {
					return false;
				}
			}
		}
		return true;
	}

	bool isGameOver() {
		if (isFull() || whoWon() == 'X' || whoWon() == 'O') {
			return true;
		}
		return false;
	}

	char whoWon() {
		for (int i = 0; i < MAX_SIZE; i++) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
				return board[i][0];
			}
			else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
				return board[0][i];
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
			return board[0][0];
		}
		else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
			return board[2][0];
		}
		return 'N';
	}

	void clearMove(int x, int y) {
		if (validCoords(x, y)) {
			board[x - 1][y - 1] = ' ';
		}
	}

	bool makeAMove(int x, int y, char player) {
		if ((player == 'X' || player == 'O') && validCoords(x, y) && board[x - 1][y - 1] == ' ') {
			board[x - 1][y - 1] = player;
			return true;
		}
		return false;
	}
};