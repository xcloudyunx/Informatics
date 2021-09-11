#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N;
	ll total = 0;
	cin >> N;
	vi trees(N);
	for (int i=0; i<N; i++) cin >> trees[i];
	stack<int> s;
	for (int i=0; i<N; i++) {
		if (s.empty()) {
			s.push(trees[i]);
			total += trees[i];
		} else if (trees[i] > s.top()) {
			total += trees[i]-s.top();
			s.push(trees[i]);
		} else if (trees[i] < s.top()) {
			s.pop();
			s.push(trees[i]);
		}
	}
	cout << total << "\n";
	
	return 0;
}