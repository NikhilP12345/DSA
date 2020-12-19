#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

bool subsetSum(vector<int> v, int sum, int n) {
	if (n == 0 && sum > 0) {
		return false;
	}
	if (sum == 0) {
		return true;
	}
	if (v[n - 1] > sum) {
		return subsetSum(v, sum, n - 1);
	}
	else {
		return subsetSum(v, sum, n - 1) || subsetSum(v, sum - v[n - 1], n - 1);
	}
}

int main() {
	vector<int> v = { 3, 34, 12, 5, 2 };
	int sum = 9;
	if (subsetSum(v, sum, v.size())) {
		cout << "Found";
	}
	else {
		cout << "Not found";
	}
}
