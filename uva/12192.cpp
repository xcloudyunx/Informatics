#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, M, Q, L, U, cmax, x;
	cin >> N >> M;
	while (N && M) {
		vector<vi> H(N+M-1);
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> x;
				H[i+M-j-1].push_back(x);
			}
		}
		cin >> Q;
		while (Q--) {
			cin >> L >> U;
			cmax = 0;
			for (auto i : H) {
				if (cmax >= i.size()) continue;
				cmax = max(cmax, (int)(upper_bound(i.begin(), i.end(), U)-lower_bound(i.begin(), i.end(), L)));
			}
			cout << cmax << "\n";
		}
		cout << "-\n";
		cin >> N >> M;
	}
	
	return 0;
}
