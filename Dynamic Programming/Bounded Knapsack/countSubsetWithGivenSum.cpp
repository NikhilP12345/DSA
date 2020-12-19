#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100,-1));

int subsetSumCount(vector<int> v, int n, int sum){
    if(n == 0 && sum > 0){
        dp[n][sum] = 0;
        return 0;
    }
    if(sum == 0){
        dp[n][sum] = 1;
        return 1;
    }
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(v[n - 1] > sum){
        dp[n][sum] = subsetSumCount(v, n - 1, sum); 
        return dp[n][sum];
    }
    else{
        dp[n][sum] =  subsetSumCount(v, n - 1, sum) + subsetSumCount(v, n - 1, sum - v[n - 1]);
        return dp[n][sum];
    }
}

int main(){
    vector<int> v = { 2,3,5,6,8,10};
	int sum = 10;
    // cout << subsetSumCount(v, v.size(), sum);
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
                sp[i][j] = sp[i - 1][j] + sp[i - 1][j - v[i - 1]];
            }
        }
    }
    cout << sp[sp.size() - 1][sp[0].size() - 1];
}