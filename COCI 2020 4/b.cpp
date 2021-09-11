#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, x;
	cin >> N >> K;
	if (K != 0) {
		vi h(N);
		vi seen(1000001, -1);
		for (int i=0; i<N; i++) {
			cin >> h[i];
		}
		for (int i=0; i<N; i++) {
			if (i) cout << " ";
			if (seen[h[i]] == -1) {
				seen[h[i]] = 0;
				for (int j=0; j<N; j++) {
					if (j == i) continue;
					if (h[i]%h[j] == K) seen[h[i]]++;
				}
			}
			cout << seen[h[i]];
		}
	} else {
		vi h(N);
		vi multiple(1000001, 0);
		for (int i=0; i<N; i++) {
			cin >> x;
			if (x >= K) {
				for (int j=0; x*j<=1000000; j++) {
					multiple[x*j]++;
				}
			}
			h[i] = x-K;
		}
		for (int i=0; i<N; i++) {
			if (i) cout << " ";
			if (h[i] >= 0 && multiple[h[i]] != 0) cout << multiple[h[i]]-1;
			else cout << 0;
		}
	}
	
	return 0;
}