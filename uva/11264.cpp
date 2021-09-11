#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000000000000

int main() {
	int T, n, num;
	ll sum;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<ll> C(n+1);
		for (int i=0; i<n; i++) cin >> C[i];
		C[n] = INF;
		num = 0;
		sum = 0;
		for (int i=0; i<n; i++) {
			if (sum + C[i] < C[i+1]) {
				sum += C[i];
				num++;
			}
		}
		cout << num << "\n";
	}
	
	return 0;
}