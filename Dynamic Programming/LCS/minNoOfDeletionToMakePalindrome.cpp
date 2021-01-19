#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "agbcba";
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 1 ; i < dp.size() ; i++){
        for(int j = 1 ; j < dp[0].size() ; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << s1.size() - dp[s1.size()][s1.size()]; 

}