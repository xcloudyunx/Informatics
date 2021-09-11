#include <bits/stdc++.h>

using namespace std;

int main() {
	int Q, P, K, T;
	string s;
	priority_queue< pair< pair<int, int>, int>, vector< pair< pair<int, int>, int> >, greater< pair< pair<int, int>, int> > > q;
	
	getline(cin, s);
	while (s != "#") {
		sscanf(s.c_str(), "Register %d %d", &Q, &P);
		q.push(make_pair(make_pair(P, Q), P));
		
		getline(cin, s);
	}
	
	cin >> K;
	
	while (K--) {
		Q = q.top().first.second;
		T = q.top().first.first;
		P = q.top().second;
		q.pop();
		cout << Q << "\n";
		q.push(make_pair(make_pair(T+P, Q), P));
	}
	
	return 0;
}