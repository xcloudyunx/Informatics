#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, H, L;
	cin >> N >> H >> L;
	vi h(N);
	vi f(N);
	vector<bool> leap(N, false);
	for (int i=0; i<N; i++) cin >> h[i];
	for (int i=1; i<N; i++) cin >> f[i];
	
	priority_queue<ii> cmaxh;
	for (int i=1; i<L; i++) cmaxh.push({h[i], i});
	for (int i=0, e=L; e<N; i++, e++) {
		cmaxh.push({h[e], e});
		while (cmaxh.top().second <= i) cmaxh.pop();
		if (h[i]+H >= cmaxh.top()) leap[e] = true;
	}
	
	vector< pair<ll, ll> > dp(N, -1);	//message, followers
	dp[0] = 0;
	for (int i=1; i<N; i++) {
		if (h[i] >= h[i-1]) dp[i] = {dp[i-1].first+dp[i-1].second+f[i], dp[i-1].second+f[i]};
		if (leap[i]) dp[i] = 
	}
	
	return 0;
}