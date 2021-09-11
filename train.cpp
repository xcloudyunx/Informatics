#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> parent;
	vector<int> size;
	
	DSU(int n) : parent(n), size(n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}
	
	int find(int x) {
		if (parent.at(x) == x) return x;
		else return parent.at(x) = find(parent.at(x));
	}
	
	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		if (size.at(x) < size.at(y)) swap(x, y);
		parent.at(y) = x;
		size.at(x) += size.at(y);
		return true;
	}
};

int main() {
	int N;
	cin >> N;
	
	priority_queue< tuple<int, int, int> > hor; //x, y, track
	priority_queue< tuple<int, int, int, int> > ver; //x, y1, y2, track
	
	for (int i=0; i<N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 == y2) {
			hor.push(make_tuple(x1, y1, i));
			hor.push(make_tuple(x2, y1, i));
		} else {
			ver.push(make_tuple(x1, min(y1, y2), max(y1, y2), i));
		}
	}
	
	unordered_map<int, int> currentX; //y, track
	priority_queue< pair< int, pair<int, int> >, vector< pair< int, pair<int, int> > >, greater< pair< int, pair<int, int> > > > q; //profit, track1, track2
	int total = 0;
	
	vector<int> tmp;
	int tx = 100001;
	
	while (!ver.empty()) {
		int vfx = get<0>(ver.top());
		int vfy1 = get<1>(ver.top());
		int vfy2 = get<2>(ver.top());
		int vft = get<3>(ver.top());
		ver.pop();
		
		if (!tmp.empty() && tx != vfx) {
			for (auto i : tmp) {
				currentX.erase(currentX.find(i));
			}
			tmp.clear();
		}
		
		while (!hor.empty() && get<0>(hor.top()) >= vfx) {
			auto s = currentX.find(get<1>(hor.top()));
			if (s != currentX.end()) {
				if (get<0>(hor.top()) == vfx) {
					tmp.push_back(get<1>(hor.top()));
					tx = vfx;
				} else {
					currentX.erase(s);
				}
			} else {
				currentX.insert(make_pair(get<1>(hor.top()), get<2>(hor.top())));
			}
			hor.pop();
		}
		
		for (auto i : currentX) {
			if (vfy1 <= i.first && i.first <= vfy2) {
				int a = abs(vfx)+abs(i.first);
				q.push(make_pair(a, make_pair(vft, i.second)));
				total += a;
			}
		}
	}
	
	DSU forest(N);
	
	while (!q.empty()) {
		auto f = q.top();
		q.pop();
		if (forest.merge(f.second.first, f.second.second)) {
			total -= f.first;
		}
	}
	
	cout << total << endl;
	
	return 0;
}