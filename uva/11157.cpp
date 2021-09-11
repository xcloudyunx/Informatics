#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, N, D, B, ctrue = 0, maxj;
	string tmp;
	char S;
	vector<int> used(103, 0);
	cin >> T;
	for (int TC=1; TC<=T; TC++) {
		cin >> N >> D;
		vector< pair<int, char> > stones(N+2);
		for (int i=1; i<=N; i++) scanf(" %c-%d", &stones[i].second, &stones[i].first);
		stones[0] = {0, 'B'};
		stones[N+1] = {D, 'B'};
		ctrue++;
		maxj = 0;
		for (int i=1; i<=N+1; i++) {
			if (stones[i].second == 'B') maxj = max(maxj, stones[i].first-stones[i-1].first);
			else {
				maxj = max(maxj, stones[i+1].first-stones[i-1].first);
				if (stones[i+1].second == 'S') used[i+1] = ctrue;
				i++;
			}
		}
		for (int i=N; i>=0; i--) {
			if (stones[i].second == 'B') maxj = max(maxj, stones[i+1].first-stones[i].first);
			else {
				while (used[i-1] == ctrue) i--;
				maxj = max(maxj, stones[i+1].first-stones[i-1].first);
				i--;
			}
		}
		cout << "Case " << TC << ": " << maxj << "\n";
	}
	
	return 0;
}