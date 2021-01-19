#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int i = 0;
    int j = 1;
    while(j < v.size()){
        if(v[i] > 0 && v[j] < 0){
            swap(v[i], v[j]);
            i++;
        }
        else if(v[i] < 0){
            i++;
        }
        j++;

    }
    for(auto i: v){
        cout << i << " ";
    }
}