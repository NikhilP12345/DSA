#include<bits/stdc++.h>
using namespace std;

int main(){
    string a = "agbcba";
    string b = a;
    reverse(b.begin(), b.end());
    vector<vector<int>> dp(a.size() + 1, vector<int>(a.size() + 1, 0));
    for(int i = 1 ; i < dp.size() ; i++){
        for(int j = 1 ; j < dp[0].size() ; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
 
    }
    cout << dp[a.size()][b.size()];
}