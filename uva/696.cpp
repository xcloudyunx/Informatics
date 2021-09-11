#include <bits/stdc++.h>

using namespace std;

int main() {
	int M, N, total;
	cin >> M >> N;
	while (M || N) {
		if (M == 0 || N == 0) {
			total = 0;
		} else if (M == 1 || N == 1) {
			total = max(M, N);
		} else if (M == 2 || N == 2) {
			total = (max(M, N)/4)*4 + (min(2, max(M, N)%4))*2;
		} else {
			total = ceil(M/2.0f)*ceil(N/2.0f) + (M/2)*(N/2);
		}
		cout << total << " knights may be placed on a " << M << " row " << N << " column board.\n";
		cin >> M >> N;
	}
	
	return 0;
}