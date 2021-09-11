#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, x, total;
	cin >> N >> M;
	
	while (N || M) {
		unordered_set<int> cd;
		total = 0;
		
		while (N--) {
			cin >> x;
			cd.insert(x);
		}
		while (M--) {
			cin >> x;
			if (cd.find(x) != cd.end()) {
				total++;
			}
		}
		
		cout << total << "\n";
		
		cin >> N >> M;
	}
	
	return 0;
}