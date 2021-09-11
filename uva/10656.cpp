#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, x;
	bool output;
	cin >> N;
	while (N) {
		output = false;
		while (N--) {
			cin >> x;
			if (x) {
				if (output) cout << " ";
				output = true;
				cout << x;
			}
		}
		if (!output) cout << 0;
		cout << "\n";
		
		cin >> N;
	}
	
	return 0;
}