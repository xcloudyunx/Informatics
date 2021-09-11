#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, cmax = 0;
	cin >> n;
	vector<vi> H(n, vi(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) cin >> H[i][j];
	}
	
	vector<vi> dp(n, vi((1<<n), 0));
	
	for (int j=(1<<n)-2; j>0; j--) {
		for (int i=0; i<n; i++) {
			if (j & (1<<i)) continue;
			for (int k=0; k<n; k++) {
				if (j & (1<<k)) {
					dp[k][j^(1<<k)] = max(dp[k][j^(1<<k)], dp[i][j]+H[i][k]);
				}
			}
		}
	}
	
	for (int i=0; i<n; i++) cmax = max(cmax, dp[i][0]);
	cout << cmax << "\n";
	
	return 0;
}