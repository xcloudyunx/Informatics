#include <bits/stdc++.h>

using namespace std;

int main() {
	int R, C, K, H, V;
	cin >> R >> C >> K >> H >> V;
	
	vector<int> hor(H);
	vector<int> ver(V);
	
	for (int i=0; i<H; i++) cin >> hor.at(i);
	for (int i=0; i<V; i++) cin >> ver.at(i);
	
	vector< vector<int> > table(2, vector<int> (K+1));
	
	for (int i=0; i<H+V; i++) {
		for (int j=0; j<K; j++) {
			bool v = false;
			int c = i%2;
			if (i >= H) {
				c = (i-H)%2;
				v = true;
			}
			int p = (c+1)%2;
			
			if (i == 0 || j == 0) {
				table.at(c).at(j) == R*C;
				continue;
			}
			
			table.at(c).at(j) = min(table.at(p).at(j), table.at(p).at(j)
		}
	}
	
	return 0;
}