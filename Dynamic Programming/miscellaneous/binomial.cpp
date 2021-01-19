#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100, vector<int>(100, -1));

int binomial(int n, int k){
    if(k > n){
        dp[n][k] = 0;
        return 0;
    }
    if(k == 0 || k == n){
        dp[n][k] = 1;
        return 1;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    else{
        dp[n][k] = binomial(n - 1, k - 1) + binomial(n - 1, k);
        return dp[n][k];
    }
}

int main(){
    cout << binomial(4, 2);
}