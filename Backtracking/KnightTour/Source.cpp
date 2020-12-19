#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

bool isSafe(vector<vector<int>> v, int i, int j) {
	if (i < v.size() && i >= 0 && j < v.size() && j >= 0 && v[i][j] == -1) {
		return true;
	}
	return false;
}

bool knight(vector<vector<int>>& v, int n, int i, int j, int xMove[], int yMove[], int total) {
	int a, b;
	if (total == n * n) {
		return true;
	}
	for (int k = 0; k < 8; k++) {
		a = i + xMove[k];
		b = j + yMove[k];
		if (isSafe(v, a, b)) {
			v[a][b] = total;
			if (knight(v, n, a, b, xMove, yMove, total + 1)) {
				return true;
			}
			v[a][b] = -1;
		}
	}
	return false;;
}

int main() {
	int n = 8;
	vector<vector<int>> v(n, vector<int>(n, -1));
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	v[0][0] = 0;
	if (knight(v, n, 0, 0, xMove, yMove, 1)) {
		for (auto i : v) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << "\n";
		}
	}
}
