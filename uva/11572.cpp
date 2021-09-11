#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, n, x, cmax, start;
	cin >> T;
	
	while (T--) {
		cin >> n;
		unordered_map<int, int> m;
		cmax = 0;
		start = 0;
		
		for (int i=0; i<n; i++) {
			cin >> x;
			if (m.find(x) == m.end()) {
				m.insert(make_pair(x, i));
			} else if (m.at(x) < start) {
				m.at(x) = i;
			} else {
				cmax = max(cmax, i-start);
				start = m.at(x)+1;
				m.at(x) = i;
			}
		}
		cmax = max(cmax, n-start);
		
		cout << cmax << "\n";
	}
	
	return 0;
}