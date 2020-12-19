#include<bits/stdc++.h>
using namespace std;

bool equalSum(vector<int> v, int sum, int n){
    if(n == 0 &&  sum > 0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(v[n - 1] > sum){
        return equalSum(v, sum, n - 1);
    }
    else{
        return equalSum(v, sum, n - 1) || equalSum(v, sum - v[n - 1], n - 1);
    }
}

int main(){
    vector<int> v = { 1,  5, 11, 5};
    int sum = 0;
    for(auto i: v){
        sum += i;
    }
    if(sum % 2 != 0){
        cout << "Cant";
    }
    else{
        cout << equalSum(v, sum / 2, v.size());
    }
}