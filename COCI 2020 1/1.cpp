#include <bits/stdc++.h>

using namespace std;

int main() {
	int Q, l, r;
	cin >> Q;

	while (Q--) {
		cin >> l >> r;
		
		int x = (r-l+1)/9;
		int total = x*45;
		
		x = l + x*9;
		
		for (int i=x; i<=r; i++) {
			int y = i%9;
			if (y == 0) {
				total += 9;
			} else {
				total += y;
			}
		}
		
		cout << total << "\n";
	}
	
	return 0;
}