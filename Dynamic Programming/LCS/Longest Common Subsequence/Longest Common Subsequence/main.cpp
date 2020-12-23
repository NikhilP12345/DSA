//
//  main.cpp
//  Longest Common Subsequence
//
//  Created by Nikhil Parihar on 19/12/20.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int lcs(string s1, string s2, int n1, int n2){
    if(n1 == 0 || n2 == 0){
        dp[n1][n2] = 0;
        return 0;
    }
    if(dp[n1][n2] != -1){
        return dp[n1][n2];
    }
    if(s1[n1 - 1] == s2[n2 - 1]){
        dp[n1][n2] =  1 + lcs(s1, s2, n1 - 1, n2 - 1);
        return dp[n1][n2];
    }
    else{
        dp[n1][n2] = max(lcs(s1, s2, n1 - 1, n2), lcs(s1, s2, n2, n2 - 1));
        return dp[n1][n2];
    }
}


int main(int argc, const char * argv[]) {
    string s1 = "abcdgh";
	string s2 = "abedfgr";
    // cout << lcs(s1, s2, s1.size(), s2.size());
    vector<vector<int>> sp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 1 ; i < sp.size() ; i++){
        for(int j = 1 ; j < sp[0].size() ; j++){
            if(s1[i - 1] == s2[j - 1]){
                sp[i][j] = sp[i - 1][j - 1] + 1;
            }
            else{
                sp[i][j] = max(sp[i - 1][j] , sp[i][j - 1]);
            }
        }
    }
    cout << sp[s1.size()][s2.size()];
    return 0;
}
