#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int> t;

int main() {
	int R, C, T;
	cin >> R >> C >> T;
	
	vector< vector< pair<int, int> > > H(R, vector< pair<int, int> > (C, make_pair(0, 0)));
	vector< vector< pair<int, int> > > v(R, vector< pair<int, int> > (C, make_pair(INT_MAX, 0)));
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> H[i][j].first;
		}
	}
	
	for (int i=0; i<T; i++) {
		int a, b;
		cin >> a >> b >> H[a-1][b-1].second;
	}
	
	pair<int, int> end = {0, 0};
	cin >> end.first >> end.second;
	
	priority_queue< t, vector<t>, greater<t> > q; //tasks, purity, r, c
	q.push(make_tuple(0, 0, 0, 0));
	
	while (!q.empty()) {
		int tasks = get<0>(q.top());
		int purity = get<1>(q.top());
		int r = get<2>(q.top());
		int c = get<3>(q.top());
		q.pop();
		
		if ((tasks >= v[r][c].first && purity <= v[r][c].second) || (r == end.first && c == end.second)) {
			continue;
		}
		
		if (H[r][c].second != 0) {
			purity += H[r][c].second;
			tasks++;
		}
		
		cout << r << " " << c << " " << tasks << " " << purity << endl;
		
		v[r][c].first = min(v[r][c].first, tasks);
		v[r][c].second = max(v[r][c].second, purity);
		
		if (r != 0) {
			if ((v[r-1][c].first > tasks || v[r-1][c].second < purity) && H[r-1][c].first <= purity) {
				q.push(make_tuple(tasks, purity, r-1, c));
			}
		}
		
		if (r != R-1) {
			if ((v[r+1][c].first > tasks || v[r+1][c].second < purity) && H[r+1][c].first <= purity) {
				q.push(make_tuple(tasks, purity, r+1, c));
			}
		}
		
		if (c != 0) {
			if ((v[r][c-1].first > tasks || v[r][c-1].second < purity) && H[r][c-1].first <= purity) {
				q.push(make_tuple(tasks, purity, r, c-1));
			}
		}
		
		if (c != C-1) {
			if ((v[r][c+1].first > tasks || v[r][c+1].second < purity) && H[r][c+1].first <= purity) {
				q.push(make_tuple(tasks, purity, r, c+1));
			}
		}
	}
	
	cout << v[end.first][end.second].first << endl;
	
	return 0;
}