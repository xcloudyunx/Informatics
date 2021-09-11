#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int M;
	while (cin >> M) {
		vector<string> grid(M);
		vector<ii> ones;
		vector<ii> threes;
		for (int i=0; i<M; i++) {
			cin >> grid[i];
			for (int j=0; j<M; j++) {
				if (grid[i][j] == '1') ones.push_back({i, j});
				else if (grid[i][j] == '3') threes.push_back({i, j});
			}
		}
		int cmax = 0;
		int cmin;
		for (auto i : ones) {
			cmin = INF;
			for (auto j : threes) cmin = min(cmin, abs(i.second-j.second)+abs(i.first-j.first));
			cmax = max(cmax, cmin);
		}
		
		cout << cmax << "\n";
	}
	
	return 0;
}