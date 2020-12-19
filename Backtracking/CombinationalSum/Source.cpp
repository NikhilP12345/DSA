#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;


void cSum(vector<int> v, int sum, int n, vector<int> &r, vector<vector<int>> &final) {
	if (sum < 0) {
		return;
	}
	if (sum == 0) {
		final.push_back(r);
		return;
	}
	while (n < v.size() && sum - v[n] >= 0) {
		r.push_back(v[n]);
		cSum(v, sum - v[n], n, r, final);
		n++;
		r.pop_back();
	}
}

int main() {
	vector<int> v = { 7,2,6,5 };
	int B = 16;
	vector<int> r = {};
	vector<vector<int>> final = {};
	//sort(v.begin(), v.end());
	//cSum(v, B, 0, r, final);
	//for (auto i : final) {
	//	for (auto j : i) {
	//		cout << j << " ";
	//	}
	//	cout << "\n";
	//}
	vector<int> temp(v.begin(), v.end());
	sort(temp.begin(), temp.end());
}