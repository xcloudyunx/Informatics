#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int A, B, C, D, a1, a2, b1, b2, c1, c2, x, y = 0;
	cin >> A >> B >> C >> D;
	a1 = abs(D-(D/A)*A);
	a2 = abs(D-((D/A)+1)*A);
	b1 = abs(D-(D/B)*B);
	b2 = abs(D-((D/B)+1)*B);
	c1 = abs(D-(D/C)*C);
	c2 = abs(D-((D/C)+1)*C);
	x = min({a1, a2, b1, b2, c1, c2});
	cout << x << "\n";
	if (a1 == x || a2 == x) y++;
	if (b1 == x || b2 == x) y++;
	if (c1 == x || c2 == x) y++;
	if (y != 1) cout << "can't make up my mind\n";
	
	return 0;
}