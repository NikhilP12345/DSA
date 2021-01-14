#include<bits/stdc++.h>
using namespace std;

void unions(vector<int> v1, vector<int> v2){
    int i = 0;
    int j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            cout << v1[i++] << " ";
        }
        else if(v1[i] > v2[j]){
            cout << v2[j++] << " ";
        }
        else{
            cout << v1[i++]  << " ";
            j++;
        }
    }
}

void intersection(vector<int> v1, vector<int> v2){
    int i = 0;
    int j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            i++;
        }
        else if(v1[i] > v2[j]){
            j++;
        }
        else{
            cout << v1[i++] << " ";
            j++;
        }
    }


}


int main(){
    vector<int> v1 = {1, 3, 4, 5, 7};
    vector<int> v2 = {2, 3, 5, 6};
    unions(v1, v2);
    cout << endl;
    intersection(v1, v2);
}