#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector< vector<int> > adj(N);
	vector<int> parents(N+M, 0);
	vector<double> water(N+M);
	
	for (int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj.at(i).push_back(a);
		adj.at(i).push_back(b);
		parents.at(a)++;
		parents.at(b)++;
	}
	
	queue<int> q;
	q.push(0);
	water.at(0) = 1.0f;
	
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		double half = water.at(f)/adj.at(f).size();
		
		for (auto i : adj.at(f)) {
			water.at(i) += half;
			parents.at(i)--;
			if (parents.at(i) == 0 && i<N) {
				q.push(i);
			}
		}
	}
	
	for (int i=N; i<N+M; i++) {
		cin.precision(8);
		cout << fixed << water.at(i) << endl;
	}
}