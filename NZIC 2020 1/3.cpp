#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, x, mean1 = 0, mean2 = 0, mean3 = 0, num = 0;
	bool resow = false;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x;
		if (x >= 25) num++;
		mean1 += x;
	}
	if (num >= N/2) resow = true;
	mean1 /= N;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x;
		mean2 += x;
	}
	mean2 /= N;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x;
		mean3 += x;
	}
	mean3 /= N;
	
	if (mean1 < 12 || mean2 < 12 || mean3 < 12) cout << "healthy\n";
	else if (resow) cout << "resow\n";
	else cout << "unhealthy\n";
	
	return 0;
}