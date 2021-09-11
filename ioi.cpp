#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector< vector<int> > table(2, vector<int> (4));
	
	for (int i=1; i<=n; i++) {
		if (i == 1) {
			table.at(i%2).at(0) = 1;
		} else if (i == 2) {
			table.at(i%2).at(0) = (table.at((i+1)%2).at(0)+k-1)%i+1;
			table.at(i%2).at(1) = 3-table.at(i%2).at(0);
		} else if (i == 3) {
			table.at(i%2).at(0) = (table.at((i+1)%2).at(0)+k-1)%i+1;
			table.at(i%2).at(1) = (table.at((i+1)%2).at(1)+k-1)%i+1;
			table.at(i%2).at(2) = 6-table.at(i%2).at(0)-table.at(i%2).at(1);
		} else if (i == 4) {
			table.at(i%2).at(0) = (table.at((i+1)%2).at(0)+k-1)%i+1;
			table.at(i%2).at(1) = (table.at((i+1)%2).at(1)+k-1)%i+1;
			table.at(i%2).at(2) = (table.at((i+1)%2).at(2)+k-1)%i+1;
			table.at(i%2).at(3) = 10-table.at(i%2).at(0)-table.at(i%2).at(1)-table.at(i%2).at(2);
		} else {
			table.at(i%2).at(0) = (table.at((i+1)%2).at(0)+k-1)%i+1;
			table.at(i%2).at(1) = (table.at((i+1)%2).at(1)+k-1)%i+1;
			table.at(i%2).at(2) = (table.at((i+1)%2).at(2)+k-1)%i+1;
			table.at(i%2).at(3) = (table.at((i+1)%2).at(3)+k-1)%i+1;
		}
	}
	
	for (int i=3; i>=0; i--) {
		cout << table.at(n%2).at(i) << " ";
	}
	
	return 0;
}