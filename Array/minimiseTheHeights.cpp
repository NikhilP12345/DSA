#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,5,8,10};
    int k = 2;
    vector<pair<int, int>> p;
    vector<int> visited(v.size());
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] - k >= 0){
            p.push_back({v[i] - k, i});
        }
        p.push_back({v[i] + k, i});
    }
    sort(p.begin(), p.end());
    int el = 0;
    int l = 0;
    int r = 0;

    while(el < v.size() && r < p.size()){
        if(visited[p[r].second] == 0){
            el++;
        }
        visited[p[r].second]++;
        r++;
    }
    int ans = p[r - 1].first - p[l].first;
    while(r < p.size()){
        if(visited[p[l].second] == 1){
            el--;
        }
        visited[p[l].second]--;
        l++;
        while(el < v.size() && r < p.size()){
            if(visited[p[r].second] == 0){
                el++;
            }
            visited[p[r].second]++;
            r++;
        }
        if(el == v.size()){
            ans = min(ans, p[r - 1].first - p[l].first);
        }
        else{
            break;
        }
    }
    cout << ans;
}