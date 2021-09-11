#include <bits/stdc++.h>

using namespace std;

int main() {
	stack<int> s;
	
	char input;
	
	while (cin >> input) {
		if (isdigit(input)) {
			s.push(input-'0');
		} else {
			int first = s.top();
			s.pop();
			int second = s.top();
			s.pop();
			if (input == '+') {
				s.push(first+second);
			} else if (input == '-') {
				s.push(second-first);
			} else if (input == '*') {
				s.push(first*second);
			}
		}
	}
	
	cout << s.top() << endl;
	
	return 0;
}