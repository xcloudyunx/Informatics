#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
	int N, A, B, C1, C2, cost = 0;
	cin >> N;
	
	vector<vii> adj(N+1);
	vii costs(N-1);
	vi num(N-1, 0);
	
	for (int i=0; i<N-1; i++) {
		cin >> A >> B >> C1 >> C2;
		adj[A].push_back({B, i});
		adj[B].push_back({A, i});
		costs[i] = {C1, C2};
	}
	
	for (int start=1; start<N; start++) {
		queue<int> q;
		vii v(N+1, {-2, -2});
		v[start] = {-1, -1};
		q.push(start);
		bool broken = false;
		
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			
			for (auto i : adj[f]) {
				if (v[i.first].first == -2) {
					q.push(i.first);
					v[i.first] = {f, i.second};
					if (i.first == start+1) {
						broken = true;
						break;
					}
				}
			}
			if (broken) break;
		}
		
		int f = start+1;
		while (v[f].first != -1) {
			num[v[f].second] += 1;
			f = v[f].first;
		}
		
	}
	
	for (int i=0; i<N-1; i++) {
		if (costs[i].first < costs[i].second/(float)num[i]) cost += num[i]*costs[i].first;
		else cost += costs[i].second;
	}
	
	cout << cost << "\n";
	
	return 0;
}