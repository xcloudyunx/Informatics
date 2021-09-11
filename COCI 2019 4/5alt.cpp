#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	if (N == K) {
		double total = 0;
		for (int i=N; i>0; i--) {
			total += 1.0f/i;
		}
		cout.precision(9);
		cout << fixed << total << endl;
		return 0;
	}
	
	vector< vector<double> > table(2, vector<double> (N+1));
	
	for (int i=1; i<=K; i++) {
		int c = i%2;
		int p = (i-1)%2;
		if (i == K) {
			double cMax = 0;
			for (int k=i-1; k<=N-1; k++) {
				cMax = max(cMax, table.at(p).at(k)+(double)(N-k)/N);
			}
			cout.precision(9);
			cout << fixed << cMax << endl;
		} else {
			for (int j=i; j<=N-K+i; j++) {
				if (i == 1) {
					table.at(c).at(j) = 1;
				} else {
					double cMax = 0;
					for (int k=i-1; k<=j-1; k++) {
						cMax = max(cMax, table.at(p).at(k)+(double)(j-k)/j);
					}
					table.at(c).at(j) = cMax;
				}
			}
			for (auto j : table.at(c)) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}