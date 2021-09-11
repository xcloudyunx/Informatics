#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string x;
	cin >> x;
	
	for (int i=0; i<N; i++) {
		stack<char> left;
		queue<char> right;
		for (int j=0; j<N; j++) {
			if (j < i) {
				left.push(x.at(j));
			} else if (j > i) {
				right.push(x.at(j));
			}
		}
		int b = 1;
		int total = 1;
		char c = x.at(i);
		while (true) {
			if (c == 'L' && !left.empty()) {
				c = left.top();
				left.pop();
				b++;
				if (c == 'L') {
					total++;
				} else {
					total += b;
				}
			} else if (c == 'R' && !right.empty()) {
				c = right.front();
				right.pop();
				b++;
				if (c == 'R') {
					total++;
				} else {
					total += b;
				}
			} else {
				break;
			}
		}
		cout << total << "\n";
	}
	
	return 0;
}