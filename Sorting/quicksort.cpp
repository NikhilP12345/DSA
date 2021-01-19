#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &v, int i, int j){
    if(i >= j){
        return;
    }
    int pivot = i;
    int left = i + 1;
    int right = j;
    while(left <= right){
        if(v[pivot] < v[left] && v[right] < v[pivot]){
            swap(v[left], v[right]);
        }
        if(v[left] <= v[pivot]){
            left++;
        }
        if(v[right] >= v[pivot]){
            right--;
        }
    }
    swap(v[pivot], v[right]);
    quicksort(v, i, right - 1);
    quicksort(v, right + 1, j);
}

int main(){
    vector<int> v = {8, 5, 2, 9, 5, 6, 3};
    quicksort(v, 0, v.size() - 1);
    for(auto i: v){
        cout << i << " ";
    }
}