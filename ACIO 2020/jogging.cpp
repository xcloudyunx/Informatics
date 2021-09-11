#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, M, u, v, w;
	ll x;
	cin >> N >> M;
	vector<vii> adj(N); //weight, dest
	while (M--) {
		cin >> u >> v >> w;
		adj[u-1].push_back({w, v-1});
	}
	
	vector<ll> d(N, LLONG_MAX);
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > q;
	q.push({0, 0});
	while (!q.empty()) {
		u = q.top().second;
		w = q.top().first;
		q.pop();
		for (auto i : adj[u]) {
			x = w+i.first;
			if (x < d[i.second]) {
				d[i.second] = x;
				q.push({x, i.second});
			}
		}
	}
	
	for (int i=1; i<N; i++) {
		if (d[i] != LLONG_MAX) cout << 2*d[i] << "\n";
		else cout << -1 << "\n";
	}
	
	return 0;
}