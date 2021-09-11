#include <bits/stdc++.h>

using namespace std;

int main() {
	int C, R;
	cin >> C >> R;
	
	vector<int> coins(C);
	vector<int> receivers(R);
	
	for (int i=0; i<C; i++) {
		cin >> coins[i];
	}
	
	for (int i=0; i<R; i++) {
		cin >> receivers[i];
	}
	
	vector< vector<int> > table(2, vector<int> (C+1, INT_MAX));
	table[0][0] = table[1][0] = 0;
	
	for (int i=1; i<=R; i++) {
		for (int j=1; j<=C; j++) {
			int c = i%2;
			int p = (i-1)%2;
			
			int x;
			
			if (j == 1) {
				x = abs(receivers[i-1] - coins[j-1]);
			} else if (coins[j-1] < receivers[i-1]) {
				x = table[c][j-1];
			} else if (coins[j-2] < receivers[i-1]) {
				x = table[c][j-1] + 2*(coins[j-1] - receivers[i-1]);
			} else {
				x = table[c][j-1] + coins[j-1] - coins[j-2];
			}
			
			table[c][j] = min(table[p][j], x);
		}
		
		for (auto j : table[i%2]) {
			cout << j << " ";
		}
		cout << endl;
	}
	
	cout << table[R%2][C] << endl;
	
	return 0;
}