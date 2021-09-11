#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, x, y, total;
	ii a, b;
	cin >> N >> K;
	queue<ii> driver;
	vi see(K);
	for (int i=1; i<=N; i++) { cin >> x; driver.push({i, x}); }
	for (int i=0; i<K; i++) cin >> see[i];
	sort(see.begin(), see.end());
	vector< vector<bool> > adj(K, vi(K, false));
	x = 0;
	while (!q.empty()) {
		a = driver.front();
		driver.pop();
		b = driver.front();
		driver.pop();
		while (see[x] < a.first) {
			x++;
			if (x == K) x = 0;
		}
		y = x+1;
		while (see[y] < b.first) {
			y++;
			if (y == K) y = 0;
		}
		if (see[x] == a.first && see[y] == b.first) {
			adj[x][y] = true;
			adj[y][x] = true;
		}
		if (a.second > b.second) driver.push(a);
		else driver.push(b);
	}
	
	vector<bool> seen(K, false);
	total = K;
	for (int i=0; i<K; i++) {
		
	}
	
	return 0;
}