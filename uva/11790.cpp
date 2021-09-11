#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, N, maxi, maxd, cmax;
	cin >> T;
	for (int TC=1; TC<=T; TC++) {
		cin >> N;
		vi H(N);
		vi W(N);
		vi LIS(N);
		vi LDS(N);
		maxi = 0, maxd = 0;
		for (int i=0; i<N; i++) cin >> H[i];
		for (int i=0; i<N; i++) cin >> W[i];
		for (int i=0; i<N; i++) {
			cmax = 0;
			for (int j=0; j<i; j++) { if (H[i] > H[j]) cmax = max(cmax, LIS[j]); }
			LIS[i] = cmax+W[i];
			cmax = 0;
			for (int j=0; j<i; j++) { if (H[i] < H[j]) cmax = max(cmax, LDS[j]); }
			LDS[i] = cmax+W[i];
			maxi = max(maxi, LIS[i]);
			maxd = max(maxd, LDS[i]);
		}
		
		cout << "Case " << TC << ". ";
		if (maxi >= maxd) cout << "Increasing (" << maxi << "). Decreasing (" << maxd << ").\n";
		else cout << "Decreasing (" << maxd << "). Increasing (" << maxi << ").\n";
	}
	
	return 0;
}