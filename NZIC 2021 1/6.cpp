#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int L, R, N, x, c, l, r, H = 0, total = 0;
	cin >> L >> R >> N;
	x = N;
	
	vector< pair< int, ii > > students(N);
	
	for (int i=0; i<N; i++) {
		cin >> c >> l >> r;
		if (l == -1) {
			R -= c;
			H += r*c;
			x--;
		} else if (r == -1) {
			L -= c;
			H += l*c;
			x--;
		} else {
			students[i].first = c;
			students[i].second.first = l;
			students[i].second.second = r;
			total += c;
		}
	}
	N = x;
	
	if (L < 0 || R < 0) {
		cout << "Camp is cancelled";
		return 0;
	}
	
	vector< vector< vector<int> > > table(L+1, vector< vector<int> >(R+1, vector<int>(2, -2)));
	for (int i=0; i<N; i++) {
		table[0][0][i] = H;
	}
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<=L; j++) {
			for (int k=0; k<=R; k++) {
				if (table[j][k][i%2] != -1) {
					if (j+students[i].first <= L) {
						table[j+students[i].first][k][(i+1)%2] = max(table[j+students[i].first][k][(i+1)%2], table[j][k][i%2] + students[i].second.first*students[i].first);
					}
					if (k+students[i].first <= R) {
						table[j][k+students[i].first][(i+1)%2] = max(table[j][k+students[i].first][(i+1)%2], table[j][k][i%2] + students[i].second.second*students[i].first);
					}
				}
				table[j][k][i%2] = -2;
			}
		}
	}
	
	H = -1;
	for (int i=0; i<=min(total, L); i++) {
		if (total-i > R) continue;
		H = max(H, table[i][total-i][0]);
		H = max(H, table[i][total-i][1]);
	}
	
	if (H == -1) {
		cout << "Camp is cancelled";
	} else {
		cout << H;
	}
	
	
	return 0;
}