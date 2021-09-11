#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

class UnionFind {
private:
	vi p, rank;
	int numSets;
public:
	UnionFind(int N) {
		rank.resize(N, 0);
		p.resize(N);
		iota(p.begin(), p.end(), 0);
		numSets = N;
	}
	
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		i = findSet(i), j = findSet(j);
		if (i != j) {
			if (rank[i] < rank[j]) swap(i, j);
			p[j] = i;
			if (rank[i] == rank[j]) rank[i]++;
			numSets--;
		}
	}
	int size() { return numSets; }
};

int main() {
	int N, M, x, y;
	bool broken;
	string s;
	
	while (cin >> N) {
		UnionFind forest(N);
		unordered_map<char, int> m;
		vector< unordered_set<int> > adj(N);
		x = 3;
		y = 0;
		cin >> M;
		cin.ignore();
		getline(cin, s);
		m[s[0]] = 0;
		m[s[1]] = 1;
		m[s[2]] = 2;
		
		while (M--) {
			getline(cin, s);
			if (m.find(s[0]) == m.end()) m[s[0]] = x++;
			if (m.find(s[1]) == m.end()) m[s[1]] = x++;
			forest.unionSet(m[s[0]], m[s[1]]);
			adj[m[s[0]]].insert(m[s[1]]);
			adj[m[s[1]]].insert(m[s[0]]);
		}
		
		if (N == 3) cout << "WAKE UP IN, 0, YEARS\n";
		else if (forest.size() > 1 || !forest.isSameSet(0, 1) || !forest.isSameSet(0, 2) || !forest.isSameSet(1, 2)) cout << "THIS BRAIN NEVER WAKES UP\n";
		else {
			broken = false;
			for (int i=3; i<N; i++) {
				if (adj[i].size() < 3) {
					cout << "THIS BRAIN NEVER WAKES UP\n";
					broken = true;
					break;
				}
			}
			if (!broken) {
				vi v(N, INF);
				priority_queue<ii, vii, greater<ii> > q;
				q.push({0, 0});
				q.push({1, 0});
				q.push({2, 0});
				v[0] = 0;
				v[1] = 0;
				v[2] = 0;
				
				while (!q.empty()) {
					int f = q.top().first, t = q.top().second;
					q.pop();
					for (auto i : adj[f]) {
						if (v[i] > t+1) {
							int count = 0;
							priority_queue<int> large;
							for (auto j : adj[i]) {
								if (v[j] != INF) {
									count++;
									if (large.size() == 3 && v[j] < large.top()) { large.pop(); large.push(v[j]); }
									else large.push(v[j]);
								}
							}
							if (count >= 3 && large.top() < v[i]) { v[i] = large.top()+1; q.push({i, v[i]}); }
						}
					}
				}

				for (auto i : v) {
					if (i == INF) { broken = true; break; }
					y = max(y, i);
				}
				if (broken) cout << "THIS BRAIN NEVER WAKES UP\n";
				else cout << "WAKE UP IN, " << y << ", YEARS\n";
			}
		}
		
	}
	
	return 0;
}