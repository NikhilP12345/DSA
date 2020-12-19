#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> board, int n) {
	//in row
	for (int row = 0; row < i; row++) {
		if (board[row][j] == 1) {
			return false;
		}
	}
	int x = i;
	int y = j;

	//left
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}
	x = i;
	y = j;

	//right
	while (x >= 0 && y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}
	return true;
}

bool printQueens(int n, vector<vector<int>> &board, int i) {
	// true condition
	if (i == n) {
		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				cout << board[x][y] << " ";
			}
			cout << "\n";
		}
		return true;
	}
	// traversing column
	for (int j = 0; j < n; j++) {
		// safe to put queen at i, j
		if (isSafe(i, j, board, n)) {
			board[i][j] = 1;
			// safe to put queen at next
			bool nextQueen = printQueens(n, board, i + 1);
			// if yes return true
			if (nextQueen) {
				return true;
			}
			// if false then move to other place
			board[i][j] = 0;
		}
	}
	// if traverse through whole column no place to place so backtrack
	return false;
}

int main() {
	int n = 2;
	vector<vector<int>> board(10, vector<int>(10, 0));
	printQueens(n, board, 0);
}
