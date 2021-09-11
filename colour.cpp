#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define MOD 1000000007

int main() {
	int n, c, p, a, b;
	ll z;
	cin >> n >> c;
	vi x(n);
	for (int i=0; i<n; i++) cin >> x[i];
	vector< set<int> > adj(c+1);
	cin >> p;
	for (int i=0; i<p; i++) {
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	
	vll num(c+1, 0);
	vll dp(n, 0);
	dp[0] = 1;
	num[x[0]] = 1;
	for (int i=1; i<n; i++) {
		z = 0;
		for (auto j : adj[x[i]]) {
			z = (z+num[j])%MOD;
		}
		dp[i] = z;
		num[x[i]] = (num[x[i]]+z)%MOD;
	}
	
	cout << dp[n-1] << "\n";
	
	return 0;
}