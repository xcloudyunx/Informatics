#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, d, r, num;
	cin >> n >> d >> r;
	while (n && d && r) {
		vi morning(n);
		vi evening(n);
		for (int i=0; i<n; i++) cin >> morning[i];
		for (int i=0; i<n; i++) cin >> evening[i];
		sort(morning.begin(), morning.end());
		sort(evening.rbegin(), evening.rend());
		num = 0;
		for (int i=0; i<n; i++) {
			num += max(0, morning[i]+evening[i]-d);
		}
		cout << num*r << "\n";
		
		cin >> n >> d >> r;
	}
	
	return 0;
}