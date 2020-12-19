//
//  main.cpp
//  CoinChange
//
//  Created by Nikhil Parihar on 16/12/20.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int coinChange(vector<int> v, int sum, int n){
    if(n == 0 && sum > 0){
        dp[n][sum] = -1;
        return 0;
    }
    if(sum == 0){
        dp[n][sum] = 0;
        return 1;
    }
    if(v[n - 1] > sum){
        dp[n][sum] = coinChange(v, sum, n - 1);
        return dp[n][sum];
    }
    else{
        dp[n][sum] = coinChange(v, sum, n - 1) + coinChange(v, sum - v[n - 1], n);
        return dp[n][sum];
    }
}

int main(int argc, const char * argv[]) {
    vector<int> v = {1, 2, 3};
    int sum = 5;
    cout << coinChange(v, sum, v.size()) << " " ;
    vector<vector<int>> sp(v.size() + 1, vector<int>(sum + 1, 0));
    for(int i = 0 ; i < sp.size() ; i++){
        sp[i][0] = 1;
    }
    for(int i = 1 ; i < sp.size() ; i++){
        for(int j = 1 ; j < sp[0].size() ; j++){
            if(v[i - 1] > j){
                sp[i][j] = sp[i - 1][j];
            }
            else{
                sp[i][j] = sp[i - 1][j] + sp[i][j - v[i - 1]];
            }
        }
    }
    cout << sp[sp.size() - 1][sp[0].size() - 1];
    return 0;
}
