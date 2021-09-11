#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
	vector<int> nodes;
	vector<int> values;
	
	SegmentTree(vector<int> v) : values(v.begin(), v.end()), nodes(v.size(), 0) {
		construct(0);
	}
	
	int construct(int node) {
		if (node*2+1 >= values.size()) return nodes.at(node) = values.at(node);
		
		return nodes.at(node) = values.at(node) + construct(node*2+1) + construct(node*2+2);
	}
	
	int query(int node, int cleft, int cright, int left, int right) {
		if (right <= cleft || left >= cright) return 0;
		if (cright <= right && cleft >= left) return nodes.at(node);
		
		int mid = (cleft+cright)/2;
		return query(node*2+1, cleft, mid, left, right) + query(node*2+2, mid, cright, left, right);
	}
};

int main() {
	int N;
	cin >> N;
	
	vector< pair< pair<int, int>, pair<int, int> > > weights(N);
	
	for (int i=0; i<N; i++) {
		cin >> weights.at(i).first.first >> weights.at(i).first.second >> weights.at(i).second.first >> weights.at(i).second.second;
	}
	
	vector<int> val(N);
	
	for (auto i=0; i<N; i++) {
		val.at(i) = weights.at(i).first.first+weights.at(i).second.first;
	}
	
	SegmentTree s(val);
	
	for (auto i : s.nodes) {
		cout << i << " ";
	}
	cout << endl;
	
	int mindif = abs(s.nodes.at(1)+weights.at(0).first.first-s.nodes.at(2)-weights.at(0).second.first);
	cout << mindif << endl;
	
	return 0;
}