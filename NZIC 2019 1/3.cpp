#include <bits/stdc++.h>

using namespace std;

int main() {
	char t;
	int N;
	
	int G, C, E, P, L, S;
	G = C = E = P = L = S = 0;
	
	cin >> t;
	while (t != 'D') {
		cin >> N;
		if (t == 'G') {
			G += N;
		} else if (t == 'C') {
			C += N;
		} else if (t == 'E') {
			E += N;
		} else if (t == 'P') {
			P += N;
		} else if (t == 'L') {
			L += N;
		} else if (t == 'S') {
			S += N;
		}
		
		cin >> t;
	}
	
	cout << G << " " << C << " " << E << " " << P << " " << L << " " << S << endl;
	
	return 0;
}