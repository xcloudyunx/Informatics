#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, N, x, cmax, u;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<vi> grid(2*N, vi(2*N));
		for (int i=0; i<2*N; i++) {
			for (int j=0; j<2*N; j++) {
				if (i < N && j < N) {
					cin >> grid[i][j];
					grid[i+N][j] = grid[i][j];
					grid[i][j+N] = grid[i][j];
					grid[i+N][j+N] = grid[i][j];
				}
				if (i) grid[i][j] += grid[i-1][j];
				if (j) grid[i][j] += grid[i][j-1];
				if (i && j) grid[i][j] -= grid[i-1][j-1];
			}
		}
		cmax = -INF;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				for (int k=i; k<i+N; k++) {
					for (int l=j; l<j+N; l++) {
						x = grid[k][l];
						if (i) x -= grid[i-1][l];
						if (j) x -= grid[k][j-1];
						if (i && j) x += grid[i-1][j-1];
						cmax = max(cmax, x);
					}
				}
			}
		}
		cout << cmax << "\n";
	}
	
	return 0;
}