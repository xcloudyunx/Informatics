#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, P, n;
	cin >> T;
	while (T--) {
		cin >> P >> n;
		vi money(n);
		for (int i=0; i<n; i++) cin >> money[i];
		vector<vi> dp(n+1, vi(20001, INF));
		dp[0][0] = 0;
		
		for (int i=1; i<=n; i++) {
			dp[i][0] = 0;
			for (int j=0; j<=20000; j++) {
				dp[i][j] = min(dp[i][j], dp[i-1][j]);
				if (j >= money[i-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-money[i-1]]+1);
			}
		}
		for (int i=P; i<=20000; i++) {
			if (dp[n][i] != INF) {
				cout << i << " " << dp[n][i] << "\n";
				break;
			}
		}
	}
	
	return 0;
}