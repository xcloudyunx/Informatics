#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

void getSubsets(int b, int l, int n, int i, vi subset, vector<vi> &subsets) {
	if (b == l) subsets.push_back(subset);
	else if (i == n) return;
	else {
		getSubsets(b, l, n, i+1, subset, subsets);
		subset.push_back(i);
		getSubsets(b, l+1, n, i+1, subset, subsets);
	}
}

int main() {
	int n, b, m, t, s, TC = 1, score, ctrue, cmax, output;
	cin >> n >> b;
	while (n && b) {
		vi c(n);
		vector<vii> overlap(n);
		for (int i=0; i<n; i++) cin >> c[i];
		cin >> m;
		for (int j=0; j<m; j++) {
			cin >> t;
			vi o(t);
			for (int i=0; i<t; i++) cin >> o[i];
			cin >> s;
			for (auto i : o) {
				overlap[i-1].push_back({j, s});
				c[i-1] -= s;
			};
		}

		vector<vi> subsets;
		getSubsets(b, 0, n, 0, {}, subsets);
		
		vi used(m, 0);
		ctrue = 0;
		cmax = 0;
		
		for (int i=0; i<subsets.size(); i++) {
			score = 0;
			ctrue++;
			for (auto j : subsets[i]) {
				score += c[j];
				for (auto k : overlap[j]) {
					if (used[k.first] != ctrue) {
						score += k.second;
						used[k.first] = ctrue;
					}
				}
			}
			if (score >= cmax) {
				cmax = score;
				output = i;
			} 
		}
		
		cout << "Case Number  " << TC++ << "\nNumber of Customers: " << cmax << "\nLocations recommended: ";
		for (int i=0; i<b; i++) {
			if (i) cout << " ";
			cout << subsets[output][i]+1;
		}
		cout << "\n\n";
		
		cin >> n >> b;
	}
	
	return 0;
}