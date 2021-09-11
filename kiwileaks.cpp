#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

ll GCD(ll a, ll b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

ll LCM(ll a, ll b) {
	if (a == 0) return b;
	if (max(a, b)%min(a, b) == 0) return max(a, b);
	return (a/GCD(a, b))*b;
}

int main() {
	ifstream infile;
	infile.open("leakin.txt");
	ofstream outfile;
	outfile.open("leakout.txt");
	
	int N, K, x;
	ll count;
	infile >> N >> K;
	
	vi sub(N+1);
	for (int i=1; i<=N; i++) infile >> sub[i];
	vi v(N+1, 0);
	for (int i=1; i<=N; i++) {
		if (v[i]) continue;
		x = i;
		count = 0;
		while (!v[x]) {
			count++;
			v[x] = 1;
			x = sub[x];
		}
		while (v[x] != count) {
			v[x] = count;
			x = sub[x];
		}
	}
	
	count = 0;
	for (int i=0; i<K; i++) {
		infile >> x;
		count = LCM(count, v[x]);
	}
	
	outfile << count << "\n";
	
	return 0;
}