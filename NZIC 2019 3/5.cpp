#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, P, S, E;
	cin >> N >> P >> S >> E;
	
	vector< vector<int> > adj(N);
	vector<int> distance(N, INT_MAX);
	
	for (int i=0; i<P; i++) {
		int a, b;
		cin >> a >> b;
		adj.at(a).push_back(b);
		adj.at(b).push_back(a);
	}
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	q.push(make_pair(0, S));
	distance.at(S) = 0;
	
	while (!q.empty()) {
		int w = q.top().first+1;
		int f = q.top().second;
		q.pop();
		
		for (auto i : adj.at(f)) {
			if (distance.at(i) > w) {
				distance.at(i) = w;
				q.push(make_pair(w, i));
			}
		}
	}
	
	cout << distance.at(E);
	
	return 0;
}