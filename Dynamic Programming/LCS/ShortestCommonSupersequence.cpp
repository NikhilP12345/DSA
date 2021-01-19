#include <bits/stdc++.h>
using namespace std;


int main(){
    string s1 = "geek";
    string s2 = "eke";
    
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
    for(auto i : dp){
        for(auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
    int i = s1.size();
    int j = s2.size();
    string s = "";
    while(i > 0 && j > 0){
        if(dp[i - 1][j] == dp[i][j]){
            s += s1[i - 1];
            i--;
        }
        else if(dp[i][j - 1] == dp[i][j]){
            s += s2[j - 1];
            j--;
        }
        else{
            s += s1[i - 1];
            i--;
            j--;
        }
    }
    while(i > 0){
        s += s1[i - 1];
        i--;
    }
    while(j > 0){
        s += s2[j - 1];
        j--;
    }
    reverse(s.begin(), s.end());
    cout << s;
}