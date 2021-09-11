#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int A, B, C;
	vector< tuple<int, int, int> > trades(N);
	
	for (int i=0; i<N; i++) {
		cin >> A >> B >> C;
		trades.at(i) = make_tuple(A-1, B-1, C);
	}
	
	vector<int> maximum(K, 0);
	int cmax = 0;
	
	for (int i=N-1; i>=0; i--) {
		A = get<0>(trades.at(i));
		B = get<1>(trades.at(i));
		C = get<2>(trades.at(i));
		
		maximum.at(A) = max(maximum.at(A), maximum.at(B)+C);
		cmax = max(maximum.at(A), cmax);
	}
	
	int total = 0;
	
	for (auto i : maximum) {
		if (i == cmax) {
			total++;
		}
	}
	
	cout << cmax << endl << total << endl;
	
	return 0;
}