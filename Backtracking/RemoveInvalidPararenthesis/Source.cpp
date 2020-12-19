#include<bits/stdc++.h>
#include<unordered_set>
#define ll long long
using namespace std;
unordered_set<string> sm;
int getMin(string str) {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')') {
			if (s.size() == 0) {
				s.push(')');
				continue;
			}
			char top = s.top();
			if(top == '('){
				s.pop();
			}
			else if (top == ')') {
				s.push(')');
			}
		}
	}
	return s.size();
}

bool isValid(string str) {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if(str[i] == ')') {
			if (s.size() == 0) {
				return false;
			}
			char top = s.top();
			if (top == '(') {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	return true;
}

void solution(string str, int rm) {
	if (rm == 0) {
		if (isValid(str)) {
			sm.insert(str);
		}
		return;
	}
	for (int i = 0; i < str.length(); i++) {
		string left = str.substr(0, i);
		string right = str.substr(i + 1);
		solution(left + right, rm - 1);
	}
}
int main() {
	string str = "x(";
	int noRemove = getMin(str);

	solution(str, noRemove);
	for (auto i : sm) {
		cout << i << "\n";
	}
}