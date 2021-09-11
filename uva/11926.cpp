#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, s, e, r;
	bool broken;
	cin >> n >> m;
	
	while (n || m) {
		bitset<1000000> time;
		broken = false;
		while (n--) {
			cin >> s >> e;
			if (!broken) {
				for (int i=s; i<e; i++) {
					if (time.test(i)) {
						broken = true;
						break;
					}
					time.set(i);
				}
			}
		}
		while (m--) {
			cin >> s >> e >> r;
			if (!broken) {
				for (int i=s; i<=1000000;) {
					for (int j=i; j<min(1000000, e); j++) {
						if (time.test(j)) {
							broken = true;
							break;
						}
						time.set(j);
					}
					if (broken) {
						break;
					}
					i += r;
					e += r;
				}
			}
		}
		
		if (broken) {
			cout << "CONFLICT\n";
		} else {
			cout << "NO CONFLICT\n";
		}
		
		cin >> n >> m;
	}
	
	return 0;
}