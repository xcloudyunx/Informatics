#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;

int main() {
	ll N, K;
	cin >> N >> K;
	
	vector<vll> grid(N, vll(N));		//from i goes to [i][j]
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) cin >> grid[i][j];
	}
	
	if (K == 1) {
		cout << 1 << "\n";
		return 0;
	} else if (K == 2) {
		cout << 2 << "\n";
		return 0;
	}
	
	vector<vll> cycle(N, vll(N, 0));
	ll prev = 1, curr = 2, tmp, c;
	for (c=1; !cycle[curr-1][prev-1]; c++) {
		cycle[curr-1][prev-1] = c;
		tmp = prev;
		prev = curr;
		curr = grid[curr-1][tmp-1];
		if (c+2 == K) {
			cout << curr << "\n";
			return 0;
		}
	}
	
	ll cyclesize = c-cycle[curr-1][prev-1];
	ll val = (K-cycle[curr-1][prev-1]-1+cyclesize)%cyclesize;
	if (val == 0) val = cyclesize;
	val += cycle[curr-1][prev-1]-1;
	
	/*cout << c << " " << cycle[curr-1][prev-1] << " " << cyclesize << " " << val << endl;
	for (auto i : cycle) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}*/
	
	prev = 1;
	curr = 2;
	while (cycle[curr-1][prev-1] != val) {
		tmp = prev;
		prev = curr;
		curr = grid[curr-1][tmp-1];
	}
	
	cout << grid[curr-1][prev-1] << "\n";
	
	return 0;
}