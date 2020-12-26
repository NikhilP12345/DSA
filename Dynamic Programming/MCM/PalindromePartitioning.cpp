#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int i = 0;
    int j = s.size() - 1;
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

int palindromePartitioning(string s, int start){
    for(int i = start; i < s.size() ; i++){
        if(isPalindrome())
    }
}

int main(){
    string s = "nitin";
    palindromePartitioning(s);
}