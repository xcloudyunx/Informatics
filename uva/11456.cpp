#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, N, cmax, x;
	cin >> T;
	while (T--) {
		cin >> N;
		vi cars(N);
		vi LIS(N);
		vi LDS(N);
		x = 0;
		for (int i=0; i<N; i++) cin >> cars[i];
		for (int i=N-1; i>=0; i--) {			
			if (i == N-1) LIS[i] = 1;
			else {
				cmax = 0;
				for (int j=N-1; j>i; j--) { if (cars[i] > cars[j]) cmax = max(cmax, LIS[j]); }
				LIS[i] = cmax+1;
			}
			
			if (i == N-1) LDS[i] = 1;
			else {
				cmax = 0;
				for (int j=N-1; j>i; j--) { if (cars[i] < cars[j]) cmax = max(cmax, LDS[j]); }
				LDS[i] = cmax+1;
			}
			x = max(x, LIS[i]+LDS[i]-1);
		}
		cout << x << "\n";
	}
	
	return 0;
}