#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, m, D, P, cmin, cmax;
	cin >> n >> m;
	int num = 1;
	
	while (n && m) {
		vii val(n);  //d, p
		for (int i=0; i<n; i++) cin >> val[i].first >> val[i].second;
		
		
		vector< vector< vi > > table(n, vector< vi >(m+1, {INF, 0, 0, 0}));
		table[0][1] = {abs(val[0].first-val[0].second), val[0].first+val[0].second, val[0].first, val[0].second, 0};
		for (int i=1; i<n; i++) {
			table[i][1] = {abs(val[i].first-val[i].second), val[i].first+val[i].second, val[i].first, val[i].second, i};
			if (table[i-1][1][0] < table[i][1][0]) {
				table[i][1] = table[i-1][1];
			} else if (table[i-1][1][0] == table[i][1][0] && table[i-1][1][1] > table[i][1][1]) {
				table[i][1] = table[i-1][1];
			}
			for (int j=2; j<=min(i+1, m); j++) {
				int x = abs(val[i].first + table[i][j-1][2] - val[i].second - table[i][j-1][3]);
				int y = val[i].first + table[i][j-1][2] + val[i].second + table[i][j-1][3];
				if (table[i-1][j][0] < x) {
					table[i][j] = table[i-1][j];
				} else if (table[i-1][j][0] == x && table[i-1][j][1] > y) {
					table[i][j] = table[i-1][j];
				} else {
					table[i][j] = {x, y, val[i].first + table[i][j-1][2], val[i].second + table[i][j-1][3]};
					for (int k=4; k<table[i][j-1].size(); k++) {
						table[i][j].push_back(table[i][j-1][k]);
					}
					table[i][j].push_back(i);
				}
			}
		}
		
		cout << "Jury #" << num++ << "\nBest jury has value " << table[n-1][m][2] << " for prosecution and value " << table[n-1][m][3] << " for defence:\n";
		for (int i=4; i<table[n-1][m].size(); i++) {
			cout << " " << table[n-1][m][i]+1;
		}
		cout << "\n";
		
		cin >> n >> m;
	}
}