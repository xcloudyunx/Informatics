#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector< pair<int, int> > tiles(n);
	
	for (int i=0; i<n; i++) {
		cin >> tiles.at(i).second << tiles.at(i).first;
	}
	
	int h, w;
	cin >> h >> w;
	
	vector< vector<int> > grid(h, vector<int> (w));
	
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> grid.at(i).at(j);
		}
	}

	return 0;
}