#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF INT_MAX

int main() {
	int n, h, w;
	cin >> n;
	vii tiles(n);
	for (int i=0; i<n; i++) {
		cin >> tiles[i].first >> tiles[i].second;
		tiles[i].second *= tiles[i].first*tiles[i].first;
	}
	cin >> h >> w;
	vector<vi> grid(h+1, vi(w+1, 0));
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			cin >> grid[i][j];
			grid[i][j] += grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
		}
	}
	
	vector<vi> dp(h+1, vi(w+1, INF));
	for (int i=0; i<=h; i++) dp[i][0] = 0;
	for (int i=0; i<=w; i++) dp[0][i] = 0;
	
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			for (int k=0; k<n; k++) {
				if (i-tiles[k].first < 0 || j-tiles[k].first < 0) continue;
				dp[i][j] = min(dp[i][j], dp[i-tiles[k].first][j-tiles[k].first]+abs(grid[i][j]-grid[i-tiles[k].first][j-tiles[k].first]-tiles[k].second));
			}
		}
	}
	
	cout << dp[h][w] << "\n";
	
	for (auto i : dp) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
	
	return 0;
}