#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

int minDif = INT_MAX;
vector<int> v1 = {};
vector<int> v2 = {};
void util(int n, vector<int> v, int current, vector<int> set1,
	vector<int> set2, int sum1, int sum2) {
	if (current == n) {
		if (abs(sum1 - sum2) < minDif) {
			v1 = {};
			v2 = {};
			minDif = abs(sum1 - sum2);
			for (auto i : set1) {
				v1.push_back(i);
			}
			for (auto i : set2) {
				v2.push_back(i);
			}
		}
		return;
	}
	if (set1.size() < n / 2 + 1) {
		set1.push_back(v[current]);
		util(n, v, current + 1, set1, set2, sum1 + v[current], sum2);
		set1.pop_back();
	}
	if (set2.size() < n / 2 + 1) {
		set2.push_back(v[current]);
		util(n, v, current + 1, set1, set2, sum1, sum2 + v[current]);
		set2.pop_back();
	}

}

void tow(vector<int> v) {
	vector<int> set1 = {};
	vector<int> set2 = {};

	util(v.size(), v, 0, set1, set2, 0, 0);
	for (auto i : v1) {
		cout << i << " ";
	}
	cout << "\n";
	for (auto i : v2) {
		cout << i << " ";
	}
}


int main() {
	vector<int> v = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	tow(v);
}