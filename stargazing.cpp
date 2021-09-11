#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, x, y, cmaxy = 0;
	cin >> N;
	
	vector< vector<int> > gridy(1000001);
	vector< vector<int> > gridx(1000001);
	
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		gridy[y].push_back(x);
		gridx[x].push_back(y);
		cmaxy = max(cmaxy, y);
	}
	
	int cmax = 0;
	
	for (int i=cmaxy; i>=0; i--) {
		if (gridy[i].size() >= 2) {
			int x1 = *min_element(gridy[i].begin(), gridy[i].end());
			int x2 = *max_element(gridy[i].begin(), gridy[i].end());
			
			int cmin = cmaxy;
			
			for (int j=x1+1; j<x2; j++) {
				if (gridx[j].size() > 0) {
					cmin = min(cmin, *min_element(gridx[j].begin(), gridx[j].end()));
				}
			}
			//cout << x2 << " " << x1 << " " << i << " " << cmin << " " << x2-x1+i-cmin << endl;
			cmax = max(cmax, x2-x1+i-cmin);
		}
	}
	
	cout << cmax << endl;
	
	return 0;
}