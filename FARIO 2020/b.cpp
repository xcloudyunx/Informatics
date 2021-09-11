#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K;
	bool broken = false;
	cin >> N >> K;
	
	vi seen(200001, -1);
	vi B(N);
	vi A(N, 0);
	for (int i=0; i<N; i++) {
		cin >> B[i];
		if (seen[B[i]] != -1) {
			A[i] = B[i];
			A[seen[B[i]]] = B[i];
			if (B[i] > K) {
				broken = true;
				break;
			}
		} else seen[B[i]] = i;
	}
	
	if (broken) cout << -1 << "\n";
	
	return 0;
}