#include<bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int> l, vector<int> r){
    vector<int> sortedList(l.size() + r.size(), 0);
    int i = 0, j = 0, k = 0;
    while(i < l.size() && j < r.size()){
        if(l[i] <= r[j]){
            sortedList[k++] = l[i++];
        }
        else{
            sortedList[k++] = r[j++];
        }
    }
    while(i < l.size()){
        sortedList[k++] = l[i++];
    }
    while(j < r.size()){
        sortedList[k++] = r[j++];
    }
    return sortedList;
}


vector<int> mergesort(vector<int> v){
    if(v.size() <= 1){
        return v;
    }
    int mid = v.size() / 2;
    vector<int> l(v.begin(), v.begin() + mid);
    vector<int> r(v.begin() + mid, v.end());

    return helper(mergesort(l), mergesort(r));
}

int main(){
    vector<int> v = {8, 5, 2, 9, 5, 6, 3};
    v = mergesort(v);
    for(auto i: v){
        cout << i << " ";
    }
}