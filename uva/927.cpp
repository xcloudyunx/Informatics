#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int C, i, d, k, n, p, pp;
	ll total, cn;
	cin >> C;
	while (C--) {
		cin >> i;
		vi c(i+1);
		for (int j=0; j<=i; j++) cin >> c[j];
		cin >> d >> k;
		p = 0, n = 1;
		for (;;n++) {
			pp = p;
			p += n*d;
			if (pp < k && k <= p) break;
		}
		total = 0;
		cn = 1;
		for (int j=0; j<=i; j++) { total += c[j]*cn; cn *= n; }
		cout << total << "\n";
	}
	
	return 0;
}