#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector< pair< pair<int, int>, int > > edges;
	vector< vector<int> > distance(N, vector<int> (N, INT_MAX/2));
	
	for (int z=0; z<K; z++) {
		int i;
		cin >> i;
	}
	
	for (int z=0; z<M; z++) {
		int i, j, L;
		cin >> i >> j >> L;
		edges.push_back({{i-1, j-1}, L});
	}
	
	for (pair< pair<int, int>, int > i : edges) {
		distance.at(i.first.first).at(i.first.second) = i.second;
		distance.at(i.first.second).at(i.first.first) = i.second;
	}
	
	for (int i=0; i<N; i++) {
		distance.at(i).at(i) = 0;
	}
	
	for (int k=1; k<N; k++) {
		for (int i=1; i<N; i++) {
			for (int j=0; j<N; j++) {
				int x = distance.at(i).at(k) + distance.at(k).at(j);
				if (x < distance.at(i).at(j)) {
					distance.at(i).at(j) = x;
					distance.at(j).at(i) = x;
				}
			}
		}
	}
	
	for (auto i : distance) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	
	return 0;
}