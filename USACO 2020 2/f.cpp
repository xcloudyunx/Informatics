#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.resize(N, 0);
		p.resize(N);
		iota(p.begin(), p.end(), 0);
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	bool unionSet(int i, int j) {
		i = findSet(i), j = findSet(j);
		if (i != j) {
			if (rank[i] < rank[j]) swap(i, j);
			p[j] = i;
			if (rank[i] == rank[j]) rank[i]++;
			return true;
		}
		return false;
	}
};

int main() {
	ifstream infile;
	infile.open("wormsort.in");
	ofstream outfile;
	outfile.open("wormsort.out");
	
	int N, M, a, b, w, cmin = INF;
	infile >> N >> M;
	
	vi p(N+1);
	for (int i=1; i<=N; i++) infile >> p[i];
	
	priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater< pair<int, ii> > > q;
	
	while (M--) {
		infile >> a >> b >> w;
		if (p[a] != a || p[b] != b) q.push({-w, {a, b}});
	}
	
	UnionFind forest(N);
	
	while (!q.empty()) {
		w = q.top().first;
		a = q.top().second.first-1;
		b = q.top().second.second-1;
		q.pop();
		cout << w << " " << a << " " << b << endl;
		if (forest.unionSet(a, b)) cmin = min(cmin, -w);
	}
	
	if (cmin == INF) outfile << -1 << "\n";
	else outfile << cmin << "\n";
	
	
	infile.close();
	outfile.close();
	return 0;
}