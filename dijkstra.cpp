#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector< vector< pair<int, int> > > adj(N); //dest, weight
	vector<int> d(N, INT_MAX);
	
	int a, b;
	cin >> a >> b;
	
	int x, y, w;
	while (N--) {
		cin >> x >> y >> w;
		adj.at(x).push_back(make_pair(y, w));
		adj.at(y).push_back(make_pair(x, w));
	}
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	q.push(make_pair(0, a));
	d.at(a) = 0;
	
	while (!q.empty()) {
		int fw = q.top().first;
		int f = q.top().second;
		q.pop();
		
		for (auto i : adj.at(f)) {
			int z = i.second+fw;
			if (z < d.at(i.first)) {
				d.at(i.first) = z;
				q.push(make_pair(z, i.first));
			}
		}
	}
	
	cout << d.at(b);
	
	return 0;
}