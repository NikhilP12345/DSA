#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

bool isPossible(vector<vector<int>> &v, int& i, int& j) {
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (v[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(vector<vector<int>> &v, int num, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (v[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (v[i][col] == num) {
            return false;
        }
    }
    int x = row - row % 3;
    int y = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[x + i][y + j] == num) {
                return false;
            }
        }
    }

    if (v[row][col] != 0) {
        return false;
    }
    return true;
}

bool Sudoku(vector<vector<int>> &v) {
    int row, col;
    if (isPossible(v, row, col)) {
        return true;
    }
    for (int i = 1; i <= 9; i++) {
        if (isSafe(v, i, row, col)) {
            v[row][col] = i;
            if (Sudoku(v)) {
                return true;
            }
            v[row][col] = 0;
        }
    }
    return false;
}



int main() {
	vector<vector<int>> grid = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (Sudoku(grid)) {
        for (auto i : grid) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "No solution";
    }
}