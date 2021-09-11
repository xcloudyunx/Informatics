#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int> &parent) {
	if (parent.at(x) == x) return x;
	else return parent.at(x) = find(parent.at(x), parent);
}

bool merge(int x, int y, vector<int> &parent, vector<int> &size) {
	x = find(x, parent);
	y = find(y, parent);
	if (x == y) return false;
	if (size.at(x) < size.at(y)) swap(x, y);
	parent.at(y) = x;
	size.at(x) += size.at(y);
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> country(N);
	
	vector<bool> v(N+1, false);
	queue< pair<int, int> > pairs;
	
	for (int i=0; i<N; i++) {
		cin >> country.at(i);
		if (!v.at(country.at(i))) {
			pairs.push(make_pair(0, i));
			v.at(country.at(i)) = true;
		}
	}
	
	vector< vector< pair<int, int> > > adj(N);
	
	int total = 0;
	
	priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > qu;
	
	for (int i=0; i<M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj.at(a).push_back(make_pair(c, b));
		adj.at(b).push_back(make_pair(c, a));
		total += c;
		qu.push(make_pair(c, make_pair(a, b)));
	}
	
	vector<int> forest(N);
	iota(forest.begin(), forest.end(), 0);
	vector<int> size(N, 1);
	
	int distance = 0;
	
	while (!pairs.empty()) {
		priority_queue< pair< pair<int, int>, int >, vector< pair< pair<int, int>, int > >, greater< pair< pair<int, int>, int > > > q;
		v.assign(N, false);
		q.push(make_pair(pairs.front(), pairs.front().second));
		pairs.pop();
		
		while (!q.empty()) {
			int w = q.top().first.first;
			int f = q.top().first.second;
			int b = q.top().second;
			q.pop();
			
			if (!v.at(f)) {
				v.at(f) = true;
				distance += w;
				merge(f, b, forest, size);
				for (auto i : adj.at(f)) {
					if (country.at(f) == country.at(i.second) && !v.at(i.second)) {
						q.push(make_pair(i, f));
					}
				}
			}
		}
	}
	
	while (!qu.empty()) {
		int w = qu.top().first;
		int f = qu.top().second.first;
		int b = qu.top().second.second;
		qu.pop();
		if (merge(f, b, forest, size)) {
			distance += w;
		}
	}
	
	cout << total-distance << endl;
	
	return 0;
}