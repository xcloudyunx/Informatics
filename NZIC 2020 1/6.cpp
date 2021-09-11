#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int R, N, T, c, f, x, y, a;
	cin >> R >> N >> T;
	vii rockets(R);
	for (int i=0; i<R; i++) cin >> rockets[i].first >> rockets[i].second;
	
	vi shortest(T, INF);
	shortest[0] = 0;
	priority_queue<ii, vii, greater<ii> > q;
	q.push({0, 0});
	while (!q.empty()) {
		c = q.top().first;
		f = q.top().second;
		q.pop();
		for (auto i : rockets) {
			x = c + i.first;
			y = f+i.second; 
			if (y < T && x < shortest[y]) {
				shortest[y] = x;
				q.push({x, y});
			}
			y = abs(f-i.second); 
			if (x < shortest[y]) {
				shortest[y] = x;
				q.push({x, y});
			}
		}
	}
	
	for (int i=0; i<N; i++) {
		cin >> a;
		cout << shortest[a] << "\n";
	}
	
	return 0;
}