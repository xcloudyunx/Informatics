#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, K, p;
	string s;
	bool sol;
	cin >> T;
	while (T--) {
		cin >> K;
		vector<string> one(5, "      "), two(5, "      ");
		for (int i=0; i<6; i++) {
			cin >> s;
			for (int j=0; j<5; j++) {
				one[j][i] = s[j];
			}
		}
		for (int i=0; i<6; i++) {
			cin >> s;
			for (int j=0; j<5; j++) {
				two[j][i] = s[j];
			}
		}
		for (int i=0; i<5; i++) { sort(one[i].begin(), one[i].end()); sort(two[i].begin(), two[i].end()); }
		
		p = 0;
		sol = false;
		for (int a=0, v=0; !sol && a<6; a++) {
			if (a && one[0][a] == one[0][a-1]) continue;
			while (v < 6 && one[0][a] > two[0][v]) v++;
			if (v == 6) continue;
			if (one[0][a] < two[0][v]) continue;
			for (int b=0, w=0; !sol && b<6; b++) {
				if (b && one[1][b] == one[1][b-1]) continue;
				while (w < 6 && one[1][b] > two[1][w]) w++;
				if (w == 6) continue;
				if (one[1][b] < two[1][w]) continue;
				for (int c=0, x=0; !sol && c<6; c++) {
					if (c && one[2][c] == one[2][c-1]) continue;
					while (x < 6 && one[2][c] > two[2][x]) x++;
					if (x == 6) continue;
					if (one[2][c] < two[2][x]) continue;
					for (int d=0, y=0; !sol && d<6; d++) {
						if (d && one[3][d] == one[3][d-1]) continue;
						while (y < 6 && one[3][d] > two[3][y]) y++;
						if (y == 6) continue;
						if (one[3][d] < two[3][y]) continue;
						for (int e=0, z=0; !sol && e<6; e++) {
							if (e && one[4][e] == one[4][e-1]) continue;
							while (z < 6 && one[4][e] > two[4][z]) z++;
							if (z == 6) continue;
							if (one[4][e] < two[4][z]) continue;
							s = "";
							s += one[0][a];
							s += one[1][b];
							s += one[2][c];
							s += one[3][d];
							s += one[4][e];
							if (++p == K) {
								cout << s << "\n";
								sol = true;
							}
						}
					}
				}
			}
		}
		
		if (!sol) cout << "NO\n";
	}
	
	return 0;
}