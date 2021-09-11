#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	double total = 0;
	
	if (N == K) {
		for (int i=N; i>0; i--) {
			total += 1.0f/i;
		}
	} else {
	}
	
	cout.precision(9);
	cout << fixed << total << endl;
	
	return 0;
}