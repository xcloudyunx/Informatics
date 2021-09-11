#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define MOD 1000003

int main() {
	ifstream infile;
	infile.open("birdin.txt");
	ofstream outfile;
	outfile.open("birdout.txt");
	
	int R, C, h, x, y, total = 0;
	bool base;
	infile >> R >> C;
	vector<vi> grid(R, vi(C));
	priority_queue< pair<int, pair<int, int> > > q;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			infile >> grid[i][j];
			q.push({grid[i][j], {i, j}});
		}
	}
	
	vector<vi> table(R, vi(C, -1));
	
	while (!q.empty()) {
		base = true;
		h = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();
		if (table[x][y] == -1) table[x][y] = 1;
		
		if (x && grid[x-1][y] < grid[x][y]) {
			if (table[x-1][y] == -1) table[x-1][y] = 0;
			table[x-1][y] = (table[x-1][y]+table[x][y])%MOD;
			base = false;
		}
		if (x+1 < R && grid[x+1][y] < grid[x][y]) {
			if (table[x+1][y] == -1) table[x+1][y] = 0;
			table[x+1][y] = (table[x+1][y]+table[x][y])%MOD;
			base = false;
		}
		if (y && grid[x][y-1] < grid[x][y]) {
			if (table[x][y-1] == -1) table[x][y-1] = 0;
			table[x][y-1] = (table[x][y-1]+table[x][y])%MOD;
			base = false;
		}
		if (y+1 < C && grid[x][y+1] < grid[x][y]) {
			if (table[x][y+1] == -1) table[x][y+1] = 0;
			table[x][y+1] = (table[x][y+1]+table[x][y])%MOD;
			base = false;
		}
		if (base) total = (total+table[x][y])%MOD;
	}
	
	outfile << total << "\n";
	
	return 0;
}