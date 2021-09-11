#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int p, q, r, s, t, u;
	bool broken;
	while (cin >> p >> q >> r >> s >> t >> u) {
		broken = false;
		double low = -0.0001, high = 1.0000, mid, ans;
		while (high-low > 0.000000001) {
			mid = (low+high)/2;
			ans = p*exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*mid*mid + u;
			if (ans <= 0.00000005 && ans >= -0.00000005) { broken = true; break; }
			else if (ans > 0.00000005) low = mid;
			else if (ans < -0.00000005) high = mid;
		}
		if (broken) printf("%.4f\n", abs(mid));
		else cout << "No solution\n";
	}
	
	return 0;
}