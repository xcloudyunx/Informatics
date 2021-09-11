#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, B, H, W, cmin, p, w;
	
	while (cin >> N >> B >> H >> W) {
		cmin = INT_MAX;
		
		for (int i=0; i<H; i++) {
			cin >> p;
			for (int j=0; j<W; j++) {
				cin >> w;
				if (w >= N && p*N <= B) {
					cmin = min(cmin, p*N);
				}
			}
		}
		
		if (cmin == INT_MAX) {
			cout << "stay home\n";
		} else {
			cout << cmin << "\n";
		}
	}
	
	return 0;
}