#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100, vector<int>(100, -1));
int permutation(int n, int k){
    if(k == 0){
        dp[n][k] = 1;
        return 1;
    }
    if(k > n){
        dp[n][k] = 0;
        return 0;
    }
    else{
        dp[n][k] =  k * permutation(n - 1, k - 1) + permutation(n - 1, k);
        return dp[n][k];
    }
}

int main(){
    // cout << permutation(10, 3);
    int n = 10;
    int k = 3;
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // for(int i = 0 ; i <= n ; i++){
    //     for(int j = 0 ; j <= min(i, k) ; j++){
    //         if(j == 0){
    //             dp[i][j] = 1;
    //         }
    //         else{
    //             dp[i][j] = j * dp[i - 1][j - 1] + dp[i - 1][j];
    //         }
    //     }
    // }
    // cout << dp[n][k];
    vector<int> dp(k + 1, 0);
    for(int i = 1 ; i <= n ; i++){
        for(int j = min(i, k) ; j > 0 ; j--){
            dp[j] = dp[j] + dp[j - 1];
        }
    }
}