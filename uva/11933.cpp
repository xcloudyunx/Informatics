#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, c;
	cin >> n;
	
	while (n) {
		x = n;
		c = 0;
		vector<int> ab(2, 0);
		
		while (x) {
			x &= x-1;
			ab.at(c) += n-x;
			n = x;
			c = (c+1)%2;
		}
		
		cout << ab.at(0) << " " << ab.at(1) << "\n";
		cin >> n;
	}
	
	return 0;
}