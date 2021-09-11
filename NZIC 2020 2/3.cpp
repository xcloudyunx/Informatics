#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, x;
	cin >> N;
	int T = 0;
	for (int i=0; i<N; i++) {
		cin >> x;
		T += x;
	}
	
	int h = T/60;
	int m = T%60;
	
	cout << "It took ";
	if (h) cout << h << " hour";
	if (h > 1) cout << "s";
	if (h && m) cout << " and ";
	if (m) cout << m << " minute";
	if (m > 1) cout << "s";
	cout << "\n";
	
	return 0;
}