#include <bits/stdc++.h>

using namespace std;

int main() {
	int W, L;
	cin >> W;
	cin >> L;
	
	vector< vector<int> > grid(2, vector<int> (W));
	vector< vector< pair<int, int> > > table(2, vector< pair<int, int> > (W, {INT_MIN, INT_MIN})); //first from left, second from right
	
	for (int j=0; j<L; j++) {
		for (int i=0; i<W; i++) {
			cin >> grid.at(j%2).at(i);
			
			if (j == 0) {
				table.at(0).at(i) = {0, 0};
			} else {
				if (i != W-1) {
					int prev = grid.at((j-1)%2).at(i+1);
					table.at(j%2).at(i).second = max(table.at((j+1)%2).at(i+1).first-prev*prev, table.at((j+1)%2).at(i+1).second+prev);
				}
				if (i != 0) {
					int prev = grid.at((j-1)%2).at(i-1);
					table.at(j%2).at(i).first = max(table.at((j+1)%2).at(i-1).second-prev*prev, table.at((j+1)%2).at(i-1).first+prev);
				}
			}
		}
		if (j == 1) {
			for (int i=0; i<W; i++) {
				table.at((j+1)%2).at(i) = {INT_MIN, INT_MIN};
			}
		}
	}
	
	int cmax = INT_MIN;
	for (int i=0; i<W; i++) {
		cmax = max(cmax, max(table.at((L-1)%2).at(i).first, table.at((L-1)%2).at(i).second)+grid.at((L-1)%2).at(i));
	}
	
	cout << cmax << endl;
	
	return 0;
}