#include <bits/stdc++.h>

using namespace std;

int knapSack() {
	if (n == 0) {
		return 0;
	} else if (table.at(n).at(size) != -1) {
		return table.at(n).at(size);
	} else if (n != cowNumbers.size() && cowNumbers.at(n-1) > cowNumbers.at(n) {
		
	} else {
		int valueWith = 1 + knapSack();
		int valueWithout = knapSack();
		return table.at(n).at(size) = min(tableWith, tableWithout);
	}
}

int main() {
	int N;
	cin >> N;
	
	vector<int> cowNumbers(N);
	vector< vector<int> > table(N+1, vector<int>(N+1, -1));
	
	for (int i=0; i<N; i++) {
		cin >> cowNumbers.at(i);
	}
	
	cout << knapSack() << endl;
	
	return 0;
}