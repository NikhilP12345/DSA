#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,-2,5};
    int maxEl = INT_MIN;
    int sum = 0;
    for(int i = 0 ; i < v.size() ; i++){
        sum = max(sum + v[i], v[i]);
        maxEl = max(maxEl, sum);
    }
    cout << maxEl;
}