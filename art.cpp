#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int H, W;
	cin >> H >> W;
	vector<vi> grid(H, vi(W));
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) cin >> grid[i][j];
	}
	
	vector<vii> dp(H, vii(W)); // up then down
	vector<vii> cmax(H, vii(W));
	
	for (int j=0; j<W; j++) {
		dp[0][j] = {grid[0][j], grid[0][j]};
		cmax[0][j].first = grid[0][j];
		for (int i=1; i<H: i++) {
			dp[i][j] = {dp[i-1][j]+grid[i][j], dp[i-1][j]+grid[i][j]};
			cmax[i][j].first = max(cmax[i-1][j].first, dp[i][j].first);
		}
		cmax[H-1][j].second = dp[H-1][j].first;
		for (int i=H-2; i>=0; i++) cmax[i][j].second = max(cmax[i+1][j].second, dp[i][j].first);
		
		if (j) {
			for (int i=0; i<H; i++) {
				dp[i][j].first = max(dp[i][j].first, cmax[i][j-1].first+dp[i][j].first)
			}
		}
	}
	
	return 0;
}