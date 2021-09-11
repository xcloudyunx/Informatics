#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> beauty(n);
	vector< vector<int> > adj(n);
	vector<int> v(n, INT_MAX);
	
	for (int i=0; i<n; i++) {
		cin >> beauty.at(i);
	}
	
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj.at(u).push_back(v);
	}
	
	priority_queue< tuple<int, int, int, int>, vector< tuple<int, int, int, int> >, greater< tuple<int, int, int, int> > > q;
	q.push(make_tuple(0, beauty.at(0), beauty.at(0), 0));
	
	while (!q.empty()) {
		int dif = get<0>(q.top());
		int cmax = get<1>(q.top());
		int cmin = get<2>(q.top());
		int f = get<3>(q.top());
		q.pop();
		
		for (auto i : adj.at(f)) {
			int tcmax = cmax;
			int tcmin = cmin;
			if (beauty.at(i) > tcmax) {
				tcmax = beauty.at(i);
				tcmin = beauty.at(i);
			} else if (tcmax-tcmin != 0) {
				tcmax = max(tcmax, beauty.at(i));
				tcmin = min(tcmin, beauty.at(i));
			} else if (beauty.at(i) < beauty.at(f)) {
				tcmin = beauty.at(i);
			}
			
			int tdif = max(dif, tcmax-tcmin);
			if (tdif < v.at(i)) {
				v.at(i) = tdif;
				q.push(make_tuple(tdif, tcmax, tcmin, i));
			}
		}
	}
	
	cout << v.at(n-1) << endl;
	
	return 0;
}