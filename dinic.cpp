#include<bits/stdc++.h>

using namespace std;

struct Edge {
	int v;
	int flow;
	int C;
	int rev;
};

bool bfs(int N, int t, int s, vector<int> &level, vector< vector<Edge> > &adj) {
	level.assign(N, -1);
	level.at(t) = 0;
	
	queue<int> q;
	q.push(t);
	
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (auto i : adj.at(f)) {
			if (level.at(i.v) < 0 && i.flow < i.C) {
				level.at(i.v) = level.at(f)+1;
				q.push(i.v);
			}
		}
	}
	
	return level.at(s) < 0 ? false : true;
}

int sendFlow(int c, int flow, int s, vector<int> &level, vector< vector<Edge> > &adj) {
	if (c == s) return flow;
	
	for (auto &i : adj.at(c)) {
		if (level.at(i.v) == level.at(c)+1 && i.flow < i.C) {
			int cflow = min(flow, i.C-i.flow);
			
			int tmp = sendFlow(i.v, cflow, s, level, adj);
			if (tmp > 0) {
				i.flow += tmp;
				
				adj.at(i.v).at(i.rev).flow -= tmp;
				return tmp;
			}
		}
	}
	
	return 0;
}

int main() {
	int N, E;
	cin >> N >> E;
	vector< vector<Edge> > adj(N);
	vector<int> level(N);
	
	for (int i=0; i<E; i++) {
		int a, b, c; //start, end, capacity
		cin >> a >> b >> c;
		adj.at(a).push_back({b, 0, c, adj.at(b).size()});
		adj.at(b).push_back({a, 0, 0, adj.at(a).size()-1});
	}
	
	int t, s; //tap, sink
	cin >> t >> s;
	
	int total = 0;
	
	while (bfs(N, t, s, level, adj)) {
		while (int flow = sendFlow(t, INT_MAX, s, level, adj)) {
			total += flow;
		}
	}
	
	cout << total << endl;
	
	return 0;
}