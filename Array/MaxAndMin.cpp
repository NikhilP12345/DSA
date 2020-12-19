#include<bits/stdc++.h>
using namespace std;

vector<int> a = {INT_MIN, INT_MAX};

vector<int> MaxMin(vector<int> v, int high, int low){
    if(low == high){
        a[0] = v[low];
        a[1] = v[high];
        return a;
    }
    else if(high == low + 1){
        if(v[low] > v[high]){
            a[0] = v[low];
            a[1] = v[high];
        }
        else{
            a[0] = v[high];
            a[1] = v[low];
        }
        return a;
    }
    int mid = low + (high - low) / 2;
    vector<int> left = MaxMin(v, low, mid);
    vector<int> right = MaxMin(v, mid + 1, high);
    

}


int main(){
    vector<int> v = { 1000, 11, 445,
                  1, 330, 3000 };

}