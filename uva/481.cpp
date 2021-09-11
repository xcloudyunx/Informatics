#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int x, d;
	vi num = {};
	vector<vi> sequence = {};
	while (cin >> x) {
		if (num.empty()) {
			num.push_back(x);
			sequence.push_back({x});
		} else {
			d = distance(num.begin(), lower_bound(num.begin(), num.end(), x));
			if (d == num.size()) {
				num.push_back(x);
				sequence.push_back(sequence.back());
				sequence.back().push_back(x);
			} else {
				num[d] = x;
				if (d) {
					sequence[d] = sequence[d-1];
					sequence[d].push_back(x);
				} else sequence[d][d] = x;
			}
		}
	}
	
	cout << num.size() << "\n-\n";
	for (auto i : sequence.back()) cout << i << "\n";
	
	return 0;
}