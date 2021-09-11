#include <bits/stdc++.h>

using namespace std;

int next_power_of_two(int value) {
	return 1 << (32 - __builtin_clz(value-1));
}

struct SegmentTree {
	int size;
	vector< tuple<int, int, int> > nodes;
	
	SegmentTree(int s) : size(2*next_power_of_two(s)), nodes(size, make_tuple(0, 0, 0)) {
		construct(0, 0, s);
	}
	
	tuple<int, int, int> construct(int node, int cleft, int cright) {
		if (cleft+1 == cright) {
			return nodes.at(node);
		}
		
		int mid = (cleft+cright)/2;
		auto x = construct(node*2+1, cleft, mid);
		auto y = construct(node*2+2, mid, cright);
		
		nodes.at(node) = make_tuple(get<0>(x), max(max(get<1>(x), get<1>(y)), get<2>(x)+get<0>(y)), get<2>(y));
		if (get<0>(x) == mid-cleft) {
			get<0>(nodes.at(node)) += get<0>(y);
		}
		if (get<2>(y) == cright-mid) {
			get<2>(nodes.at(node)) += get<2>(x);
		}
		return nodes.at(node);
	}
	
	int query() {
		return max(max(get<0>(nodes.at(0)), get<1>(nodes.at(0))), get<2>(nodes.at(2)));
	}
	
	void update(int node, int cleft, int cright, int target, int delta) {
		if (target < cleft || target >= cright) return;
		if (cleft == target && cright == target+1) {
			//cout << node << " " << cleft << " " << cright << endl;
			if (delta == 1) {
				nodes.at(node) = make_tuple(1, 1, 1);
			} else {
				nodes.at(node) = make_tuple(0, 0, 0);
			}
		}
		else {
			int mid = (cleft+cright)/2;
			update(node*2+1, cleft, mid, target, delta);
			update(node*2+2, mid, cright, target, delta);
			
			auto x = nodes.at(node*2+1);
			auto y = nodes.at(node*2+2);
			
			nodes.at(node) = make_tuple(get<0>(x), max(max(get<1>(x), get<1>(y)), get<2>(x)+get<0>(y)), get<2>(y));
			if (get<0>(x) == mid-cleft) {
				get<0>(nodes.at(node)) += get<0>(y);
			}
			if (get<2>(y) == cright-mid) {
				get<2>(nodes.at(node)) += get<2>(x);
			}
		}
	}
};

int main() {
	int N, L;
	cin >> N >> L;
	
	SegmentTree s(N);
	priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > q;
	
	for (int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;
		q.push(make_tuple(a, 1, i));
		q.push(make_tuple(b, 0, i));
	}
	
	int cmax = 0;
	
	while (!q.empty()) {
		int t = get<0>(q.top());
		int p = get<1>(q.top());
		int m = get<2>(q.top());
		q.pop();
		
		s.update(0, 0, N, m, p);
		/*for (auto i : s.nodes) {
			cout << "(" << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << "), ";
		}
		cout << endl;*/
		cmax = max(cmax, s.query());
	}
	
	cout << cmax << endl;
	
	return 0;
}