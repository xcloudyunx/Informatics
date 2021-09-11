#include <bits/stdc++.h>

using namespace std;

int main() {
	int SET, N, S, Q, x, time;
	string a;
	cin >> SET;
	
	while (SET--) {
		cin >> N >> S >> Q;
		vector< queue<int> > q(N);
		for (int i=0; i<N; i++) {
			cin >> time;
			while (time--) {
				cin >> x;
				q.at(i).push(x-1);
			}
		}
		
		time = 0;
		x = 0;
		set<int> test;
		for (int i=0; i<N; i++) {
			test.insert(i);
		}
		stack<int> s;
		while (true) {
			while (!s.empty()) {
				if (s.top() == x) {
					s.pop();
					time++;
				} else if (q.at(x).size() < Q) {
					q.at(x).push(s.top());
					s.pop();
					time++;
				} else {
					break;
				}
			}
			while (s.size() < S && !q.at(x).empty()) {
				s.push(q.at(x).front());
				q.at(x).pop();
				time++;
			}
			if (q.at(x).empty()) {
				test.erase(x);
				if (test.empty() && s.empty()) {
					cout << time << "\n";
					break;
				}
			}
			
			x = (x+1)%N;
			time += 2;
		}
	}
	
	return 0;
}