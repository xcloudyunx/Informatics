#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, D, X;
	string s;
	cin >> N >> D >> s;
	vector<ll> F(N);
	vector<ll> X(D);
	for (int i=0; i<N; i++) cin >> F[i];
	for (int i=0; i<D; i++) cin >> X[i];
	
	vector<ll> lsum(N, 0);
	vector<ll> rsum(N, 0);
	ll cmax = 0;
	for (int i=0; i<N; i++) {
		if (s[i] == 'L') {
			lsum[i] = max((ll)0, F[i]-cmax);
			cmax = max(cmax, F[i]);
		}
	}
	for (int i=N-1; i>=0; i--) {
		rsum[i] = lsum[i];
		if (i != N-1) rsum[i] += rsum[i+1];
		if (s[i] == 'R') {
			rsum[i] = max(rsum[i], F[i]);
		}
	}
	
	cout << rsum[0] << "\n";
	
	for (auto j : X) {
		for (int i=j; i>=0; i--) {
			rsum[i] = lsum[i];
			if (i != N-1) rsum[i] += rsum[i+1];
			if (s[i] == 'R') {
				rsum[i] = max(rsum[i], F[i]);
			}
		}
	}
	
	return 0;
}