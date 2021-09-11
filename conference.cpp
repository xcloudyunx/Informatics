#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> cities(K);
	
	for (int i=0; i<K; i++) {
		cin >> cities.at(i);
		cities.at(i)--;
	}
	
	vector< vector<int> > adj(N);
	
	for (int i=0; i<N-1; i++) {
		int A, B;
		cin >> A >> B;
		A--;
		B--;
		adj.at(A).push_back(B);
		adj.at(B).push_back(A);
	}
	
	if (K == 2) {
		vector<int> distance(N, INT_MAX);
		
		priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
		q.push(make_pair(0, cities.front()));
		distance.at(cities.front()) = 0;
		
		while (!q.empty()) {
			int w = q.top().first;
			int f = q.top().second;
			q.pop();
			
			for (auto i : adj.at(f)) {
				if (w+1 < distance.at(i)) {
					distance.at(i) = w+1;
					q.push(make_pair(w+1, i));
				}
			}
		}
		
		cout << distance.at(cities.back()) << endl;
	} else {
		int centre = cities.at(K/2);
		int distance = 0;
		for (auto i : cities) {
			distance += abs(centre-i);
		}
		cout << distance << endl;
	}
	
	return 0;
}