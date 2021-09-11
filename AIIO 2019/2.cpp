#include <bits/stdc++.h>

using namespace std;

int main() {
	int R, C;
	cin >> R >> C;
	
	vector< vector<int> > grid(R, vector<int> (C));
	
	vector< vector< pair<int, int> > > table(R, vector< pair<int, int> > (C));
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> grid.at(i).at(j);
		}
	}
	
	int Q;
	cin >> Q;
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (i == 0) {
				if (j == 0) {
					table.at(i).at(j) = {grid.at(i).at(j), grid.at(i).at(j)};
				} else {
					table.at(i).at(j).first = table.at(i).at(j-1).second+grid.at(i).at(j);
					table.at(i).at(j).second = max(table.at(i).at(j-1).second, table.at(i).at(j).first);
				}
			} else {
				if (j == 0) {
					table.at(i).at(j).first = table.at(i-1).at(j).second+grid.at(i).at(j);
					table.at(i).at(j).second = max(table.at(i-1).at(j).second, table.at(i).at(j).first);
				} else {
					int x = max(table.at(i-1).at(j).second, table.at(i).at(j-1).second);
					table.at(i).at(j).first = x+grid.at(i).at(j);
					table.at(i).at(j).second = max(table.at(i).at(j).first, x);
				}
			}
		}
	}
	
	/*for (auto i : table) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}*/
	
	if (Q != 0) {
		for (int i=0; i<Q; i++) {
			int sr, sc, fr, fc;
			cin >> sr >> sc >> fr >> fc;
			cout << table.at(fr).at(fc).first-max(table.at(sr).at(fc).first, table.at(fr).at(sc).first) << endl;
		}
	} else {
		cout << table.at(R-1).at(C-1).first << endl;
	}
	
	return 0;
}