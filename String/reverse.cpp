#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abcd";
    int i = 0,j = s.size() - 1;
    while(i <= j){
        swap(s[i++], s[j--]);
    }
    cout << s;
}