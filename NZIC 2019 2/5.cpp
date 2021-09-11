#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	
	vector<int> heights(N);
	
	for (int i=0; i<N; i++) {
		cin >> heights.at(i);
	}
	
	sort(heights.rbegin(), heights.rend());
	
	int total = 0;
	
	int j = 0;
	for (int i=T; i>0; i--) {
		if (heights.at(j) >= i) {
			total++;
			j++;
			if (j == N) break;
		}
	}
	
	cout << total << endl;
	
	return 0;
}