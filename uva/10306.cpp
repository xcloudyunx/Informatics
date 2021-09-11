#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, m, S, cmin;
	cin >> n;
	while (n--) {
		cin >> m >> S;
		vii money(m);
		for (int i=0; i<m; i++) cin >> money[i].first >> money[i].second;
		
		vector<vi> dp(S+1, vi(S+1, INF));
		dp[0][0] = 0;
		for (int i=0; i<=S; i++) {
			for (int j=0; j<=S; j++) {
				for (auto k : money) {
					if (i-k.first >= 0 && j-k.second >= 0) dp[i][j] = min(dp[i][j], dp[i-k.first][j-k.second]+1);
				}
			}
		}
		
		cmin = INF;
		for (int i=0, j=S; i<=j; i++) {
			while (i*i+j*j > S*S) j--;
			if (i*i+j*j == S*S) cmin = min({cmin, dp[i][j], dp[j][i]});
		}
		
		if (cmin == INF) cout << "not possible\n";
		else cout << cmin << "\n";
	}
	
	return 0;
}