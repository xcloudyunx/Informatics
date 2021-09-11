#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;
typedef vector<ll> vll;
typedef vector<llll> vllll;
#define INF LLONG_MAX

int main() {
	ll V, H, C, S, w, f;
	cin >> V >> H;
	vector<vllll> adj(V+H+1);
	for (int i=1; i<=H; i++) {
		cin >> C >> S;
		for (int j=0; j<S; j++) {
			cin >> f;
			adj[f].push_back({C, V+i});
			adj[V+i].push_back({0, f});
		}
	}
	
	vll d(V+H+1, INF);
	priority_queue<llll, vllll, greater<llll> > q;
	q.push({0, 1});
	
	while (!q.empty()) {
		w = q.top().first;
		f = q.top().second;
		q.pop();
		
		for (auto i : adj[f]) {
			C = w + i.first;
			if (C < d[i.second]) {
				d[i.second] = C;
				q.push({C, i.second});
			}
		}
	}
	
	cout << d[V] << "\n";
	
	return 0;
}