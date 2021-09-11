#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int> &parent) {
	if (parent.at(x) == x) return x;
	else return parent.at(x) = find(parent.at(x), parent);
}

void merge(int x, int y, vector<int> &parent, vector<int> &size) {
	x = find(x, parent);
	y = find(y, parent);
	if (x == y) return;
	if (size.at(x) < size.at(y)) swap(x, y);
	parent.at(y) = x;
	size.at(x) += size.at(y);
}

int main() {
	int N, M, a, b;
	cin >> N >> M;
	
	vector<int> fighters(N);
	vector<int> size(N, 1);
	iota(fighters.begin(), fighters.end(), 0);
	vector< vector<int> > adj(N);
	
	bool done = false;
	
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		if (!done) {
			a--;
			b--;
			if (!adj.at(a).empty()) merge(b, adj.at(a).at(0), fighters, size);
			if (!adj.at(b).empty()) merge(a, adj.at(b).at(0), fighters, size);
			if (find(a, fighters) == find(b, fighters)) {
				cout << i+1;
				done = true;
			}
			adj.at(a).push_back(b);
			adj.at(b).push_back(a);
		}
	}
	
	return 0;
}