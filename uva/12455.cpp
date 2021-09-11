#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int t, n, p, l;
	cin >> t;
	while (t--) {
		cin >> n >> p;
		vi bars(p);
		for (int i=0; i<p; i++) cin >> bars[i];
		for (int i=0; i<(1<<p); i++) {
			l = 0;
			for (int j=0; j<p; j++) {
				if (i & (1<<j)) l += bars[j];
			}
			if (l == n) break;
		}
		if (l == n) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}