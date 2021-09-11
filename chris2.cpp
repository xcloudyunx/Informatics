#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, x=0, y=0, cost, z=9;
	bool broken = false;
	cin >> N;
	vi c(10);
	for (int i=0; i<10; i++) {
		cin >> c[i];
		if (c[i] <= c[y]) {
			x = N/c[i];
			y = i;
		}
	}
	cost = x*c[y];
	
	if (y == 0) {
		for (int i=8; i>0; i--) {
			if (c[i] < c[z]) z = i;
		}
		cost += c[z]-ceil((float)(c[z]-N+cost)/c[y])*c[y];
		x -= ceil((float)(c[z]-N+cost)/c[y]);
		for (int i=9; i>z; i--) {
			if (cost-c[z]+c[i] <= N) {
				cost = cost-c[z]+c[i];
				cout << i;
				broken = true;
				break;
			}
		}
		if (!broken) cout << z;
	}
	
	for (int i=9; i>y; i--) {
		if (cost-c[y]+c[i] <= N) {
			cost = cost-c[y]+c[i];
			cout << i;
			i++; x--;
		}
	}
	while (x--) cout << y;
	
	return 0;
}