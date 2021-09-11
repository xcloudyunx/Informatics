#include <bits/stdc++.h>

using namespace std;

int main() {
	int c, l, m, x;
	string s;
	cin >> c;
	
	while (c--) {
		cin >> l >> m;
		l *= 100;
		queue<int> left;
		queue<int> right;
		while (m--) {
			cin >> x >> s;
			if (s == "left") {
				left.push(x);
			} else {
				right.push(x);
			}
		}
		s = "left";
		x = 0;
		while (!left.empty() || !right.empty()) {
			m = 0;
			x++;
			if (s == "left") {
				if (!left.empty()) {
					while (!left.empty() && m+left.front() <= l) {
						m += left.front();
						left.pop();
					}
					
				}
				s = "right";
			} else if (s == "right") {
				if (!right.empty()) {
					while (!right.empty() && m+right.front() <= l) {
						m += right.front();
						right.pop();
					}
				}
				s = "left";
			}
		}
		
		cout << x << "\n";
	}
	
	return 0;
}