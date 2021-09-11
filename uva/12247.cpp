#include <bits/stdc++.h>

using namespace std;

int mid(int a, int b, int c) {
	int x = a-b;
	int y = b-c;
	int z = c-a;
	
	if (x*y > 0) {
		return b;
	} else if (y*z > 0) {
		return c;
	} else {
		return a;
	}
}

int main() {
	int a, b, c, x, y, count;
	bool broken;
	cin >> a >> b >> c >> x >> y;
	while (a || b || c || x || y) {
		count = 0;
		if (x > a && x > b && x > c) count++;
		if (y > a && y > b && y > c) count++;
		
		if (count == 0) {
			if (min(x, y) > mid(a, b, c)) {
				broken = false;
				for (int i=mid(a, b, c)+1; i<=52; i++) {
					if (i != a && i != b && i != c && i != x && i != y) {
						cout << i << "\n";
						broken = true;
						break;
					}
				}
				if (!broken) {
					cout << -1 << "\n";
				}
			} else {
				cout << -1 << "\n";
			}
			
		} else if (count == 2) {
			broken = false;
			for (int i=1; i<=52; i++) {
				if (i != a && i != b && i != c && i != x && i != y) {
					cout << i << "\n";
					broken = true;
					break;
				}
			}
		} else {
			if (min(x, y) < mid(a, b, c)) {
				broken = false;
				for (int i=max({a, b, c})+1; i<=52; i++) {
					if (i != x && i != y) {
						cout << i << "\n";
						broken = true;
						break;
					}
				}
				if (!broken) {
					cout << -1 << "\n";
				}
			} else {
				broken = false;
				for (int i=mid(a, b, c)+1; i<=52; i++) {
					if (i != a && i != b && i != c && i != x && i != y) {
						cout << i << "\n";
						broken = true;
						break;
					}
				}
				if (!broken) {
					cout << -1 << "\n";
				}
			}
		}
		
		cin >> a >> b >> c >> x >> y;
	}
	
	return 0;
}