#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N;
	cin >> N;
	
	int total;
	cin >> total;
	for (int i=1; i<N; i++) {
		int x;
		cin >> x;
		if (i%3 == 1) total += x;
		else if (i%3 == 2) total -= x;
		else total *= x;
	}
	cout << total;
	
	return 0;
}