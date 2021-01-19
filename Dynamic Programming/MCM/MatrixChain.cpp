#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));
int solve(vector<int> v, int i, int j){
    if(i >= j){
        dp[i][j] = 0;
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int minEl = INT_MAX;
    for(int k = i ; k < j ; k++){
        dp[i][j] = v[i - 1] * v[k] * v[j] + solve(v, i, k) + solve(v, k + 1, j);
        minEl = min(minEl, dp[i][j]);
    }
    return minEl;
}


int main(){
    vector<int> v = {40, 20, 30, 10, 30};
    cout << solve(v, 1, v.size() - 1);
}