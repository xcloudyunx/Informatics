#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int maxj = 19;
vector<vii> parents(200001, vii(maxj, {-1, -1}));
vi depth(200001, -1);

ii jump(int a, int k) {
	int j = maxj;
	int d = -1;
	while (k > 0) {
		if ((1<<j) <= k) {
			if (d == -1) d = parents[a][j].second;
			else d ^= parents[a][j].second;
			a = parents[a][j].first;
			k = k-(1<<j);
		}
		j--;
	}
	return {a, d};
}

int LCA(int a, int b) {
	if (a == b) return -1;
	if (depth[a] > depth[b]) swap(a, b);
	auto tmp = jump(b, depth[b]-depth[a]);
	b = tmp.first;
	int d = tmp.second;
	if (a == b) return d;
	for (int j=maxj; j>=0; j--) {
		if (parents[a][j].first != parents[b][j].first) {
			if (d == -1) d = parents[a][j].second^parents[b][j].second;
			else d ^= parents[a][j].second^parents[b][j].second;
			a = parents[a][j].first;
			b = parents[b][j].first;
		}
	}
	if (d == -1) d = parents[a][0].second^parents[b][0].second;
	else d^= parents[a][0].second^parents[b][0].second;
	return d;
}

int main() {
	int Q, a, b, n, d, cmax;
	string c;
	cin >> Q;
	depth[1] = 0;
	vector<vi> adj(200001);
	queue<int> q;
	
	n = 2;
	while (Q--) {
		cin >> c >> a >> b;
		if (c == "Add") {
			adj[a].push_back(n);
			parents[n][0] = {a, b};
			for (int i=1; i<maxj && parents[parents[n][i-1].first][i-1].first != -1; i++) {
				parents[n][i] = {parents[parents[n][i-1].first][i-1].first, parents[parents[n][i-1].first][i-1].second^parents[n][i-1].second};
			}
			depth[n++] = depth[a]+1;
		} else {
			d = LCA(a, b);
			cmax = d;
			q.push(b);
			while (!q.empty()) {
				int f = q.front();
				q.pop();
				if (d == -1) cmax = max(cmax, LCA(b, f));
				else cmax = max(d, d^LCA(b, f));
				for (auto i : adj[f]) q.push(i);
			}
			cout << cmax << "\n";
		}
	}
	
	return 0;
}