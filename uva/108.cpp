#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, cmax = -INF, x;
	cin >> N;
	vector<vi> grid(N, vi(N));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> grid[i][j];
			if (j) grid[i][j] += grid[i][j-1];
		}
	}
	
	for (int l=0; l<N; l++) {
		for (int r=l; r<N; r++) {
			x = 0;
			for (int row=0; row<N; row++) {
				x += grid[row][r];
				if (l) x -= grid[row][l-1];
				cmax = max(cmax, x);
				if (x < 0) x = 0;
			}
		}
	}
	
	cout << cmax << "\n";
	
	return 0;
}