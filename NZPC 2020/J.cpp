#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int R, C;
	cin >> R >> C;
	
	while (R && C) {
	
		vector<vi> grid(R, vi(C, 0));
		vector< vector< unordered_set<int> > > options(R, vector< unordered_set<int> >(C));
		
		bool changes = false;
		bool broken = false;
		
		int r1, r2, c1, c2;
		vector<vi> co(R*C);
		for (int i=0; i<R*C; i++) {
			cin >> r1 >> c1 >> r2 >> c2;
			r1--; c1--; r2--; c2--;
			if (r1 < 0 || c1 < 0 || r1 >= R || c1 >= C) {
				grid[r2][c2] = max(r2, r1)-min(r2, r1) + max(c2, c1)-min(c2, c1);
			} else if (r2 < 0 || c2 < 0 || r2 >= R || c2 >= C) {
				grid[r1][c1] = max(r2, r1)-min(r2, r1) + max(c2, c1)-min(c2, c1);
			}
			co[i] = {r1, c1, r2, c2};
		}
		while (true) {
			for (int i=0; i<R*C; i++) {
				r1 = co[i][0];
				c1 = co[i][1];
				r2 = co[i][2];
				c2 = co[i][3];
				if (((r2 < 0 || c2 < 0 || r2 >= R || c2 >= C) || (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && grid[r2][c2] != 0)) && ((r1 < 0 || c1 < 0 || r1 >= R || c1 >= C) || (r1 >= 0 && r1 < R && c1 >= 0 && c1 < C && grid[r1][c1] != 0))) continue;
				
				if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && grid[r2][c2] != 0) {
					grid[r1][c1] = max(r2, r1)-min(r2, r1) + max(c2, c1)-min(c2, c1);
					changes = true;
				} else if (r1 >= 0 && r1 < R && c1 >= 0 && c1 < C && grid[r1][c1] != 0) {
					grid[r2][c2] = max(r2, r1)-min(r2, r1) + max(c2, c1)-min(c2, c1);
					changes = true;
				}
			}
			if (!changes) break;
			changes = false;
		}
		
		for (int i=0; i<R*C; i++) {
			r1 = co[i][0];
			c1 = co[i][1];
			r2 = co[i][2];
			c2 = co[i][3];
			if (((r2 < 0 || c2 < 0 || r2 >= R || c2 >= C) || (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && grid[r2][c2] != 0)) && ((r1 < 0 || c1 < 0 || r1 >= R || c1 >= C) || (r1 >= 0 && r1 < R && c1 >= 0 && c1 < C && grid[r1][c1] != 0))) continue;

			if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C) {
				options[r2][c2].insert(max(r2, r1)-min(r2, r1) + max(c2, c1)-min(c2, c1));
			}
			if (r1 >= 0 && r1 < R && c1 >= 0 && c1 < C ) {
				options[r1][c1].insert(max(r2, r1)-min(r2, r1) + max(c2, c1)-min(c2, c1));
			}
		}
		
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (grid[i][j] == 0) {
					if (options[i][j].size() == 1) {
						grid[i][j] = *options[i][j].begin();
					} else {
						broken = true;
						break;
					}
				}
			}
		}
		
		cout << "\n";
		if (broken) cout << "No solution\n";
		else {
			for (auto i : grid) {
				for (auto j : i) {
					cout << j;
				}
				cout << "\n";
			}
		}
		
		cin >> R >> C;
	}
}