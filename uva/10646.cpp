#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, X;
	string c;
	cin >> t;
	
	for (int TC=1; TC<=t; TC++) {
		list<string> d;
		for (int i=0; i<52; i++) {
			cin >> c;
			d.push_back(c);
		}
		int Y = 0;
		for (int i=0; i<3; i++) {
			auto it = d.end();
			advance(it, -26);
			if ((*it).at(0) == 'A' || (*it).at(0) == 'J' || (*it).at(0) == 'Q' || (*it).at(0) == 'K'  || (*it).at(0) == 'T') {
				X = 10;
			} else {
				X = (*it).at(0)-'0';
			}
			Y += X;
			auto it2 = d.end();
			advance(it2, X-36);
			advance(it, 1);
			d.erase(it2, it);
		}
		auto it = d.begin();
		advance(it, Y-1);
		cout << "Case " << TC << ": " << *it << "\n";
	}
	
	return 0;
}