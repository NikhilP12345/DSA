//
//  main.cpp
//  longest Pallindrome
//
//  Created by Nikhil Parihar on 19/01/21.
//

#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string str) {
    if(str.length() == 1){
        return str;
    }
    string result = "";
    for(int i = 1 ; i < str.length()  ; i++){
        string s = "";
        int a = i - 1;
        int b = i + 1;
        if(str[a] == str[b]){
                while(a >= 0 && b < str.length() ){
                        if(str[a] != str[b]){
                            break;
                        }
                        a--;
                        b++;
                }
            s = str.substr(a + 1, b - a - 1);
        }
        else{
            s = str[i];
        }
        string s1 = "";
        a = i - 1;
        b = i;
        if(str[a] == str[b]){
            while(a >= 0 && b < str.length()){
                if(str[a] != str[b]){
                    break;
                }
                a--;
                b++;
            }
            s1 = str.substr(a + 1, b - a - 1 );
        }
        else{
            s1 = str[i];
        }
        string temp = s.length() > s1.length() ? s : s1;
        result = result.length() > temp.length() ? result: temp;
    }
  return result;
}

int main(int argc, const char * argv[]) {
    string s = "abaxyzzyxf";
    cout << longestPalindromicSubstring(s);
    return 0;
}
