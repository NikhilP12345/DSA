#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
    // vector<int> visited(v.size(), INT_MAX);
    // visited[0] = 0;
    // for(int i = 1 ; i < v.size() ; i++){
    //     for(int j = 0 ; j < i ; j++){
    //         if(v[j] + j >= i){
    //             visited[i] = min(visited[i], visited[j] + 1);
    //         }
    //     }
    // }
    // cout << visited[v.size() - 1];
    int maxR = v[0];
    int steps = v[0];
    int jumps = 0;
    for(int i = 1 ; i < v.size() - 1 ; i++){
        maxR = max(maxR, v[i] + i);
        steps--;
        if(steps == 0){
            steps = maxR - i;
            ++jumps;
        }
    }
    cout << jumps + 1;
}