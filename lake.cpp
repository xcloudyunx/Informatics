#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF LLONG_MAX

int main() {
	int N;
	ll cmin = INF;
	
	cin >> N;
	vll huts(N);
	for (int i=0; i<N; i++) cin >> huts[i];
	vll prefix(N+1);
	vll prefix2(N+1);
	prefix[0] = 0;
	prefix2[0] = 0;
	
	for (int i=1; i<=N; i++) {
		prefix[i] = huts[i-1] + prefix[i-1];
		prefix2[i] = i*huts[i-1] + prefix2[i-1];
	}
	
	for (int i=0; i<=N; i++) cmin = min(cmin, prefix2[N]-i*prefix[N]+N*prefix[i]);
	

	for (int i=1; i<=N; i++) {
		prefix[i] = huts[N-i] + prefix[i-1];
		prefix2[i] = i*huts[N-i] + prefix2[i-1];
	}
	
	for (int i=0; i<=N; i++) cmin = min(cmin, prefix2[N]-i*prefix[N]+N*prefix[i]);
	
	cout << cmin << "\n";
	
	return 0;
}