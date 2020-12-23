#include <bits/stdc++.h>
using namespace std;

int longestcommonsubstring(string s1, string s2, int n1, int n2, int count){
    if(n1 == 0 || n2 == 0){
        return 0;
    }
    if(s1[n1 - 1] == s2[n2 - 1]){
        count = longestcommonsubstring(s1, s2, n1 - 1, n2 - 1, count + 1);
        return count;
    }
    count = max(count, max(longestcommonsubstring(s1, s2, n1 - 1, n2, count),longestcommonsubstring(s1, s2, n1, n2 - 1, count)));
    return count;
}

int main(){
    string s1 = "abcde";
	string s2 = "abfce";
    int maxEl = INT_MIN;
    cout << longestcommonsubstring(s1, s2, s2.size(), s2.size(),0);
    vector<vector<int>> sp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 1 ; i < sp.size() ; i++){
        for(int j = 1 ; j < sp[0].size() ; j++){
            if(s1[i - 1] == s2[j - 1]){
                sp[i][j] = sp[i - 1][j - 1] + 1;
                maxEl = max(maxEl, sp[i][j]); 
            }
            else{
                sp[i][j] = 0;
            }
        }
    }
    cout << maxEl;
}