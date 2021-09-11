#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, H, v, w, x, y, val;
	bool meet;
	ll cmax = 0;
	cin >> N >> H;
	vii data;
	while (N--) {
		cin >> v >> w;
		if (w != 1) data.push_back({v, w});
	}
	
	vector< pair<ll, int> > dp(data.size());
	dp[0] = {data[0].second, -1};
	for (int i=1; i<data.size(); i++) {
		cmax = 0;
		for (int j=0; j<i; j++) {
			meet = false;
			x = min(data[i].first, data[j].first)/2;
			y = max(data[i].first, data[j].first);
			if (x == y) meet = true;
			else {
				for(; y>=x; y/=2) if (x == y) { meet = true; break; }
			}
			if (meet && dp[j] > cma) cmax = max(cmax, dp[j]);
		}
		dp[i] = cmax+data[i].second;
	}
	
	return 0;
}