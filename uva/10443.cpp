#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, r, c, n;
	unordered_map<char, char> w = {{'P', 'R'}, {'R', 'S'}, {'S', 'P'}};
	cin >> t;
	while (t--) {
		cin >> r >> c >> n;
		vector< vector< vector<char> > > grid(2, vector< vector<char> > (r, vector<char> (c)));
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				cin >> grid.at(0).at(i).at(j);
			}
		}
		grid.at(1) = grid.at(0);
		
		while (n--) {
			for (int i=0; i<r; i++) {
				for (int j=0; j<c; j++) {
					if (i > 0) {
						if (w.at(grid.at(n%2).at(i).at(j)) == grid.at(n%2).at(i-1).at(j)) {
							grid.at((n+1)%2).at(i-1).at(j) = grid.at(n%2).at(i).at(j);
						}
					}
					if (i < r-1) {
						if (w.at(grid.at(n%2).at(i).at(j)) == grid.at(n%2).at(i+1).at(j)) {
							grid.at((n+1)%2).at(i+1).at(j) = grid.at(n%2).at(i).at(j);
						}
					}
					if (j > 0) {
						if (w.at(grid.at(n%2).at(i).at(j)) == grid.at(n%2).at(i).at(j-1)) {
							grid.at((n+1)%2).at(i).at(j-1) = grid.at(n%2).at(i).at(j);
						}
					}
					if (j < c-1) {
						if (w.at(grid.at(n%2).at(i).at(j)) == grid.at(n%2).at(i).at(j+1)) {
							grid.at((n+1)%2).at(i).at(j+1) = grid.at(n%2).at(i).at(j);
						}
					}
				}
			}
			grid.at(n%2) = grid.at((n+1)%2);
		}
		
		for (auto i : grid.at(1)) {
			for (auto j : i) {
				cout << j;
			}
			cout << "\n";
		}
		if (t) cout << "\n";
	}
	
	return 0;
}