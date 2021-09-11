#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, start, end, val;
	float cmin;
	cin >> N;
	for (int TC=1; N; TC++) {
		vii co(N);
		for (int i=0; i<N; i++) cin >> co[i].first >> co[i].second;
		vector< vector<float> > d(N, vector<float>(N, 0));
		for (int i=0; i<N; i++) {
			for (int j=i+1; j<N; j++) {
				d[i][j] = sqrt(pow(co[i].first-co[j].first, 2.0) + pow(co[i].second-co[j].second, 2.0))+16;
				d[j][i] = d[i][j];
			}
		}
		
		vector< vector< pair<float, int> > > dp((1<<N), vector< pair<float, int> >(N, {INF, -1}));
		for (int i=0; i<N; i++) dp[((1<<N)-1)^(1<<i)][i].first = 0;
		
		for (int i=(1<<N)-1; i>0; i--) {
			for (int j=0; j<N; j++) {
				if (i & (1<<j)) continue;
				for (int k=0; k<N; k++) {
					if (i & (1<<k)) {
						if (dp[i][j].first+d[j][k] < dp[i^(1<<k)][k].first) {
							dp[i^(1<<k)][k] = {dp[i][j].first+d[j][k], j};
						}
					}
				}
			}
		}
		
		cmin = INF;
		for (int i=0; i<N; i++) {
			if (dp[0][i].first < cmin) {
				cmin = dp[0][i].first;
				start = i;
			}
		}
		val = 0;
		end = dp[val][start].second;
		printf("**********************************************************\n");
		printf("Network #%d\n", TC);
		for (int i=1; i<N; i++) {
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", co[start].first, co[start].second, co[end].first, co[end].second, d[start][end]);
			val ^= (1<<start);
			start = end;
			end = dp[val][start].second;
		}
		printf("Number of feet of cable required is %.2f.\n", cmin);
		
		cin >> N;
	}
	
	
	return 0;
}