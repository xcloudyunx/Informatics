#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, n, b, x;
	cin >> T;
	while (T--) {
		b = 0;
		cin >> n;
		multiset<int> a;
		while (n--) {
			cin >> x;
			b += distance(a.begin(), a.upper_bound(x));
			a.insert(x);
		}
		cout << b << "\n";
	}
	
	return 0;
}