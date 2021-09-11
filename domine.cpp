#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, num, add;
	cin >> N >> K;
	vector<vi> grid(N, vi(3));
	for (int i=0; i<N; i++) cin >> grid[i][0] >> grid[i][1] >> grid[i][2];
	
	vector< vector<vi> > dp(2, vector<vi>(max(K+1, 4), vi(8, -INF)));
	dp[0][0][0] = 0;
	dp[1][0][0] = 0;
	dp[0][1][0] = grid[0][1]+max(grid[0][0], grid[0][2]);
	dp[0][1][1] = grid[0][2];
	dp[0][2][1] = grid[0][0]+grid[0][1]+grid[0][2];
	dp[0][1][2] = grid[0][1];
	dp[0][2][3] = grid[0][1]+grid[0][2];
	dp[0][1][4] = grid[0][0];
	dp[0][2][4] = grid[0][0]+grid[0][1]+grid[0][2];
	dp[0][2][5] = grid[0][0]+grid[0][2];
	dp[0][2][6] = grid[0][0]+grid[0][1];
	dp[0][3][7] = grid[0][0]+grid[0][1]+grid[0][2];
	
	for (int i=0; i<N-1; i++) {
		for (int k=0; k<=K; k++) {
			for (int j=0; j<8; j++) {
				for (int l=0; l<8; l++) {
					if (j&l) continue;
					add = 0;
					num = 0;
					for (int a=0; a<3; a++) {
						if (j&(1<<a)) add += grid[i+1][2-a];
						if (l&(1<<a)) { num++; add += grid[i+1][2-a]; }
					}
					if (k+num > K) continue;
					dp[(i+1)%2][k+num][l] = max(dp[(i+1)%2][k+num][l], dp[i%2][k][j]+add);
					
					if (k+num+1 > K) continue;
					if (!(j&3) && !(l&3)) dp[(i+1)%2][k+num+1][l] = max(dp[(i+1)%2][k+num+1][l], dp[i%2][k][j]+add+grid[i+1][1]+grid[i+1][2]);
					if (!(j&6) && !(l&6)) dp[(i+1)%2][k+num+1][l] = max(dp[(i+1)%2][k+num+1][l], dp[i%2][k][j]+add+grid[i+1][0]+grid[i+1][1]);
				}
			}
		}
		dp[i%2].assign(K+1, vi(8, -INF));
		dp[0][0][0] = 0;
		dp[1][0][0] = 0;
	}
	
	cout << dp[(N-1)%2][K][0] << "\n";
	
	/*for (int i=0; i<=K; i++) {
		for (int j=0; j<N; j++) {
			for (int k=0; k<8; k++) cout << dp[j][i][k] << " ";
			cout << endl;
		}
		cout << endl;
	}*/
	//line across different states per domino
	
	return 0;
}