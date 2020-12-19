//
//  main.cpp
//  MinCoinChange
//
//  Created by Nikhil Parihar on 16/12/20.
//

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> v = {1, 2, 3, 5};
    int sum = 5;
    vector<vector<int>> dp(v.size() + 1, vector<int>(sum + 1, 0));
    for(int i = 0 ; i < dp[0].size() ; i++){
        dp[0][i] = INT_MAX - 1;
    }
    for(int i = 1 ; i < dp[0].size() ; i++){
        if(i % v[0] == 0){
            dp[1][i] = i / v[0];
        }
        else{
            dp[1][i] = INT_MAX - 1;
        }
    }
    for(int i = 2 ; i < dp.size() ; i++){
        for(int j = 1 ; j < dp[0].size() ; j++){
            if(v[i - 1] <= j){
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - v[i - 1]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[dp.size() - 1][dp[0].size() - 1];
    return 0;
}
