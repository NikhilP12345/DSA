#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

void findMax(string str, int k, string &max) {
	if (k == 0) {
		return;
	}
	int n = str.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] < str[j]) {
				swap(str[i], str[j]);
				if (str.compare(max) > 0) {
					max = str;
				}
				findMax(str, k - 1, max);
				swap(str[i], str[j]);
			}
		}
	}
}


int main() {
	string str = "129814999";
	int k = 4;
	string max = str;
	findMax(str, k, max);
	cout << max;
}