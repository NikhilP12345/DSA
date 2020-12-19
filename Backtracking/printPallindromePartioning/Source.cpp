#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long
using namespace std;

bool isPallindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

void util(vector<vector<string>>& v, vector<string> &cr, int n, string str, int start) {
	if (start >= n) {
		v.push_back(cr);
		return;
	}
	for (int i = start; i < n; i++) {
		if (isPallindrome(str, start, i)) {
			cr.push_back(str.substr(start, i - start + 1));
			util(v, cr, n, str, i + 1);
			cr.pop_back();
		}
	}
}

//void util(vector<vector<string>>& v, vector<string>& cr, int n, string str) {
//	for (int i = 1; i <= n; i++) {
//		string temp = str.substr(0, i);
//		if (isPallindrome(temp, 0, temp.size() - 1)) {
//			if (i >= n) {
//				cr.push_back(temp);
//				v.push_back(cr);
//				cr.pop_back();
//				return;
//			}
//			cr.push_back(temp);
//			util(v, cr, n - i, str.substr(i, n - i));
//			cr.pop_back();
//		}
//	}
//}

void palPart(string str) {
	int n = str.length();
	vector<vector<string>> v;
	vector<string> cr;
	util(v, cr, n, str, 0);

	for (auto i : v) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}


int main() {
	string str = "nitin";
	palPart(str);
}
