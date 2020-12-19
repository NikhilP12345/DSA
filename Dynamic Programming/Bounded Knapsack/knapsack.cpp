#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100, vector<int>(100, -1));
int knapsack(int n, vector<int> weight, vector<int> val, int maxW){
    if(n <= 0 || maxW == 0){
        dp[n][maxW] = 0;
        return 0;
    }
    if(dp[n][maxW] != -1){
        return dp[n][maxW];
    }
    if(weight[n - 1] > maxW){
        dp[n][maxW] =  knapsack(n - 1, weight,val, maxW);
        return dp[n][maxW];
    }
    else{
        dp[n][maxW] = max(knapsack(n - 1, weight, val, maxW), val[n - 1] + knapsack( n - 1, weight, val, maxW - weight[n - 1]));
        return dp[n][maxW];
    }
}


int main(){
    vector<int> weight {1,3,4,5};
	vector<int> val {1,4,5,7};
	int maxW = 7;
	cout << knapsack(weight.size(), weight, val, maxW);
    // vector<vector<int>> t(weight.size() + 1  , vector<int>(maxW + 1, 0));
    // for(int i = 1 ; i < t.size() ; i++){
    //     for(int j = 1 ; j < t[0].size() ; j++){
    //         if(weight[i - 1] > j){
    //             t[i][j] = t[i - 1][j];
    //         }
    //         else{
    //             t[i][j] = max(t[i - 1][j], val[i - 1] + t[i - 1][j - weight[i - 1]]);
    //         }
    //     }
    // }
    // cout << t[t.size() - 1][t[0].size() - 1];
}