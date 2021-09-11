#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, S, F, P, W, A, B, T;;
	cin >> N >> S >> F >> P;
	S--;
	F--;
	
	vector< vector< pair<int, int> > > adj(N);
	vector< vector<int> > worm(N);
	vector<int> d(N, INT_MAX);
	
	for (int i=0; i<P; i++) {
		cin >> A >> B >> T;
		A--;
		B--;
		adj[A].push_back(make_pair(T, B));
	}
	
	cin >> W;
	
	for (int i=0; i<W; i++) {
		cin >> A >> B;
		A--;
		B--;
		worm[A].push_back(B);
	}
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	q.push(make_pair(0, S));
	d[S] = 0;
	
	while (!q.empty()) {
		int w = q.top().first;
		int f = q.top().second;
		q.pop();
		
		if (w <= d[f]) {
			for (auto i : adj[f]) {
				int x = i.first+w;
				if (x < d[i.second]) {
					d[i.second] = x;
					q.push(make_pair(x, i.second));
				}
			}
			
			for (auto i : worm[f]) {
				int x = w/2;
				if (x < d[i]) {
					d[i] = x;
					q.push(make_pair(x, i));
				}
			}
		}
	}
	
	cout << d[F] << endl;
	
	return 0;
}