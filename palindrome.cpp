#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string a;
	cin >> a;
	
	string b(a.rbegin(), a.rend());
	
	vector< vector<int> > table(2, vector<int>(N+1, -1));
	
	for (int i=0; i<=N; i++) {
		table.at(0).at(i) = i;
	}
	
	for (int i=1; i<=N; i++) {
		int c = i%2;
		int p = (i-1)%2;
		table.at(c).at(0) = i;
		for (int j=1; j<=N; j++) {
			if (a.at(i-1) == b.at(j-1) && table.at(c).at(j-1) == table.at(p).at(j)) {
				table.at(c).at(j) = table.at(c).at(j-1)-1;
			} else {
				table.at(c).at(j) = min(table.at(c).at(j-1), table.at(p).at(j))+1;
			}
		}
		
		for (auto j : table.at(c)) {
			cout << j << " ";
		}
		cout << endl;
	}
	
	cout << table.at(N%2).at(N)/2 << endl;
	
	return 0;
}