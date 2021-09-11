#include <bits/stdc++.h>

using namespace std;

int main() {
	int R, C, cmax, pmax, cpos, ppos;
	cin >> R >> C;
	
	vector< vector<int> > grid(R, vector<int>(C));
	vector< pair< pair<int, int>, pair<int, int> > > big(R);
	
	for (int i=0; i<R; i++) {
		cmax = INT_MIN;
		for (int j=0; j<C; j++) {
			cin >> grid.at(i).at(j);
			if (grid.at(i).at(j) >= cmax) {
				pmax = cmax;
				ppos = cpos;
				cmax = grid.at(i).at(j);
				cpos = j;
			} else if (grid.at(i).at(j) >= pmax) {
				pmax = grid.at(i).at(j);
				ppos = j;
			}
		}
		big.at(i) = make_pair(make_pair(cmax, cpos), make_pair(pmax, ppos));
	}
	
	sort(big.begin(), big.end());
	
	cmax = INT_MIN;
	for (int i=0; i<R; i++) {
		int x = big.at(i).first.first;
		int xpos = big.at(i).first.second;
		int y = big.at(i).second.first;
		int ypos = big.at(i).second.second;
		
		for (int j=i+1; j<R; j++) {
			if (xpos != big.at(j).first.second) {
				cmax = max(cmax, x+big.at(j).first.first);
			} else {
				cmax = max({cmax, x+big.at(j).second.first, y+big.at(j).first.first});
			}
		}
	}
	
	cout << cmax;
	
	return 0;
}