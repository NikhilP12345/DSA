#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,6,11,5};
    int sum = 0;
    for(auto i: v){
        sum += i;
    }
    vector<vector<int>> dp(v.size() + 1, vector<int>(sum + 1, 0));
    for(int i = 0 ; i < dp.size() ; i++){
        dp[i][0] = 1;
    }
    for(int i = 1 ; i < dp.size() ; i++){
        for(int j = 1 ; j < dp[0].size(); j++){
            if(v[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i - 1]];
            }
        }
    }
    int minDiff = 100;
    for(int i = 1 ; i <= dp[0].size() / 2 ; i++){
        if(dp[dp.size() - 1][i] == 1){
            minDiff = min(minDiff, abs(2 * i - sum));
        }
    }
    cout << minDiff;

}