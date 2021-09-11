#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, A, B, C;
	bool sol;
	cin >> N;
	while (N--) {
		sol = false;
		cin >> A >> B >> C;
		for (int x=-22; !sol && x<=22; x++) {
			if (x*x <= C) {
				for (int y=-58; !sol && y<=58; y++) {
					if (x != y && x*x+y*y <= C) {
						for (int z=-100; !sol && z<=100; z++) {
							if (x != z && y != z && x+y+z == A && x*y*z == B && x*x+y*y+z*z == C) {
								cout << x << " " << y << " " << z << "\n";
								sol = true;
							}
						}
					}
				}
			}
		}
		if (!sol) cout << "No solution.\n";
	}
	
	return 0;
}