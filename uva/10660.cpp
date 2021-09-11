#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int t, n, r, c, v, ax, ay, bx, by, cx, cy, dx, dy, ex, ey, total, cmin;
	bool broken;
	vi output(5);
	cin >> t;
	while (t--) {
		vector<vi> grid(5, vi(5, 0));
		cin >> n;
		while (n--) {
			cin >> r >> c >> v;
			grid[r][c] = v;
		}
		
		cmin = INF;
		for (int a=0; a<21; a++) {
			ax = a/5, ay = a%5;
			for (int b=a+1; b<22; b++) {
				bx = b/5, by = b%5;
				for (int c=b+1; c<23; c++) {
					cx = c/5, cy = c%5;
					for (int d=c+1; d<24; d++) {
						dx = d/5, dy = d%5;
						for (int e=d+1; e<25; e++) {
							ex = e/5, ey = e%5;
							
							total = 0;
							broken = false;
							for (int i=0; i<5; i++) {
								for (int j=0; j<5; j++) {
									total += grid[i][j]*min({abs(ax-i)+abs(ay-j), abs(bx-i)+abs(by-j), abs(cx-i)+abs(cy-j), abs(dx-i)+abs(dy-j), abs(ex-i)+abs(ey-j)});
									if (total >= cmin) { broken = true; break; }
								}
								if (broken) break;
							}
							if (total < cmin) {
								cmin = total;
								output = {a, b, c, d, e};
							}
						}
					}
				}
			}
		}
		for (int i=0; i<5; i++) {
			if (i) cout << " ";
			cout << output[i];
		}
		cout << "\n";
	}
	
	return 0;
}