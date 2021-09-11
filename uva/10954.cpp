#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, x, total;
	cin >> N;
	
	while (N) {
		priority_queue<int, vector<int>, greater<int> > q;
		total = 0;
		
		while (N--) {
			cin >> x;
			q.push(x);
		}
		
		while (q.size() != 1) {
			x = q.top();
			q.pop();
			total += x+q.top();
			q.push(x+q.top());
			q.pop();
		}
		
		cout << total << "\n";
		
		cin >> N;
	}
	
	return 0;
}