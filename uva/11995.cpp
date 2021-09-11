#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, c, x;
	bool S, Q, PQ;
	
	while (cin >> n) {
		S = true;
		Q = true;
		PQ = true;
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		
		while (n--) {
			cin >> c >> x;
			if (c == 1) {
				if (S) s.push(x);
				if (Q) q.push(x);
				if (PQ) pq.push(x);
			} else {
				if (S && s.empty()) S = false;
				else if (S && s.top() != x) S = false;
				else if (S) s.pop();
				if (Q && q.empty()) Q = false;
				else if (Q && q.front() != x) Q = false;
				else if (Q) q.pop();
				if (PQ && pq.empty()) PQ = false;
				else if (PQ && pq.top() != x) PQ = false;
				else if (PQ) pq.pop();
			}
		}
		
		if ((S && (Q || PQ)) || ((S||Q) && PQ) || (Q && (S||PQ))) cout << "not sure\n";
		else if (S) cout << "stack\n";
		else if (Q) cout << "queue\n";
		else if (PQ) cout << "priority queue\n";
		else cout << "impossible\n";
	}
	
	return 0;
}