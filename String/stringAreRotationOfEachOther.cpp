#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "ABCD";
    string s2 = "CDAB";
    string result = s1 + s1;
    if(result.find(s2) != string::npos){
        cout << "present";
    }
    else{
        cout << "not";
    }
}