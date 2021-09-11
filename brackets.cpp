#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	
	string x;
	getline(cin, x);
	
	stack<char> s;
	
	for (auto i : x) {
		if (i == '(' || i == '[' || i == '{') {
			s.push(i);
		} else if (i == ')') {
			if (s.top() != '(') {
				cout << "NO" << endl;
				return 0;
			}
			s.pop();
		} else if (i == ']') {
			if (s.top() != '[') {
				cout << "NO" << endl;
				return 0;
			}
			s.pop();
		} else if (i == '}') {
			if (s.top() != '{') {
				cout << "NO" << endl;
				return 0;
			}
			s.pop();
		}
	}
	
	if (s.empty()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}