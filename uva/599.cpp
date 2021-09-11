#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000;

class UnionFind {
private: vi p, rank, setSize;
public:
	int numSets;

	UnionFind(int N) {
		rank.resize(N, 0);
		p.resize(N, 0);
		iota(p.begin(), p.end(), 0);
		setSize.resize(N, 1);
		numSets = N;
	}
	
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] < rank[y]) swap(x, y);
			p[y] = x;
			setSize[x] += setSize[y];
			if (rank[x] == rank[y]) rank[x]++;
			numSets--;
		}
	}
	
	int numOfSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[i] = setSize[findSet(i)]; }
};

int main() {
	int N, x, trees, acorns;
	string s;
	char a, b;
	bool broken;
	cin >> N;
	
	while (N--) {
		unordered_map<char, int> m;
		vector<vi> adj(26, vector<int>());
		x = 0;
		cin >> s;
		while (s.at(0) != '*') {
			a = s.at(1), b = s.at(3);
			if (m.find(a) == m.end()) {
				m[a] = x++;
			}
			if (m.find(b) == m.end()) {
				m[b] = x++;
			}
			
			adj.at(m[a]).push_back(m[b]);
			adj.at(m[b]).push_back(m[a]);
			
			cin >> s;
		}
		cin >> s;
		x = s.size()/2+1;
		adj.resize(x);
		UnionFind forest(x);
		
		for (int i=0; i<x; i++) {
			for (auto j : adj.at(i)) {
				forest.unionSet(i, j);
			}
		}
		
		acorns = 0;
		unordered_set<int> parents;
		
		for (int i=0; i<x; i++) {
			if (forest.sizeOfSet(i) == 1) {
				acorns++;
			} else {
				parents.insert(forest.findSet(i));
			}
		}
		
		trees = parents.size();
		for (auto i : parents) {
			queue<ii> q;
			vector<bool> v(x, false);
			q.push({i, i});
			v[i] = true;
			broken = false;
			while (!q.empty()) {
				int f = q.front().first;
				int o = q.front().second;
				q.pop();
				for (auto j : adj.at(f)) {
					if (j != o && v[j]) {
						trees--;
						broken = true;
						break;
					} else if (j != o) {
						q.push({j, f});
						v[j] = true;
					}
				}
				if (broken) break;
			}
		}
		
		cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
	}
	
	return 0;
}