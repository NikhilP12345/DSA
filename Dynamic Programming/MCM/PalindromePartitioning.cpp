#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
vector<vector<int>> dp(100, vector<int>(100, -1));
int palindromePartitioning(string s, int i, int j){
    if(i >= j){
        dp[i][j] = 0;
        return 0;
    }
    if(isPalindrome(s, i, j)){
        dp[i][j] = 0;
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ansEl = INT_MAX;
    for(int k = i ; k < j ; k++){
        int left = 0;
        int right = 0;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = palindromePartitioning(s, i, k);
            dp[i][k] = left;
        }
        if(dp[k + 1][j] != -1){
            right = dp[k + 1][j];
        }
        else{
            right = palindromePartitioning(s, k + 1, j);
            dp[k + 1][j] = right;
        }
        int temp = 1 + left + right;
        dp[i][j] = temp;
        ansEl = min(temp, ansEl);
    }
    return ansEl;
}

int main(){
    string s = "nitik";
    cout << palindromePartitioning(s, 0, s.size() - 1);
}