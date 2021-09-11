#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, cmax = -INF;
	cin >> N >> K;
	vi extra(K+1);
	for (int i=1; i<=K; i++) cin >> extra[i];
	vector<vi> grid(N, vi(N));
	for (int i=0; i<N; i++) {
		for (int j=0; j<=i; j++) {
			cin >> grid[i][j];
		}
	}
	
	vector< vector<vi> > dp(2, vector<vi>(N, vi(K+1, -INF)));
	dp[0][0][0] = grid[0][0];
	for (int i=1; i<=K; i++) dp[0][0][i] = max(dp[0][0][i-1], extra[i]);
	for (int i=0; i<N-1; i++) {
		for (int j=0; j<=i; j++) {
			for (int k=0; k<=K; k++) {
				dp[(i+1)%2][j][k] = max(dp[(i+1)%2][j][k], dp[i%2][j][k]+grid[i+1][j]);
				dp[(i+1)%2][j+1][k] = max(dp[(i+1)%2][j+1][k], dp[i%2][j][k]+grid[i+1][j+1]);
				if (k < K) {
					dp[(i+1)%2][j][k+1] = max({dp[(i+1)%2][j][k+1], dp[i%2][j][k]+extra[k+1], dp[(i+1)%2][j][k]});
					dp[(i+1)%2][j+1][k+1] = max({dp[(i+1)%2][j+1][k+1], dp[i%2][j][k]+extra[k+1], dp[(i+1)%2][j+1][k]});
				}
			}
		}
		dp[i%2].assign(N, vi(K+1, -INF));
	}
	
	for (int i=0; i<N; i++) {
		cmax = max(cmax, dp[(N-1)%2][i][K]);
	}
	cout << cmax << "\n";
	
	return 0;
}