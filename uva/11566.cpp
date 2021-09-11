#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, x, T, K, val, budget;
	cin >> N >> x >> T >> K;
	while (N || x || T || K) {
		budget = (x*(N+1))/1.1f - T*(N+1);
		vii dim(K);
		for (int i=0; i<K; i++) {
			cin >> dim[i].first;
			dim[i].second = 0;
			for (int j=0; j<=N; j++) {
				cin >> val;
				dim[i].second += val;
			}
		}
		
		vector< vector<vi> > dp(2*K+1, vector<vi>(2*(N+1)+1, vi(budget+1, 0)));
		
		for (int i=1; i<=2*K; i++) {
			for (int j=1; j<=2*(N+1); j++) {
				for (int k=1; k<=budget; k++) {
					dp[i][j][k] = dp[i-1][j][k];
					if (k-dim[(int)ceil(i/2.0)-1].first >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-dim[(int)ceil(i/2.0)-1].first]+dim[(int)ceil(i/2.0)-1].second);
				}
			}
		}
		printf("%.2f\n", dp[2*K][2*(N+1)][budget]/(float)(N+1));
		
		cin >> N >> x >> T >> K;
	}
	
	return 0;
}