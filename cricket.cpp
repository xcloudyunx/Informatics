#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, M, T, a, b;
	vector<vi> adj(N+1);
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vii team(T);
	for (int i=0; i<T; i++) cin >> team[i].first >> team[i].second;
	
	cout << N << "\n";
	
	return 0;
}