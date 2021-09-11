#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000;

int main() {
	int m, n, r, x;
	while (cin >> m >> n) {
		vector<vii> adj(n+1);
		for (int i=1; i<=m; i++) {
			cin >> r;
			vector<int> y(r);
			for (int j=0; j<r; j++) {
				cin >> y[j];
			}
			for (int j=0; j<r; j++) {
				cin >> x;
				adj[y[j]].push_back({i, x});
			}
		}
		cout << n << " " << m << "\n";
		for (int i=1; i<=n; i++) {
			cout << adj[i].size();
			for (auto j : adj[i]) {
				cout << " " << j.first;
			}
			cout << "\n";
			for (int j=0; j<adj[i].size(); j++) {
				if (j) cout << " ";
				cout << adj[i][j].second;
			}
			cout << "\n";
		}
	}
	
	return 0;
}