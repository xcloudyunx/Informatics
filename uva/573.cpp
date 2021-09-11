#include <bits/stdc++.h>

using namespace std;

int main() {
	int H, D, F, t;
	float U, d, r;
	cin >> H >> U >> D >> F;
	
	while (H) {
		d = 0;
		t = 0;
		r = U*(F/100.0f);
		while (d <= H && d >= 0) {
			t++;
			d += U;
			if (d > H) {
				cout << "success on day " << t << "\n";
				break;
			}
			U = max(0.0f, U-r);
			d -= D;
			if (d < 0) {
				cout << "failure on day " << t << "\n";
				break;
			}
		}
		cin >> H >> U >> D >> F;
	}
	
	return 0;
}