#include <bits/stdc++.h>

using namespace std;

int next_power_of_two(int value) {
	return 1 << (32 - __builtin_clz(value-1));
}

struct SegmentTree {
	int size;
	vector< tuple<int, int, int> > nodes;
	vector<int> values;
	
	SegmentTree(vector<int> v) : size(2*next_power_of_two(values.size())), nodes(size, make_tuple(0, 0, 0)) {
		values = v;
		construct(0, 0, values.size());
	}
	
	tuple<int, int, int> construct(int node, int cleft, int cright) {
		if (cleft+1 == cright) {
			if (values.at(cleft) != 0) {
				return nodes.at(node) = make_tuple(1, 1, 1);
			} else {
				return nodes.at(node);
			}
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
		
	}
};

int main() {
	int N, L;
	cin >> N >> L;
	
	
	
	return 0;
}