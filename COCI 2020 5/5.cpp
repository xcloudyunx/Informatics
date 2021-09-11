#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define MOD 1000000007

ll factorial[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

ll c(int a, int b) {
	return factorial[a]/(factorial[b]*factorial[a-b]);
}

int main() {
	int N;
	cin >> N;
	
	ll total = 1 + N*(N-1), tmp;
	cout << total << endl;
	for (int i=N-2; i>0; i--) {
		tmp = 0;
		for (int j=1; j<=N-i; j++) {
			tmp += j*c(N-1, j);
			if (N-i > i) tmp -= j;
			tmp %= MOD;
			//cout << tmp << endl;
		}
		total += (tmp*c(N, i))%MOD;
		cout << total << endl;
	}
	
	cout << total << "\n";
	
	return 0;
}