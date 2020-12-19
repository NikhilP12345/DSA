#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define ll long long
using namespace std;

void wordbreak(unordered_set<string> s, string str, int n, string res) {
	for (int i = 1; i <= n; i++) {
		string prefix = str.substr(0, i);
		if (s.find(prefix) != s.end()) {
			if (i == n) {
				res += prefix;
				cout << res << endl;
				return;
			}
			wordbreak(s, str.substr(i, n - i), n - i, res + prefix + " ");
		}
	}
}

int main() {
	unordered_set<string> s = { "i", "love", "sam", "sung", "samsung" };

	string str = "ilovesamsung";
	wordbreak(s, str, str.length(), "");
}
