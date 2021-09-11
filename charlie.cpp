#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> heights;
	
	int x;
	cin >> x;
	while (x != -1) {
		heights.push_back(x);
		cin >> x;
	}
	
	int N = heights.size();
	
	vector< vector<int> > table(2, vector<int>(N));
	table.at(0).assign(N, 0);
	
	
	
	return 0;
}