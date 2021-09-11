#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, num = 0;
	cin >> N;
	vi a(N);
	for (int i=0; i<N; i++) cin >> a[i];
	vi b(N);
	for (int i=0; i<N; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for (int i=0, j=0; i<N && j<N; i++, j++) {
		while (j < N && a[j] < b[i]) j++;
		if (j == N) break;
		num++;
	}
	
	cout << num << "\n";
	
	return 0;
}