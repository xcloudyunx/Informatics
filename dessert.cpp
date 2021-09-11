#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	long long B = 0;
	
	vector<int> p(N);
	for (int i=0; i<N; i++) {
		cin >> p.at(i);
		B += p.at(i);
	}
	
	int x = N-1;
	int y = N;
	B -= p.at(x);
	long long J = p.at(x);
	while (B != J) {
		if (B > J) {
			if (x == 0) {
				cout << 0 << endl;
				return 0;
			}
			x--;
			B -= p.at(x);
			J += p.at(x);
		} else if (B < J) {
			if (y <= x) {
				cout << 0 << endl;
				return 0;
			}
			y--;
			J -= p.at(y);
		}
	}
	
	cout << B << endl;
	
	return 0;
}