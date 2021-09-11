#include <bits/stdc++.h>

using namespace std;

int main() {
	int c, n, t, m, x;
	string s;
	cin >> c;
	
	while (c--) {
		cin >> n >> t >> m;
		queue< pair<int, int> > left;
		queue< pair<int, int> > right;
		vector<int> times(m);
		for (int i=0; i<m; i++) {
			cin >> x >> s;
			if (s == "left") {
				left.push(make_pair(x, i));
			} else {
				right.push(make_pair(x, i));
			}
		}
		s = "left";
		x = 0;
		while (!left.empty() || !right.empty()) {
			m = 0;
			if (s == "left") {
				if (!left.empty()) {
					if (left.front().first <= x) {
						while (!left.empty() && left.front().first <= x && m < n) {
							m++;
							times.at(left.front().second) = x+t;
							left.pop();
						}
						x += t;
						s = "right";
					} else if (right.empty() || left.front().first <= right.front().first) {
						x = left.front().first;
					} else {
						x = max(right.front().first, x)+t;
						s = "right";
					}
				} else {
					x = max(right.front().first, x)+t;
					s = "right";
				}
			} else if (s == "right") {
				if (!right.empty()) {
					if (right.front().first <= x) {
						while (!right.empty() && right.front().first <= x && m < n) {
							m++;
							times.at(right.front().second) = x+t;
							right.pop();
						}
						x += t;
						s = "left";
					} else if (left.empty() || right.front().first <= left.front().first) {
						x = right.front().first;
					} else {
						x = max(left.front().first, x)+t;
						s = "left";
					}
				} else {
					x = max(left.front().first, x)+t;
					s = "left";
				}
			}
		}
		
		for (auto i : times) {
			cout << i << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}