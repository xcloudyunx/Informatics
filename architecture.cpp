#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, bool, int> s;

int main() {
	int N, a, b;
	cin >> N;
	
	vector< pair<int, int> > west(N);
	priority_queue< s, vector<s>, greater<s> > client;
	vector< vector<int> > table(2, vector<int> (2*N-1));
	
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		west[i] = make_pair(a-1, b-1);
	}
	
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		client.push(make_tuple(a-1, false, i));
		client.push(make_tuple(b-1, true, i));
	}
	
	while (!q.empty()) {
		int x = get<0>(q.top());
		bool end = get<1>(q.top());
		int y = get<2>(q.top());
		
		
	}
	
	return 0;
}