#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100, vector<int>(100, -1));

bool subsetSum(vector<int> v, int sum, int n){
    if(n == 0 && sum > 0){
        dp[n][sum] = 0;
        return false;
    }
    if(sum == 0){
        dp[n][sum] = 1;
        return true;
    }
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(v[n - 1] > sum){
        dp[n][sum] = subsetSum(v, sum, n - 1); 
        return dp[n][sum];
    }
    else{
        dp[n][sum] = subsetSum(v, sum, n - 1) || subsetSum(v, sum - v[n - 1], n - 1);
        return dp[n][sum];
    }
}

int main(){
    vector<int> v = { 2,3,7,8,10 };
	int sum = 13;

    // cout << subsetSum(v, sum, v.size());

    vector<vector<bool>> t(v.size() + 1, vector<bool>(sum + 1, false));
    for(int i = 0 ; i < t.size() ; i++){
        t[i][0] = true;
    }
    for(int i = 1 ; i < t.size() ; i++){
        for(int j = 1 ; j < t[0].size() ; j++){
            if(v[i - 1] > j){
                t[i][j] = t[i - 1][j];
            }
            else{
                t[i][j] = t[i - 1][j] || t[i - 1][j - v[i - 1]];
            }
        }
    }
    cout << t[t.size() - 1][t[0].size() - 1];
}