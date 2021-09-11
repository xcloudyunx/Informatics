#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, C, D, S, E, d, x, y, e, t;
	bool broken;
	cin >> N >> C >> D >> S >> E;
	vi v(N+1);
	for (int i=1; i<=N; i++) cin >> v[i];
	vector<vii> ozone(N+1);
	vector<int> s;
	{set<int> tmp;
	tmp.insert(0);
	tmp.insert(D);
	for (int i=0; i<C; i++) {
		cin >> x >> y >> t;
		ozone[x].push_back({y, t});
		tmp.insert(y);
		tmp.insert(t);
	}
	for (auto i : tmp) s.push_back(i);}
	
	vector<vi> distance(N+1, vi(s.size(), INF));
	distance[S][0] = 0;
	priority_queue< pair<int, pair<ii, int> > > q;
	q.push({0, {{S, 0}, 1}});
	while (!q.empty()) {
		d = q.top().first;
		x = q.top().second.first.first;
		y = q.top().second.first.second;
		e = q.top().second.second;
		q.pop();
		
		if (s[y] != D) {
			t = d+v[x]*(s[y+1]-s[y]);
			if (t < distance[x][y+1]) {
				distance[x][y+1] = t;
				q.push({t, {{x, y+1}, 0}});
			}
		}
		
		if (x != 1) {
			broken = false;
			for (auto i : ozone[x-1]) {
				if ((s[y] > i.first || (s[y] == i.first && e == 1)) && (s[y] < i.second || (s[y] == i.second && s[y] == D))) { broken = true; break; }
				if (s[y] == i.second) e = 1;
			}
			if (!broken) {
				if (distance[x][y] < distance[x-1][y]) {
					distance[x-1][y] = distance[x][y];
					q.push({distance[x][y], {{x-1, y}, e}});
				}
			}
		}
		
		if (x != N) {
			broken = false;
			for (auto i : ozone[x]) {
				if ((s[y] > i.first || (s[y] == i.first && e == 1)) && (s[y] < i.second || (s[y] == i.second && s[y] == D))) { broken = true; break; }
				if (s[y] == i.second) e = 1;
			}
			if (!broken) {
				if (distance[x][y] < distance[x+1][y]) {
					distance[x+1][y] = distance[x][y];
					q.push({distance[x][y], {{x+1, y}, e}});
				}
			}
		}
	}
	
	cout << distance[E][D] << "\n";
	
	return 0;
}