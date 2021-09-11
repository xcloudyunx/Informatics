#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, A, B, C;
	ll cmax, x;
	cin >> T;
	while (T--) {
		cin >> A >> B >> C;
		vector< vector< vector<ll> > > grid(A, vector< vector<ll> >(B, vector<ll>(C)));
		for (int i=0; i<A; i++) {
			for (int j=0; j<B; j++) {
				for (int k=0; k<C; k++) {
					cin >> grid[i][j][k];
					if (j > 0) grid[i][j][k] += grid[i][j-1][k];
					if (k > 0) grid[i][j][k] += grid[i][j][k-1];
					if (j > 0 && k > 0) grid[i][j][k] -= grid[i][j-1][k-1];
				}
			}
		}
		cmax = -LLONG_MAX;
		for (int i=0; i<B; i++) {
			for (int j=0; j<C; j++) {
				for (int k=i; k<B; k++) {
					for (int l=j; l<C; l++) {
						x = 0;
						for (int r=0; r<A; r++) {
							x += grid[r][k][l];
							if (i > 0) x -= grid[r][i-1][l];
							if (j > 0) x -= grid[r][k][j-1];
							if (i > 0 && j > 0) x += grid[r][i-1][j-1];
							cmax = max(cmax, x);
							if (x < 0) x = 0;
						}
					}
				}
			}
		}
		
		cout << cmax << "\n";
		if (T) cout << "\n";
	}
	
	return 0;
}