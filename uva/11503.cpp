#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

class UnionFind {
private: vi p, rank, size;
public:
	UnionFind() {}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		i = findSet(i), j = findSet(j);
		if (i != j) {
			if (rank[i] < rank[j]) swap(i, j);
			size[i] += size[j];
			p[j] = i;
			if (rank[i] == rank[j]) rank[i]++;
		}
	}
	int setSize(int i) { return size[findSet(i)]; }
	void newPerson() { p.push_back(p.size()); rank.push_back(0); size.push_back(1); }
};

int main() {
	int T, F, x;
	string a, b;
	cin >> T;
	
	while (T--) {
		x = 0;
		map<string, int> m;
		UnionFind forest;
		cin >> F;
		while (F--) {
			cin >> a >> b;
			if (m.find(a) == m.end()) { m[a] = x++; forest.newPerson(); }
			if (m.find(b) == m.end()) { m[b] = x++; forest.newPerson(); }
			forest.unionSet(m[a], m[b]);
			cout << forest.setSize(m[a]) << "\n";
		}
	}
	
	return 0;
}