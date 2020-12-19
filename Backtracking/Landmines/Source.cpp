#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;
vector<int> row = { 1, -1, 0, 0 };
vector<int> col = { 0 , 0, -1, 1 };
bool isSafe(vector<vector<int>> v, int r, int c, vector<vector<int>> visited) {
	if (visited[r][c] || v[r][c] == 0) {
		return false;
	}
	return true;
}

bool isValid(vector<vector<int>> v, int r, int c) {
	if (r < 0 || r >= v.size() || c < 0 || c >= v[0].size()) {
		return false;
	}
	return true;
}

void util(vector<vector<int>> v, vector<vector<int>>& visited, int r, int c, int& minD, int d) {
    if (c == v[0].size() - 1) {
        minD = min(minD, d);
        return;
    }
    if (d > minD) {
        return;
    }
    visited[r][c] = 1;
    for (int k = 0; k < 4; k++) {
        if (isValid(v, r + row[k], c + col[k]) && isSafe(v, r + row[k], c + col[k], visited)) {
            util(v, visited, r + row[k], c + col[k], minD, d + 1);
        }
    }
    visited[r][c] = 0;
}

void findShortest(vector<vector<int>> v) {
    int min_D = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    if (isValid(v, i + row[k], j + col[k])) {
                        v[i + row[k]][j + col[k]] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == -1) {
                v[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i][0] == 1) {
            vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 0));
            util(v, visited, i, 0, min_D, 0);
            if (min_D == v[0].size() - 1) {
                return;
            }
        }
    }
    cout << min_D;
}


int main() {
	vector<vector<int>> v = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    findShortest(v);
}