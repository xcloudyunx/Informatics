#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, C;
	cin >> N >> C;
	vi buy(N);
	for (int i=0; i<N; i++) {
		cin >> buy[i];
	}
	vi sell(N);
	for (int i=0; i<N; i++) {
		cin >> sell[i];
	}
	
	int coins = 0;
	int value = INF;
	for (int i=0; i<N; i++) {
		value = max(sell[i], value);
		if (buy[i] < value) {
			C += coins * value;
			coins = C / buy[i];
			C %= buy[i];
			value = buy[i];
		}
	}
	C += coins * value;
	
	cout << C;
	
	return 0;
}