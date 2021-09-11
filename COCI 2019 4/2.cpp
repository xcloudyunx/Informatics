#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector< vector<int> > adj(N);
	vector<bool> possible(N, false);
	
	for (int i=0; i<M; i++) {
		int x, y;
		cin >> x >> y;
		adj.at(y-1).push_back(x-1);
	}
	
	queue<int> q;
	q.push(0);
	bool any = false;
	
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		
		for (int i=0; i<adj.at(f).size(); i++) {
			if (!possible.at(adj.at(f).at(i))) {
				any = true;
				possible.at(adj.at(f).at(i)) = true;
				q.push(adj.at(f).at(i));
			}
		}
	}
	
	for (int i=0; i<N; i++) {
		if (!any && i == 0) {
			cout << 1;
			continue;
		}
		if (possible.at(i)) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	
	cout << endl;

	return 0;
}