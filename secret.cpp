#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> v(54, false);
int size;

void dfs(vector<vector<int>> adj, int i) {
	if (!v.at(i)) {
		size++;
		v.at(i) = true;
		for (auto j=adj.at(i).begin(); j!= adj.at(i).end(); j++) {
			dfs(adj, *j);
		}
	}
}

int main() {
	int nodes = 54;
	vector<vector<int>> adj(nodes);
	
	int a, b;
	while (cin >> a >> b) {
		adj.at(a).push_back(b);
		adj.at(b).push_back(a);
	}
	
	for (int i=0; i<nodes; i++) {
		size = 0;
		dfs(adj, i);
		if (size > 0) {
			cout << size << endl;
		}
	}
	
	return 0;
}