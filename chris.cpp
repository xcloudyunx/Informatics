#include <bits/stdc++.h>

using namespace std;

int next_power_of_two(int value) {
	return 1 << (32 - __builtin_clz(value-1));
}

struct SegmentTree {
	int size;
	vector< pair<int, int> > nodes;
	vector<int> lazy;
	vector<int> numbers;
	
	SegmentTree(vector<int> n) : size(2*next_power_of_two(n.size())), nodes(size, {INT_MAX, INT_MAX}), lazy(size, 0) {
		numbers = n;
		construct(0, 0, numbers.size());
	}
	
	pair<int, int> construct(int node, int left, int right) {
		if (left+1 == right) return nodes.at(node) = {numbers.at(left), INT_MAX};
		
		int middle = (left+right)/2;
		auto x = construct(node*2+1, left, middle);
		auto y = construct(node*2+2, middle, right);
		if (y.first < x.first) swap(x, y);
		return nodes.at(node) = {x.first, min(x.second, y.first)};
	}
	
	pair<int, int> query(int node, int cleft, int cright, int left, int right) {
		if (right <= cleft || left >= cright) return {INT_MAX, INT_MAX};
		
		if (lazy.at(node) != 0) {
			nodes.at(node).first += lazy.at(node);
			
			if (cleft+1 != cright) {
				nodes.at(node).second += lazy.at(node);
				lazy.at(node*2+1) += lazy.at(node);
				lazy.at(node*2+2) += lazy.at(node);
			}
			
			lazy.at(node) = 0;
		}
		
		if (cright <= right && cleft >= left) return nodes.at(node);
		
		int mid = (cleft+cright)/2;
		auto x = query(node*2+1, cleft, mid, left, right);
		auto y = query(node*2+2, mid, cright, left, right);
		
		if (y.first < x.first) swap(x, y);
		return {x.first, min(x.second, y.first)};
	}
	
	void update(int node, int cleft, int cright, int left, int right, int delta) {
		if (lazy.at(node) != 0) {
			nodes.at(node).first += lazy.at(node);
			
			if (cleft+1 != cright) {
				nodes.at(node).second += lazy.at(node);
				lazy.at(node*2+1) += lazy.at(node);
				lazy.at(node*2+2) += lazy.at(node);
			}
			
			lazy.at(node) = 0;
		}
		
		if (right <= cleft || left >= cright) return;
		if (cleft >= left && cright <= right) {
			nodes.at(node).first += delta;
			
			if (cleft+1 != cright) {
				nodes.at(node).second += delta;
				lazy.at(node*2+1) += delta;
				lazy.at(node*2+2) += delta;
			}
			return;
		}
		
		int mid = (cleft+cright)/2;
		update(node*2+1, cleft, mid, left, right, delta);
		update(node*2+2, mid, cright, left, right, delta);
		auto x = nodes.at(node*2+1);
		auto y = nodes.at(node*2+2);
		if (y.first < x.first) swap(x, y);
		nodes.at(node) = {x.first, min(x.second, y.first)};
	}
};

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> numbers(N);
	
	for (int i=0; i<N; i++) {
		cin >> numbers.at(i);
	}
	
	SegmentTree s(numbers);
	
	for (int i=0; i<K; i++) {
		char task;
		cin >> task;
		if (task == 'Q') {
			int a, b;
			cin >> a >> b;
			auto x = s.query(0, 0, N, a, b+1);
			cout << x.first << " " << x.second << endl;
			/*for (auto j : s.nodes) {
				cout << j.first << " ";
			}
			cout << endl;
			for (auto j : s.lazy) {
				cout << j << " ";
			}
			cout << endl;*/
		} else {
			int a, b, c;
			cin >> a >> b >> c;
			s.update(0, 0, N, a, b+1, c);
			/*for (auto j : s.nodes) {
				cout << j.first << " ";
			}
			cout << endl;
			for (auto j : s.lazy) {
				cout << j << " ";
			}
			cout << endl;*/
		}
	}
	
	return 0;
}