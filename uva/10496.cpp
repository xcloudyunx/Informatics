#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, x, y, startx, starty, n, cmin;
	cin >> T;
	while (T--) {
		cin >> x >> y >> startx >> starty >> n;
		vii beep(n+1);
		beep[0] = {startx, starty};
		for (int i=1; i<=n; i++) cin >> beep[i].first >> beep[i].second;
		
		vector<vi> d(n+1, vi(n+1));
		for (int i=0; i<=n; i++) {
			d[i][i] = 0;
			for (int j=i+1; j<=n; j++) {
				d[i][j] = abs(beep[i].first-beep[j].first)+abs(beep[i].second-beep[j].second);
				d[j][i] = d[i][j];
			}
		}
		
		vector<vi> dp(n+1, vi((1<<(n+1)), INF));
		dp[0][((1<<(n+1))-1)^1] = 0;
		for (int j=(1<<(n+1))-1; j>0; j--) {
			if (j & 1) continue;
			for (int i=0; i<=n; i++) {
				if (j & (1<<i)) continue;
				for (int k=1; k<=n; k++) {
					if (j & (1<<k)) {
						dp[k][j^(1<<k)] = min(dp[k][j^(1<<k)], dp[i][j]+d[i][k]);
					}
				}
			}
		}
		
		cmin = INF;
		for (int i=1; i<=n; i++) {
			cmin = min(cmin, dp[i][0]+d[0][i]);
		}
		cout << "The shortest path has length " << cmin << "\n";
	}
	
	return 0;
}