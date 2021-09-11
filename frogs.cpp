#include <bits/stdc++.h>

using namespace std;

int main() {
	int p, j, sa, sb;
	cin >> p >> j >> sa >> sb;
	sa--;
	sb--;
	
	vector< vector<int> > adj(p);
	
	for (int i=0; i<j; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		p1--;
		p2--;
		adj.at(p1).push_back(p2);
		adj.at(p2).push_back(p1);
	}
	
	vector< pair<int, int> > v(p, make_pair(-1, -1));
	
	queue< pair<int, int> > q;
	q.push(make_pair(sa, 1));
	v.at(sa).first = -2;
	
	while (!q.empty()) {
		int f = q.front().first;
		int parity = q.front().second;
		q.pop();
		
		if (f == sb && parity%2 == 1) {
			cout << parity/2 << endl;
			int mid = sb;
			for (int i=0; i<parity/2; i++) {
				if (i%2 == 0) {
					mid = v.at(mid).first;
				} else if (i%2 == 1) {
					mid = v.at(mid).second;
				}
			}
			cout << mid+1 << endl;
			return 0;
		}
		
		for (auto i : adj.at(f)) {
			if (parity%2 == 0) {
				if (v.at(i).first == -1) {
					v.at(i).first = f;
					q.push(make_pair(i, parity+1));
				}
			} else if (parity%2 == 1) {
				if (v.at(i).second == -1) {
					v.at(i).second = f;
					q.push(make_pair(i, parity+1));
				}
			}
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}