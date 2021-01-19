#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<char> v;
    string s = "abcdab";
    for(auto i: s){
        if(v.find(i) == v.end()){
            v.insert(i);
        }
        else{
            cout << i << " ";
        }
    }
}