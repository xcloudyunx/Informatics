#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int R, C, x;
	cin >> R >> C;
	vector<vi> P(R, vi(C));
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) cin >> P[i][j];
	}
	
	vector< vector<vi> > dp(R, vector<vi>(C, vi(4, 0)));
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (!i && !j) continue;
			for (int k=0; k<4; k++) {
				x = 0;
				if (i) {
					if (k == 2 || k == 3) {
						x += max(max(dp[i-1][j][0], dp[i-1][j][1]) + max(0, P[i-1][j]+P[i][j]), max(dp[i-1][j][2], dp[i-1][j][3]));
					} else {
						x += *max_element(dp[i-1][j].begin(), dp[i-1][j].end());
					}
				}
				if (j) {
					if (k == 1 || k == 3) {
						x += max(max(dp[i][j-1][0], dp[i][j-1][2]) + max(0, P[i][j-1]+P[i][j]), max(dp[i][j-1][1], dp[i][j-1][3]));
					} else {
						x += *max_element(dp[i][j-1].begin(), dp[i][j-1].end());
					}
				}
				if (i && j) {
					x -= *max_element(dp[i-1][j-1].begin(), dp[i-1][j-1].end());
				}
				
				dp[i][j][k] = x;
			}
		}
	}
	
	cout << *max_element(dp[R-1][C-1].begin(), dp[R-1][C-1].end()) << "\n";
	
	return 0;
}