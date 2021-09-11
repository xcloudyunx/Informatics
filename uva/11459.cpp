#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, a, b, c, x, y, cp, r;
	bool finished;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		vector<int> adj(101, 0);
		vector<int> pos(a, 1);
		while (b--) {
			cin >> x >> y;
			adj.at(x) = y;
		}
		finished = false;
		cp = 1;
		while (c--) {
			cin >> r;
			if (!finished) {
				pos.at(cp) += r;
				if (adj.at(pos.at(cp))) {
					pos.at(cp) = adj.at(pos.at(cp));
				}
				if (pos.at(cp) >= 100) {
					pos.at(cp) = 100;
					finished = true;
				}
			}
			cp = (cp+1)%a;
		}
		for (int i=1; i<=a; i++) {
			cout << "Position of player " << i << " is " << pos.at(i%a) << ".\n";
		}
	}
	
	return 0;
}