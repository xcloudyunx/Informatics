#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int s, d, sum, tsum, cmax;
	bool broken;
	while (cin >> s >> d) {
		cmax = -INF;
		for (int i=0; i<(1<<12); i++) {
			queue<int> q;
			sum = 0, tsum = 0;
			broken = false;
			for (int j=0; j<12; j++) {
				if (i & (1<<j)) {
					q.push(s);
					sum += s;
					tsum += s;
				} else {
					q.push(-d);
					sum -= d;
					tsum -= d;
				}
				if (q.size() > 5) {
					sum -= q.front();
					q.pop();
				}
				if (q.size() == 5) {
					if (sum >= 0) {
						broken = true;
						break;
					}
				}
			}
			if (!broken) cmax = max(cmax, tsum);
		}
		if (cmax < 0) cout << "Deficit\n";
		else cout << cmax << "\n";
	}
	
	return 0;
}