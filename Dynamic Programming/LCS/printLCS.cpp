#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    string s1 = "abcdgh";
	string s2 = "abedfgr";
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
    string s = "";
    int i = s1.size();
    int j = s2.size();
    while(i > 0 && j > 0){
        if(sp[i - 1][j] == sp[i][j]){
            i--;
        }
        else if(sp[i][j - 1] == sp[i][j]){
            j--;
        }
        else{
            s += s1[i - 1];
            i--;
            j--;
        }
    }
    cout << s;
}