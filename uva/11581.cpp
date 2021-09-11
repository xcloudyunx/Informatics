#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, count;
	cin >> t;
	
	vector< vector<int> > empty(3, vector<int>(3, 0));
	vector< vector< vector<int> > > g(2, vector< vector<int> >(3, vector<int>(3)));
	
	while (t--) {
		count = -1;
		
		scanf("%1d%1d%1d\n%1d%1d%1d\n%1d%1d%1d", &g.at(0).at(0).at(0), &g.at(0).at(0).at(1), &g.at(0).at(0).at(2), &g.at(0).at(1).at(0), &g.at(0).at(1).at(1), &g.at(0).at(1).at(2), &g.at(0).at(2).at(0), &g.at(0).at(2).at(1), &g.at(0).at(2).at(2));
		
		while (g.at((count+1)%2) != empty) {
			g.at((count+2)%2).at(0).at(0) = (g.at((count+1)%2).at(0).at(1)+g.at((count+1)%2).at(1).at(0))%2;
			g.at((count+2)%2).at(0).at(1) = (g.at((count+1)%2).at(0).at(0)+g.at((count+1)%2).at(1).at(1)+g.at((count+1)%2).at(0).at(2))%2;
			g.at((count+2)%2).at(0).at(2) = (g.at((count+1)%2).at(0).at(1)+g.at((count+1)%2).at(1).at(2))%2;
			g.at((count+2)%2).at(1).at(0) = (g.at((count+1)%2).at(0).at(0)+g.at((count+1)%2).at(1).at(1)+g.at((count+1)%2).at(2).at(0))%2;
			g.at((count+2)%2).at(1).at(1) = (g.at((count+1)%2).at(0).at(1)+g.at((count+1)%2).at(1).at(0)+g.at((count+1)%2).at(1).at(2)+g.at((count+1)%2).at(2).at(1))%2;
			g.at((count+2)%2).at(1).at(2) = (g.at((count+1)%2).at(0).at(2)+g.at((count+1)%2).at(1).at(1)+g.at((count+1)%2).at(2).at(2))%2;
			g.at((count+2)%2).at(2).at(0) = (g.at((count+1)%2).at(1).at(0)+g.at((count+1)%2).at(2).at(1))%2;
			g.at((count+2)%2).at(2).at(1) = (g.at((count+1)%2).at(2).at(0)+g.at((count+1)%2).at(1).at(1)+g.at((count+1)%2).at(2).at(2))%2;
			g.at((count+2)%2).at(2).at(2) = (g.at((count+1)%2).at(2).at(1)+g.at((count+1)%2).at(1).at(2))%2;
			count++;
		}
		
		cout << count << "\n";
	}
	
	return 0;
}