#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	unsigned int N, L, U, M;
	while (cin >> N >> L >> U) {
		M = ~N;
		for (int i=31; i>=0; i--) {
			if ((L&(1<<i)) == (U&(1<<i))) {
				if (L&(1<<i)) M |= (1<<i);
				else M &= ~(1<<i);
			} else break;
		}
		for (int i=31; M<L; i--) { if (L&(1<<i)) M |= (1<<i); }
		for (int i=31; M>U; i--) { if (!(U&(1<<i))) M &= ~(1<<i); }
		
		cout << M << "\n";
	}
	
	return 0;
}