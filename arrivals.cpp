#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, T, low, high, mid, c, s;
	cin >> N >> K;
	
	queue<int> og, t;
	
	for (int i=0; i<N; i++) {
		cin >> T;
		og.push(T);
	}
	
	low = 0, high = og.back()-og.front();
	while (high > low) {
		mid = (high+low)/2;
		t = og;
		c = 0;
		while (!t.empty()) {
			s = t.front();
			t.pop();
			while (!t.empty() && t.front() <= s+mid) t.pop();
			c++;
		}
		if (c > K) low = mid+1;
		else high = mid-1;
	}
	
	c = 0;
	while (!og.empty()) {
		s = og.front();
		og.pop();
		while (!og.empty() && og.front() <= s+low) og.pop();
		c++;
	}
	
	if (c <= K) cout << low;
	else cout << low+1;
	
	return 0;
}