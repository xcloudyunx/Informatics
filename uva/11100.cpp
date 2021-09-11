#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, maxl, curl, val;
	cin >> n;
	while (n) {
		vi bags(n);
		for (int i=0; i<n; i++) cin >> bags[i];
		sort(bags.begin(), bags.end());
		maxl = 1, curl = 1, val = bags[0];
		for (int i=1; i<n; i++) {
			if (bags[i] == bags[i-1]) curl++;
			else {
				if (curl > maxl) {
					maxl = curl;
					val = bags[i-1];
				}
				curl = 1;
			}
		}
		if (curl > maxl) {
			maxl = curl;
			val = bags[n-1];
		}
		vector<vi> output(maxl);
		for (int i=0, count=0; i<n; i++) {
			output[(count++)%maxl].push_back(bags[i]);
		}
		cout << maxl << "\n";
		for (auto i : output) {
			for (int j=0; j<i.size(); j++) {
				if (j) cout << " ";
				cout << i[j];
			}
			cout << "\n";
		}
		
		cin >> n;
		if (n) cout << "\n";
	}
	
	return 0;
}