#include <bits/stdc++.h>

using namespace std;

int p2(int value) {
	return 1 << (32-__builtin_clz(value-1));
}

struct SegmentTree {
	int size;
	vector<int> nodes;
	vector<int> values;
	int z;
	
	SegmentTree(vector<int> v): size(2*p2(v.size())), nodes(size, 0) {
		values = v;
		construct(0, 0, values.size());
		z = values.front();
	}
	
	int construct(int node, int cleft, int cright) {
		if (cleft+1 == cright) return nodes.at(node) = values.at(cleft);
		int mid = (cleft+cright)/2;
		return nodes.at(node) = max(construct(node*2+1, cleft, mid), construct(node*2+2, mid, cright));
	}
	
	int query(int node, int cleft, int cright, int target) {
		if (target < cleft || target >= cright) return 0;
		if (cleft == target && cright == target+1) return 0;
		int mid = (cleft+cright)/2;
		int x = query(node*2+1, cleft, mid, target);
		int y = query(node*2+2, mid, cright, target);
		if (nodes.at(node) == z) return max(x, y)+1;
		else return max(x, y);
	}
	
	void update(int node, int cleft, int cright, int target, int value) {
		if (target < cleft || target >= cright) return;
		if (cleft == target && cright == target+1) nodes.at(node) = value;
		else {
			int mid = (cleft+cright)/2;
			update(node*2+1, cleft, mid, target, value);
			update(node*2+2, mid, cright, target, value);
			nodes.at(node) = max(nodes.at(node*2+1), nodes.at(node*2+2));
		}
	}
};

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> skills(N);
	
	for (int i=0; i<N; i++) {
		cin >> skills.at(i);
	}
	
	SegmentTree s(skills);
	
	int wins = s.query(0, 0, N, 0);
	
	int total = -1;
	
	for (int i=0; i<N; i++) {
		int j = i+1;
		if (i%2 == 0) j++;
		for (; j<N; j++) {
			SegmentTree copy = s;
			copy.update(0, 0, N, i, skills.at(j));	
			copy.update(0, 0, N, j, skills.at(i));
			int w;
			if (i == 0) w = copy.query(0, 0, N, j);
			else w = copy.query(0, 0, N, 0);
			if (w > wins) {
				total = 1;
				wins = w;
			} else if (w == wins && total != -1) {
				total++;
			}
		}
	}
	
	cout << wins << "\n" << total;
	
	return 0;
}