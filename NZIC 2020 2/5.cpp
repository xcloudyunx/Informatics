#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int M, R, C, T, A;
	cin >> M >> R;
	vii mince(M, {0, 0});
	for (int i=0; i<M; i++) cin >> mince[i].first;
	
	vector< vii > rafts(R);
	for (int i=0; i<R; i++) {
		cin >> C;
		for (int j=0; j<C; j++) {
			cin >> T >> A;
			rafts[i].push_back({T, A});
		}
	}
	
	priority_queue<ii> q;
	q.push({M+R, 1});
	while (!q.empty()) {
		T = q.top().first;
		A = q.top().second;
		q.pop();
		if (T <= M) mince[T-1].second += A;
		else {
			T -= M;
			for (auto i : rafts[T-1]) {
				q.push({i.first, A*i.second});
			}
		}
	}
	
	int limit = INF;
	for (auto i : mince) {
		if (i.second != 0) limit = min(limit, i.first/i.second);
	}
	
	cout << limit << "\n";
	
	return 0;
}