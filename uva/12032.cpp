#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, n, low, high, mid, k;
	bool broken;
	cin >> T;
	for (int TC=1; TC<=T; TC++) {
		cin >> n;
		vi r(n+1);
		r[0] = 0;
		for (int i=1; i<=n; i++) cin >> r[i];
		low = 0, high = 10000000;
		while (high-low > 1) {
			mid = (low+high)/2;
			k = mid;
			broken = false;
			for (int i=1; i<=n; i++) {
				if (r[i]-r[i-1] > k) { broken = true; break; }
				if (r[i]-r[i-1] == k) k--;
			}
			if (broken) low = mid;
			else high = mid;
		}
		cout << "Case " << TC << ": " << high << "\n";
	}
	
	return 0;
}