#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
using namespace std;
bool isSafe(int i, int j, vector<vector<int>> v, int n, vector<vector<bool>> visited) {
    if (i == -1 || i == n || j == -1 || j == n || visited[i][j] || v[i][j] == 0) {
        return false;
    }
    return true;
}
void print(vector<vector<bool>> visited) {
    for (auto i : visited) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void printUtil(int i, int j, vector<vector<int>> v, int n,
    string& path, vector<string>& possiblePath, vector<vector<bool>> visited) {
    if (i == -1 || i == n || j == -1 || j == n || visited[i][j] || v[i][j] == 0) {
        return;
    }
    if (i == n - 1 && j == n - 1) {
        possiblePath.push_back(path);
    }
    visited[i][j] = true;
    if (isSafe(i + 1, j, v, n, visited)) {
        path.push_back('D');
        printUtil(i + 1, j, v, n, path, possiblePath, visited);
        path.pop_back();
    }
    if (isSafe(i, j + 1, v, n, visited)) {
        path.push_back('R');
        printUtil(i, j + 1, v, n, path, possiblePath, visited);
        path.pop_back();
    }
    if (isSafe(i - 1, j, v, n, visited)) {
        path.push_back('U');
        printUtil(i - 1, j, v, n, path, possiblePath, visited);
        path.pop_back();
    }
    if (isSafe(i , j - 1, v, n, visited)) {
        path.push_back('L');
        printUtil(i , j - 1, v, n, path, possiblePath, visited);
        path.pop_back();
    }
    visited[i][j] = false;

}


void printPath(vector<vector<int>> v) {
    vector<string> possiblePaths;
    string path;
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    printUtil(0, 0, v, 4, path, possiblePaths, visited);
    for (auto i : possiblePaths) {
        cout << i << " ";
    }
}

int main() {
	vector<vector<int>> v = { {1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}
                            };
    printPath(v);

}
