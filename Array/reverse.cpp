#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3};
    int i = 0;
    int j = v.size() - 1;
    while(i < j){
        swap(v[i], v[j]);
        i++;
        j--;
    }
    for(auto i: v){
        cout << i << " ";
    }
}