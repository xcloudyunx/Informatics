#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

vector<vi> possible;

bool place(int r, int c, vi current) {
	for (int prev=0; prev<c; prev++) {
		if (current[prev] == r || abs(current[prev]-r) == abs(prev-c)) return false;
	}
	return true;
}

void backtrack(int c, vi current) {
	if (c == 8) possible.push_back(current);
	else {
		for (int r=0; r<8; r++) {
			if (place(r, c, current)) {
				current[c] = r;
				backtrack(c+1, current);
			}
		}
	}
}

int main() {
	int cmin, c, TC = 1;;
	vi row(8);
	backtrack(0, vi(8));
	
	while (cin >> row[0] >> row[1] >> row[2] >> row[3] >> row[4] >> row[5] >> row[6] >> row[7]) {
		cmin = 8;
		for (auto i : possible) {
			c = 0;
			for (int j=0; j<8; j++) {
				if (i[j] != row[j]-1) c++;
			}
			cmin = min(c, cmin);
		}
		cout << "Case " << TC++ << ": " << cmin << "\n";
	}
	
	return 0;
}