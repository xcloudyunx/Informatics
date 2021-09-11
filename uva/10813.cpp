#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;;
	bool won, used, used2;
	cin >> n;

	while (n--) {
		vector< vector<int> > grid(12, vector<int> (5));
		vector< unordered_set<int> > combinations(12);
		for (int i=0; i<5; i++) {
			for (int j=0; j<5; j++) {
				if (i == 2 && j == 2) {
					grid.at(i).at(j) = -1;
					continue;
				}
				cin >> grid.at(i).at(j);
			}
		}
		for (int i=0; i<5; i++) {
			for (int j=0; j<5; j++) {
				combinations.at(i).insert(grid.at(i).at(j));
			}
		}
		for (int i=5; i<10; i++) {
			for (int j=0; j<5; j++) {
				combinations.at(i).insert(grid.at(j).at(i-5));
			}
		}
		for (int i=0, j=0; i<5; i++, j++) {
			combinations.at(10).insert(grid.at(i).at(j));
			combinations.at(11).insert(grid.at(i).at(4-j));
		}
		
		won = false;
		used2 = false;
		for (int i=1; i<=75; i++) {
			cin >> x;
			if (!won) {
				used = false;
				for (int j=0; j<12; j++) {
					auto it = combinations.at(j).find(x);
					if (it != combinations.at(j).end()) {
						combinations.at(j).erase(it);
						used = true;
						if (combinations.at(j).empty()) {
							cout << "BINGO after " << i << " numbers announced\n";
							won = true;
							break;
						}
					}
				}
				if (!used && !used2) {
					combinations.at(2).erase(combinations.at(2).find(-1));
					combinations.at(7).erase(combinations.at(7).find(-1));
					combinations.at(10).erase(combinations.at(10).find(-1));
					combinations.at(11).erase(combinations.at(11).find(-1));
					used2 = true;
				}
			}
		}
	}
	
	return 0;
}