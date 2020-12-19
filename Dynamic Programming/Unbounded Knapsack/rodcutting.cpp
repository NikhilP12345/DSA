#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1000, vector<int>(100, -1));
int rodcutting(vector<int> v, vector<int> price, int weight, int n){
    if(n <= 0 || weight == 0){
        dp[n][weight] = 0;
        return 0;
    }
    if(dp[n][weight] != -1){
        return dp[n][weight];
    }
    if(v[n - 1] > weight){
        dp[n][weight] =  rodcutting(v, price, weight, n - 1);
        return dp[n][weight];
    }
    else{
        dp[n][weight] = max(rodcutting(v, price, weight, n - 1),
         price[n - 1] + rodcutting(v, price, weight - v[n - 1], n));
        return dp[n][weight];
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = 8;
    cout << rodcutting(arr, price, N, arr.size());
    vector<vector<int>> sp(arr.size() + 1, vector<int>(N + 1, 0));
    for(int i = 1 ; i < sp.size() ; i++){
        for(int j = 1 ; j < sp[0].size() ; j++){
            if(arr[i - 1] > j){
                sp[i][j] = sp[i - 1][j];
            }
            else{
                sp[i][j] = max(price[i - 1] + sp[i][j - arr[i - 1]], sp[i - 1][j]);
            }
        }
    }
    cout << "\n";
    cout << sp[N][N];
}
