#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
#define INF INT_MAX

int main() {
	int R, C, T, r, c, p, num;
	cin >> R >> C >> T;
	vvi grid(R, vi(C));
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) cin >> grid[i][j];
	}
	vvi tasks(R, vi(C));
	for (int i=0; i<T; i++) {
		cin >> r >> c >> p;
		tasks[r][c] = p;
	}
	
	priority_queue< pair<ii, ii>, vector< pair<ii, ii> >, greater< pair<ii, ii> > > q;
	vector<vvi> distance(R, vvi(C, vi(T+1, -1)));
	
	q.push({{0, 0}, {0, 0});
	distance[0][0][0] = 0;
	while (!q.empty()) {
		p = q.top().first.first;
		num = q.top().first.second;
		r = q.top().second.first;
		c = q.top().second.second;
	}
	
	return 0;
}