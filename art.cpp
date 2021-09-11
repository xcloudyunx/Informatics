#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int H, W;
	ll maxval = 0, cmax;
	cin >> H >> W;
	
	vector<vi> grid(H, vi(W));
	for (int i=H-1; i>=0; i--) {
		for (int j=0; j<W; j++) cin >> grid[i][j];
	}
	
	vector< vector< pair<ll, ll> > > dp(H, vector< pair<ll, ll> >(W));
	
	for (int j=0; j<W; j++) {
		dp[0][j] = {grid[0][j], grid[0][j]};
		for (int i=1; i<H; i++) {
			dp[i][j].first = dp[i-1][j].first+grid[i][j];
			dp[i][j].second = dp[i][j].first;
		}
		
		if (j) {
			cmax = LLONG_MIN;
			for (int i=0; i<H; i++) {
				cmax = max(cmax, dp[i][j-1].first);
				dp[i][j].first = max(dp[i][j].first, dp[i][j].first+cmax);
				maxval = max(maxval, dp[i][j].first);
			}
			cmax = LLONG_MIN;
			for (int i=H-1; i>=0; i--) {
				cmax = max(cmax, dp[i][j-1].second);
				dp[i][j].second = max({dp[i][j].second, dp[i][j].first, dp[i][j].second+cmax});
				maxval = max(maxval, dp[i][j].second);
			}
		} else {
			for (int i=0; i<H; i++) maxval = max(maxval, dp[i][j].first);
		}
	}
	
	cout << maxval << "\n";
	
	return 0;
}