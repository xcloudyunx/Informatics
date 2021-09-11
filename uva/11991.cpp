#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000;

int main() {
	int n, m, x, k, v;
	
	while (cin >> n >> m) {
		vector<vi> adj(1000000);
		for (int i=1; i<=n; i++) {
			cin >> x;
			adj[x].push_back(i);
		}
		
		while (m--) {
			cin >> k >> v;
			if (adj[v].size() >= k) cout << adj[v][k-1] << "\n";
			else cout << 0 << "\n";
		}
	}
	
	return 0;
}