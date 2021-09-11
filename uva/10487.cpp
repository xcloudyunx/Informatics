#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, TC = 1, m, q, dif, val;
	cin >> n;
	while (n) {
		cout << "Case " << TC++ << ":\n";
		vi numbers(n);
		for (int i=0; i<n; i++) cin >> numbers[i];
		//sort(numbers.begin(), numbers.end());
		cin >> m;
		while (m--) {
			cin >> q;
			dif = INF;
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					if (abs(q-numbers[i]-numbers[j]) < dif) {
						val = numbers[i]+numbers[j];
						dif = abs(q-val);
					}
				}
			}
			cout << "Closest sum to " << q << " is " << val << ".\n";
		}
		
		cin >> n;
	}
	
	return 0;
}