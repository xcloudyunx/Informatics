#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, N, M, K, S;
	ll P, x;
	cin >> T;
	for (int TC=1; TC<=T; TC++) {
		cin >> N >> M >> K;
		vector< vector<ll> > grid(N, vector<ll>(M));
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> grid[i][j];
				if (i) grid[i][j] += grid[i-1][j];
				if (j) grid[i][j] += grid[i][j-1];
				if (i && j) grid[i][j] -= grid[i-1][j-1];
			}
		}
		P = -LLONG_MAX;
		S = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				for (int k=i; k<N; k++) {
					for (int l=j; l<M; l++) {
						if ((k-i+1)*(l-j+1) < S) continue;
						x = grid[k][l];
						if (i) x -= grid[i-1][l];
						if (j) x -= grid[k][j-1];
						if (i && j) x += grid[i-1][j-1];
						if (x > K) break;
						if ((k-i+1)*(l-j+1) > S) { P = x; S = (k-i+1)*(l-j+1); }
						else P = min(P, x);
					}
				}
			}
		}
		cout << "Case #" << TC << ": " << S << " " << ((S == 0) ? 0 : P) << "\n";
	}
	
	return 0;
}