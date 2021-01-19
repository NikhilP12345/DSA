#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v = {0, 1, 2, 0, 1, 2};
    int low = 0;
    int high = v.size() - 1;
    int mid = 0;
    while(mid <= high){
        switch(v[mid]){
            case 0:
                swap(v[low++], v[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(v[mid], v[high--]);
                break;
        }
    }
    // int o = 0, z = 0, t = 0;
    // for(int i = 0 ; i < v.size() ; i++){
    //     if(v[i] == 0){
    //         z++;
    //     }
    //     else if(v[i] == 1){
    //         o++;
    //     }
    //     else{
    //         t++;
    //     }
    // }
    // int i = 0;
    // while(i < z){
    //     v[i] = 0;
    //     i++;
    // }
    // while(i < o + z){
    //     v[i] = 1;
    //     i++;
    // }
    // while(i < t + o + z){
    //     v[i] = 2;
    //     i++;
    // }
    for(auto i: v){
        cout << i << " ";
    }
}