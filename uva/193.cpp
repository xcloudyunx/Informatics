#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int n, mblack;
vi output;

void backtrack(int num, int black, bitset<101> used, vi current, vector<vi> &adj) {
	if (num == n) {
		if (black > mblack) { mblack = black; output = current; }
	}
	else {
		for (int i=1; i<=n; i++) {
			if (!used[i]) {
				used[i] = true;
				queue<int> q;
				for (auto j : adj[i]) {
					if (!used[j]) { used[j] = true; q.push(j); }
				}
				current.push_back(i);
				backtrack(num+q.size()+1, black+1, used, current, adj);
				current.pop_back();
				while (!q.empty()) {
					used[q.front()] = false;
					q.pop();
				}
				used[i] = false;
			}
		}
	}
}

int main() {
	int m, k, a, b;
	cin >> m;
	while (m--) {
		cin >> n >> k;
		vector<vi> adj(n+1);
		while (k--) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		mblack = 0;
		output.clear();
		backtrack(0, 0, bitset<101>(), {}, adj);
		cout << mblack << "\n";
		for (int i=0; i<mblack; i++) {
			if (i) cout << " ";
			cout << output[i];
		}
		cout << "\n";
	}
	
	return 0;
}