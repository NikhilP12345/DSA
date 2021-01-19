#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "heap";
    string s2 = "pea";

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
    int a = dp[s1.size()][s2.size()];
    cout << "Insertion: " << s2.size() - a << "\n";
    cout << "Deletion: " << s1.size() - a << "\n";
}