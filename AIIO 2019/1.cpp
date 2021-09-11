#include <bits/stdc++.h>

using namespace std;

int next_two(int value) {
	return 1 << (32-__builtin_clz(value-1));
}

struct SegmentTree {
	int size;
	vector<int> 
}

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> scores(n);
	
	for (int i=0; i<n; i++) {
		cin >> scores.at(i);
	}
	
	vector< vector<pair<int, int> > > table(n+1, vector< pair<int, int> > (k+1));
	
	for (int i=0; i<=n; i++) {
		for (int j = 0; j<=k; j++) {
			if (i == 0 || j == 0) {
				table.at(i).at(j) = {0, -1};
			} else {
				if (table.at(i-1).
				table.at(i).at(j).first = max(table.at(i-1).at(j), table.at(i-1).at(j-1)+scores.at(i-2));
			}
		}
	}
	
	cout << *max_element(table.at)
	
	return 0;
}