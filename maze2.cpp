#include <bits/stdc++.h>

using namespace std;

bool output(vector<string> &grid, vector<string> test, int cx, int cy) {
	if (test.at(cy).at(cx+1) == 'E') {
		return true;
	} else if (test.at(cy).at(cx+1) == (test.at(cy).at(cx)-'0' + 1)%10+'0') {
		if (output(grid, test, cx+1, cy)) {
			grid.at(cy).at(cx+1) = test.at(cy).at(cx+1);
			return true;
		}
	}
	
	if (test.at(cy+1).at(cx) == 'E') {
		return true;
	} else if (test.at(cy+1).at(cx) == (test.at(cy).at(cx)-'0' + 1)%10+'0') {
		if (output(grid, test, cx, cy+1)) {
			grid.at(cy+1).at(cx) = test.at(cy+1).at(cx);
			return true;
		}
	}
	
	if (test.at(cy).at(cx-1) == 'E') {
		return true;
	} else if (test.at(cy).at(cx-1) == (test.at(cy).at(cx)-'0' + 1)%10+'0') {
		if (output(grid, test, cx-1, cy)) {
			grid.at(cy).at(cx-1) = test.at(cy).at(cx-1);
			return true;
		}
	}
	
	if (test.at(cy-1).at(cx) == 'E') {
		return true;
	} else if (test.at(cy-1).at(cx) == (test.at(cy).at(cx)-'0' + 1)%10+'0') {
		if (output(grid, test, cx, cy-1)) {
			grid.at(cy-1).at(cx) = test.at(cy-1).at(cx);
			return true;
		}
	}
	
	return false;
}

int main() {
	int N;
	cin >> N;
	
	for (int z=0; z<N; z++) {
		int x, y;
		cin >> x >> y;
		cin.ignore();
		
		vector<string> grid(y);
		vector<string> test;
		
		pair<int, int> start;
		pair<int, int> end;
		
		for (int i=0; i<y; i++) {
			getline(cin, grid.at(i));
			int n = grid.at(i).find("S");
			if (n != string::npos) {
				start = {n, i};
			}
			n = grid.at(i).find("E");
			if (n != string::npos) {
				end = {n, i};
			}
		}
		
		test = grid;
		
		queue< pair<int, int> > q;
		test.at(start.second).at(start.first) = 0+'0';
		q.push(start);
		
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			
			if (test.at(cy).at(cx+1) == 'E') {
				break;
			} else if (test.at(cy).at(cx+1) == ' ') {
				test.at(cy).at(cx+1) = (test.at(cy).at(cx)-'0' + 1)%10+'0';
				q.push({cx+1, cy});
			}
			
			if (test.at(cy+1).at(cx) == 'E') {
				break;
			} else if (test.at(cy+1).at(cx) == ' ') {
				test.at(cy+1).at(cx) = (test.at(cy).at(cx)-'0' + 1)%10+'0';
				q.push({cx, cy+1});
			}
			
			if (test.at(cy).at(cx-1) == 'E') {
				break;
			} else if (test.at(cy).at(cx-1) == ' ') {
				test.at(cy).at(cx-1) = (test.at(cy).at(cx)-'0' + 1)%10+'0';
				q.push({cx-1, cy});
			}
			
			if (test.at(cy-1).at(cx) == 'E') {
				break;
			} else if (test.at(cy-1).at(cx) == ' ') {
				test.at(cy-1).at(cx) = (test.at(cy).at(cx)-'0' + 1)%10+'0';
				q.push({cx, cy-1});
			}
		}
		
		output(grid, test, start.first, start.second);
		
		for (auto i : grid) {
			cout << i << endl;
		}
		cout << endl;
	}
	
	return 0;
}