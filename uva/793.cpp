#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000;

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.resize(N, 0);
		p.resize(N);
		iota(p.begin(), p.end(), 0);
	}
	
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) {return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
};

int main() {
	int T, n, i, j, su, un;
	string s;
	char c;
	cin >> T;
	
	while (T--) {
		su = 0, un = 0;
		cin >> n;
		UnionFind forest(n+1);
		cin.ignore();
		getline(cin, s);
		while (s != "") {
			c = s.at(0);
			sscanf(s.c_str(), "%*c %d %d", &i, &j);
			if (c == 'c') forest.unionSet(i, j);
			else if (forest.isSameSet(i, j)) su++;
			else un++;
			
			getline(cin, s);
		}
		cout << su << "," << un << "\n";
		if (T) cout << "\n";
	}
	
	return 0;
}