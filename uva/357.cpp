#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int x;
	vector<vi> dp(30001, vi(30001, INF));
	vi dp2(30001, 0);
	dp[1][1] = 1;
	dp[1][5] = 1;
	dp[1][10] = 1;
	dp[1][25] = 1;
	dp[1][50] = 1;
	dp2[1] = 1;
	dp2[5] = 1;
	dp2[10] = 1;
	dp2[25] = 1;
	dp2[50] = 1;
	for (int i=2; i<=30000; i++) {
		for (int j=2; j<=30000; j++) {
			dp[i][j] = dp[i-1][j-1];
			if (j > 5) dp[i][j] = min(dp[i][j], dp[i-1][j-5]);
			if (j > 10) dp[i][j] = min(dp[i][j], dp[i-1][j-10]);
			if (j > 25) dp[i][j] = min(dp[i][j], dp[i-1][j-25]);
			if (j > 50) dp[i][j] = min(dp[i][j], dp[i-1][j-50]);
			if (dp[i][j] != INF) dp2[j]++;
		}
	}
	
	while (cin >> x) {
		if (dp2[x] > 1) cout << "There are " << dp2[x] << " ways to produce " << x << " cents change.\n";
		else cout << "There is only 1 way to produce " << x << " cents change.\n";
	}
	
	return 0;
}
