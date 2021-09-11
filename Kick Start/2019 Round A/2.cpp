#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int z=1; z<=T; z++) {
		int R, C;
		cin >> R >> C;
		
		vector< vector<int> > grid(R, vector<int> (C, INT_MAX));
		queue< pair<int, int> > q;
		
		for (int i=0; i<R; i++) {
			string s;
			cin >> s;
			for (int j=0; j<C; j++) {
				if (s.at(j) == '1') {
					grid.at(i).at(j) = 0;
					q.push(make_pair(i, j));
				}
			}
		}
		
		int cmax = 0;
		
		if (q.size() != R*C) {
			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				int val = grid.at(r).at(c)+1;
				
				if (r != 0) {
					if (val < grid.at(r-1).at(c)) {
						grid.at(r-1).at(c) = val;
						q.push(make_pair(r-1, c));
					}
				}
				if (r != R-1) {
					if (val < grid.at(r+1).at(c)) {
						grid.at(r+1).at(c) = val;
						q.push(make_pair(r+1, c));
					}
				}
				if (c != 0) {
					if (val < grid.at(r).at(c-1)) {
						grid.at(r).at(c-1) = val;
						q.push(make_pair(r, c-1));
					}
				}
				if (c != C-1) {
					if (val < grid.at(r).at(c+1)) {
						grid.at(r).at(c+1) = val;
						q.push(make_pair(r, c+1));
					}
				}
			}
			
			int cx;
			int cy;
			for (int i=0; i<R; i++) {
				for (int j=0; j<C; j++) {
					if (grid.at(i).at(j) > cmax) {
						cmax = grid.at(i).at(j);
						cx = i;
						cy = j;
					}
				}
			}
			
			grid.at(cx).at(cy) = 0;
			q.push(make_pair(cx, cy));
			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				int val = grid.at(r).at(c)+1;
				
				if (r != 0) {
					if (val < grid.at(r-1).at(c)) {
						grid.at(r-1).at(c) = val;
						q.push(make_pair(r-1, c));
					}
				}
				if (r != R-1) {
					if (val < grid.at(r+1).at(c)) {
						grid.at(r+1).at(c) = val;
						q.push(make_pair(r+1, c));
					}
				}
				if (c != 0) {
					if (val < grid.at(r).at(c-1)) {
						grid.at(r).at(c-1) = val;
						q.push(make_pair(r, c-1));
					}
				}
				if (c != C-1) {
					if (val < grid.at(r).at(c+1)) {
						grid.at(r).at(c+1) = val;
						q.push(make_pair(r, c+1));
					}
				}
			}
			
			cmax = 0;
			for (int i=0; i<R; i++) {
				for (int j=0; j<C; j++) {
					cmax = max(grid.at(i).at(j), cmax);
				}
			}
		}
		
		cout << "Case #" << z << ": " << cmax << endl;
	}
	
	return 0;
}