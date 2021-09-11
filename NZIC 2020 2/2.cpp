#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, x;
	int total = 10;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x;
		total += x;
	}
	
	if (total == 10) cout << "She's got them all\n";
	else cout << 10-total << "\n";
	
	return 0;
}