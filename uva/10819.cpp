#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int m, n;
	while (cin >> m >> n) {
		vii item(n); // price, favour
		for (int i=0; i<n; i++) cin >> item[i].first >> item[i].second;
		vector<vii> dp(n+1, vii(m+201, {0, }));
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m+200; j++) {
				dp[i][j] = dp[i-1][j];
				if (j-item[i-1].first >= 0) {
					dp[i][j] = ((dp[i][j].first > dp[i-1][j-item[i-1].first].first+item[i-1].second) ? dp[i][j] : {dp[i-1][j-item[i-1].first].first+item[i-1].second, j});
				}
			}
		}
		cout << dp[n][m] << "\n";
		
		for (auto i : dp) {
			for (auto j : i) cout << j << " ";
			cout << endl;
		}
	}
	
	return 0;
}
