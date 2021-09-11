#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF INT_MAX

int main() {
	int N, K, f, r, c, vert, x;
	cin >> N >> K;
	vector<vi> data(2, vi(N));
	
	for (int i=0; i<N; i++) cin >> data[0][i];
	for (int i=0; i<N; i++) cin >> data[1][i];
	
	vector< vector<vi> > dist(2, vector<vi>(N, vi(2, -INF)));
	dist[0][0][0] = data[0][0];
	dist[1][0][0] = data[1][0];
	
	priority_queue< pair<ii, ii> > q;
	q.push({{data[0][0], 0}, {0, 0}});
	q.push({{data[1][0], 0}, {1, 0}});
	
	while (!q.empty()) {
		f = q.top().first.first;
		vert = q.top().first.second;
		r = q.top().second.first;
		c = q.top().second.second;
		q.pop();
		
		//cout << f << " " << vert << " " << r << " " << c << endl;
		
		for (int i=0; i<=K; i++) {
			if (c+i >= N) break;
			if (i == 0 && vert) continue;
			x = f+data[(r+1)%2][c+i];
			if (x > dist[(r+1)%2][c+i][(i?0:1)]) {
				//cout << "test: " << x << " " << (r+1)%2 << " " << c+i << " " << (i?0:1) << endl;
				dist[(r+1)%2][c+i][(i?0:1)] = x;
				q.push({{x, (i?0:1)}, {(r+1)%2, c+i}});
			}
		}
	}
	
	cout << max(dist[0][N-1][1], dist[1][N-1][1]) << "\n";
	
	/*for (auto i : dist) {
		for (auto j : i) {
			for (auto k : j) cout << k << " ";
			cout << endl;
		}
		cout << endl;
	}*/
	
	return 0;
}