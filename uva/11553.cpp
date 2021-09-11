#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int t, n, score, cmax;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vi> grid(n, vi(n));
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> grid[i][j];
			}
		}
		vi order(n);
		iota(order.begin(), order.end(), 0);
		
		cmax = INF;
		do {
			score = 0;
			for (int i=0; i<n; i++) {
				score += grid[i][order[i]];
			}
			cmax = min(cmax, score);
		} while(next_permutation(order.begin(), order.end()));
		
		cout << cmax << "\n";
	}
	
	return 0;
}