#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, sum, cmax, x;
	cin >> N;
	while (N) {
		sum = 0;
		cmax = -INF;
		while (N--) {
			cin >> x;
			sum += x;
			cmax = max(cmax, sum);
			if (sum < 0) sum = 0;
		}
		if (cmax > 0) cout << "The maximum winning streak is " << cmax << ".\n";
		else cout << "Losing streak.\n";
		
		cin >> N;
	}
	
	return 0;
}