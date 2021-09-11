#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

void backtrack(int t, int sum, int used, int pos, vi &x, vi current, vector<vi> &output) {
	if (sum == t) output.push_back(current);
	else {
		for (int i=pos; i<x.size(); i++) {
			if (!(used & (1<<i)) && sum+x[i] <= t && (i == pos || (i != pos && x[i] != x[i-1]))) {
				current.push_back(x[i]);
				backtrack(t, sum+x[i], used|(1<<i), i+1, x, current, output);
				current.pop_back();
			}
		}
	}
}

int main() {
	int t, n;
	cin >> t >> n;
	while (n) {
		vi x(n);
		for (int i=0; i<n; i++) cin >> x[i];
		sort(x.rbegin(), x.rend());
		vector<vi> output;
		backtrack(t, 0, 0, 0, x, {}, output);
		cout << "Sums of " << t << ":\n";
		if (output.empty()) cout << "NONE\n";
		else {
			for (auto i : output) {
				for (int j=0; j<i.size(); j++) {
					if (j) cout << "+";
					cout << i[j];
				}
				cout << "\n";
			}
		}
		
		cin >> t >> n;
	}
	
	return 0;
}