#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, m, low, mid, high, num, cscore;
	while (cin >> n >> m) {
		vi c(n);
		for (int i=0; i<n; i++) cin >> c[i];
		low = 0, high = 1000000000;
		while (high-low > 1) {
			mid = (low+high)/2;
			num = 1;
			cscore = 0;
			for (auto i : c) {
				if (i > mid) { num = INF; break; }
				if (cscore + i > mid) {
					num++;
					cscore = 0;
				}
				cscore += i;
			}
			if (cscore == 0) num--;
			if (num > m) low = mid;
			else high = mid;
		}
		cout << high << "\n";
	}
	
	return 0;
}