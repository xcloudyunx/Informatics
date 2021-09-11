#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long c;
	cin >> N >> c;
	c /= 5;
	
	unordered_map<long long, int> m;
	vector<long long> heights(N);
	
	for (int i=0; i<N; i++) {
		long long h;
		cin >> h;
		heights.at(i) = h;
		if (!m.emplace(h, 1).second) {
			m.at(h)++;
		}
	}
	
	sort(heights.begin(), heights.end());
	heights.erase(unique(heights.begin(), heights.end()), heights.end());
	
	long long total = 0;
	int trees = 0;
	int current = heights.size()-1;
	
	while (current >= 0) {
		long long ch = heights.at(current--);
		trees += m.at(ch);
		long long mh = c/trees;
		if (current != -1) mh = max(mh, heights.at(current));
		total += max(ch-mh, (long long) 0);
	}
	
	cout << total;
	
	return 0;
}