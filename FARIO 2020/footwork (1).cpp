#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, cscore = 0;
	ii tmp;
	cin >> N >> K;
	vi A(N);
	vi B(N);
	
	queue<int> apos;
	queue<int> bpos;
	
	for (int i=0; i<N; i++) {
		cin >> A[i];
		if (i == 0 || i == N-1 || A[i] >= 0) {
			cscore += A[i];
			apos.push(i);
		}
	}
	for (int i=0; i<N; i++) {
		cin >> B[i];
		if (i == 0 || i == N-1 || B[i] >= 0) {
			cscore += B[i];
			bpos.push(i);
		}
	}
	
	int a = apos.front();
	int b = bpos.front();
	bool change;
	apos.pop();
	bpos.pop();
	
	while (!apos.empty() || !bpos.empty()) {
		do {
			change = false;
			while (!apos.empty() && apos.front()-b <= K) {
				a = apos.front();
				apos.pop();
				change = true;
			}
			while (!bpos.empty() && bpos.front()-a <= K) {
				b = bpos.front();
				bpos.pop();
				change = true;
			}
		} while (change);
		
		if (apos.empty() && bpos.empty()) break;
		
		if (a < b) {
			a = b+K;
		} else if (a > b) {
			b = a+K;
		} else if (apos.front() < bpos.front()) {
			if (a + 2*K >= apos.front()) {
				b = a+K;
			} else {
				a = b+K;
			}
		} else {
			if (b + 2*K >= bpos.front()) {
				a = b+K;
			} else {
				b = a+K;
			}
		}
		cscore--;
	}
	
	cout << cscore << "\n";
	
	return 0;
}