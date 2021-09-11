#include <bits/stdc++.h>

using namespace std;

int main() {
	int SZ, width, x, y, dx, dy, cw;
	long long P, n;
	cin >> SZ >> P;
	
	while (SZ || P) {
		if (P == 1) {
			cout << "Line = " << SZ/2+1 << ", column = " << SZ/2+1 << ".\n";
		} else {
			n = 1;
			while (n*n < P) {
				n += 2;
			}
			width = n;
			n -= 2;
			n *= n;
			n++;
			x = SZ/2 + width/2;
			y = x+1;
			dx = -1;
			dy = 0;
			cw = 2;
			while (n < P) {
				x += dx;
				y += dy;
				n++;
				cw++;
				if (cw == width) {
					cw = 1;
					if (dx == -1) {
						dy = -1;
						dx = 0;
					} else if (dy == -1) {
						dx = 1;
						dy = 0;
					} else if (dx == 1) {
						dy = 1;
						dx = 0;
					}
				}
			}
			cout << "Line = " << y << ", column = " << x << ".\n";
		}
		
		cin >> SZ >> P;
	}
	
	return 0;
}