#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	int t, m, n, total;
	
	cin >> t;
	
	for (int TC=0; TC<t; TC++) {
		cin >> c >> m >> n;
		if (c == 'r') {
			cout << min(m, n) << "\n";
		} else if (c == 'k') {
			cout << ceil(n/2.0f)*ceil(m/2.0f) + (n/2)*(m/2) << "\n";
		} else if (c == 'Q') {
			cout << min(m, n) << "\n";
		} else if (c == 'K') {
			cout << ceil(n/2.0f)*ceil(m/2.0f) << "\n";
		}
	}
	
	return 0;
}