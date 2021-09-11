#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void backtrack(int n, int used, vi output) {
	if (output.size() == n && primes.find(output.back()+1) != primes.end()) {
		for (int i=0; i<n; i++) {
			if (i) cout << " ";
			cout << output[i];
		}
		cout << "\n";
	} else {
		for (int i=2; i<=n; i++) {
			if (!(used & (1<<i)) && primes.find(output.back()+i) != primes.end()) {
				output.push_back(i);
				backtrack(n, used|(1<<i), output);
				output.pop_back();
			}
		}
	}
}

int main() {
	int n, TC = 1;
	while (cin >> n) {
		if (TC != 1) cout << "\n";
		cout << "Case " << TC++ << ":\n";
		backtrack(n, 1, {1});
	}
	
	return 0;
}