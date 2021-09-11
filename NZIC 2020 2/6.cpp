#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, w, c;
	cin >> N >> K;
	
	vector< set<int> > width(K+1);
	map<int, int> depth;
	depth[K] = 0;
	for (int i=0; i<N; i++) {
		cin >> w;
		auto pos = depth.lower_bound(w);
		
		auto it = width[pos->first].find(pos->second);
		if (it != width[pos->first].end()) width[pos->first].erase(it);
		
		width[pos->first-w].insert(pos->second);
		if (!width[pos->first].empty()) pos->second = *width[pos->first].begin();
		else pos->second++;
		
		if (depth.find(pos->first-w) == depth.end()) depth[pos->first-w] = INF;
		depth[pos->first-w] = min(depth[pos->first-w], pos->second-1);
		
		if (pos->second == next(pos)->second) depth.erase(pos);
		
		for (auto i : depth) {
			cout << i.first << " " << i.second << ",  ";
		}
		cout << endl;
	}
	
	cout << depth[K] << "\n";
	
	return 0;
}