#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, s, m, h;
	bool sync;
	vector<int> times(2);
	cin >> times.at(0) >> times.at(1);
	while (times.at(0) && times.at(1)) {
		cin >> x;
		while (x != 0) {
			times.push_back(x);
			cin >> x;
		}
		
		x = *min_element(times.begin(), times.end());
		
		for (int i=x; i<18001; i++) {
			sync = true;
			for (auto j : times) {
				if ((i/j)%2 || ((i+5)/j)%2) {
					sync = false;
					break;
				}
			}
			if (sync) {
				s = i%60;
				m = (i/60)%60;
				h = i/3600;
				printf("%02d:%02d:%02d\n", h, m, s);
				break;
			}
		}
		
		if (!sync) {
			cout << "Signals fail to synchronise in 5 hours\n";
		}
		
		times.resize(2);
		cin >> times.at(0) >> times.at(1);
	}
	cin >> x;
	
	return 0;
}