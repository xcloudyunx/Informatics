#include <bits/stdc++.h>

using namespace std;

int main () {
	int T, N, c, cmax;
	cin >> T;
	
	for (int i=1; i<=T; i++) {
		cmax = 0;
		cin >> N;
		while (N--) {
			cin >> c;
			cmax = max(cmax, c);
		}
		cout << "Case " << i << ": " << cmax << "\n";
	}
	
	return 0;
}