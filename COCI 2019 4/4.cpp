#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	if (fac(N*M)%K != 0) {
		cout << -1 << endl;
	}
	
	return 0;
}