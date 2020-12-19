#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

bool isSafe(int i, int j, vector<int>& dp, vector<vector<int>> v) {
    for (int k = 0; k < v.size(); k++) {
        if (v[i][k] == 1 && dp[k] == j) {
            return false;
        }
    }
    return true;
}

bool graphUtil(int i, vector<int>& dp, vector<vector<int>> v, int m, int n) {
    if (i == n) {
        return true;
    }
    for (int j = 1; j <= m; j++) {
        if (isSafe(i, j, dp, v)) {
            dp[i] = j;
            if (graphUtil(i + 1, dp, v, m, n)) {
                return true;
            }
            dp[i] = 0;
        }
    }
    return false;
}

void graphColoring(vector<vector<int>> v, int m) {
    vector<int> dp(v.size(), 0);
    if (graphUtil(0, dp, v, m, v.size())) {
        for (int i = 0; i < dp.size(); i++) {
            cout << dp[i] << " ";
        }
    }
}


int main() {
	vector<vector<int>> v = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3;
    graphColoring(v, 3);
}
