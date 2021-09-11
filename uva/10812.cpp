#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	long long s, d, x, y;
	cin >> n;
	
	while (n--) {
		cin >> s >> d;
		if (d <= s) {
			if ((d+s)%2 == 0) {
				x = (d+s)/2;
				y = s-x;
				cout << x << " " << y << "\n";
				continue;
			}
		}
		cout << "impossible\n";
	}
	
	return 0;
}