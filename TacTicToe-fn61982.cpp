#include<iostream>
#include"Board.h";

using namespace std;

int index1, index2;


int minimax(Board& board, int depth, bool isMax, char player, int alpha = -1000, int beta = 1000) {
	char opponent = (player == 'X') ? 'O' : 'X';
	int max_val = -1000, min_val = 1000;
	int v = 1;
	if (board.whoWon() == opponent) {
		return 10 -  depth;
	} else if (board.whoWon() == player) {
		return -10 + depth;
	} else if (board.isFull()) {
		return 0;
	}

	if (isMax) {
		bool flag = false;
		for (int i = 1; i < MAX_SIZE + 1; i++) {
			for (int j = 1; j < MAX_SIZE + 1; j++) {
				if (board.isCellEmpty(i, j)) {
					board.makeAMove(i, j, opponent);
					int minimax_val = minimax(board, depth + 1, !isMax, player, alpha, beta);

					alpha = (alpha > minimax_val) ? alpha : minimax_val;
					board.clearMove(i, j);
					
					if (alpha >= beta) {
						flag = true;
						break;
					}

				}
			}
			if (flag) break;
		}
		return alpha;
	}
	else {
		bool flag = false;
		for (int i = 1; i < MAX_SIZE + 1; i++) {
			for (int j = 1; j < MAX_SIZE + 1; j++) {
				if (board.isCellEmpty(i, j)) {
					board.makeAMove(i, j, player);
					int minimax_val = minimax(board, depth + 1, !isMax, player, alpha, beta);
					beta = (beta < minimax_val) ? beta : minimax_val;
					board.clearMove(i, j);

					if (alpha >= beta)
					{
						flag = true; 
						break;
					}
				}
			}
			if (flag) break;
		}
		return beta;
	}
}


void findBestMove(Board& board, char opponent) {
	char player = (opponent == 'X') ? 'O' : 'X';
	int bestVal = -1000;
	
	for (int i = 1; i < MAX_SIZE + 1; i++) {
		for (int j = 1; j < MAX_SIZE + 1; j++) {
			if (board.isCellEmpty(i, j)) {
				board.makeAMove(i, j, opponent);
				int moveVal = minimax(board, 0, false, player);
				board.clearMove(i, j);
				if (moveVal > bestVal) {
					index1 = i ;
					index2 = j ;
					bestVal = moveVal;
				}
			}
		}
	}
}

bool hasTheGameEnd(Board b, char player) {
	char opponent = (player == 'X') ? 'O' : 'X';
	if (b.isGameOver()) {
		b.print();
		if (b.whoWon() == player) {
			cout << "-------------------------" << endl;
			cout << "Congratulations! You Won!" << endl;
			cout << "-------------------------" << endl << endl;
			return true;
		}
		else if (b.whoWon() == opponent) {
			cout << "------------------------" << endl;
			cout << "Sorry! The computer won!" << endl;
			cout << "------------------------" << endl << endl;
			return true;
		}
		else if (b.whoWon() == 'N') {
			cout << "-------------------------" << endl;
			cout << "Good game! It was a draw!" << endl;
			cout << "-------------------------" << endl << endl;
			return true;
		}
	}
	return false;

}

bool humanMakeAMove(Board& b, char player) {
	cout << "Enter your move (two digits between 1 and 3): ";
	int x, y;
	cin >> x >> y;
	if (!b.makeAMove(x, y, player)) {
		return false;
	}
	return true;
}

bool aiMakeAMove(Board& b, char player) {
	char opponent = (player == 'X') ? 'O' : 'X';
	findBestMove(b, opponent);
	cout << "Computer's move: " << index1 << " " << index2 << endl;
	if (b.makeAMove(index1, index2, opponent)) return true;
	return false;
}

int main() { 
	Board b;
	char player;
	do {
		cout << "Enter X to be first and O otherwise: ";
		cin >> player;
	} while (player != 'X' && player != 'O');

	cout << "Let's begin the game!" << endl;
	cout << "Player 1 (X)" << ((player == 'X') ? "(YOU)" : "(Computer)") << "  -  Player 2 (O)" << ((player == 'O') ? "(YOU)" : "(Computer)") << endl << endl;
	cout << endl;
	b.print();
	while (!b.isGameOver()) {
		if (player == 'X') {
			if (!humanMakeAMove(b, player)) {
				continue;
			}
			b.print();
			if (hasTheGameEnd(b, player)) {
				break;
			}

			aiMakeAMove(b, player);
			if (hasTheGameEnd(b, player)) {
				break;
			}
		} else {
			aiMakeAMove(b, player);
			b.print();
			if (hasTheGameEnd(b, player)) {
				break;
			}

			while (!humanMakeAMove(b, player)) {
			}
			if (hasTheGameEnd(b,player)) {
				break;
			}
		}
		b.print();

	}

	system("pause");
	return 0;
}