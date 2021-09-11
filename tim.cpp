#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

const int MAXJ = 17;

vector<vii> parents;
vi depth;

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
	void unionSet(int i, int j) {
		i = findSet(i), j = findSet(j);
		if (i != j) {
			if (rank[i] > rank[j]) swap(i, j);
			p[j] = i;
			if (rank[i] == rank[j]) rank[j]++;
		}
	}
};

ii jump(int a, int x) { //return the ancestor and the distance jumped so far
  int j = MAXJ, d = 0;
  while (x != 0) {
    if ((1<<j) <= x) {
      d = max(d, parents[a][j].second);
      a = parents[a][j].first;
      x -= (1<<j);
    }
    j--;
  }
  return {a, d};
}

int LCA(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  ii tmp = jump(b, depth[b]-depth[a]);
  b = tmp.first;
  int d = tmp.second;
  if (a == b) return d;
  for (int j=MAXJ; j>=0; j--) {
    if (parents[a][j].first != parents[b][j].first) {
      d = max({d, parents[a][j].second, parents[b][j].second});
      a = parents[a][j].first;
      b = parents[b][j].first;
    }
  }
  if (a != b) d = max({d, parents[a][0].second, parents[b][0].second});
  return d;
}

int main() {
  int N, M, Q, u, v, e, a, b;
  cin >> N >> M >> Q;

  vector<vii> adj(N); //dest, weight
  priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater< pair<int, ii> > > qu;

  while (M--) {
    cin >> u >> v >> e;
    u--; v--;
	qu.push({e, {u, v}});
  }
  
  UnionFind forest(N);
  
  while (!qu.empty()) {
	e = qu.top().first;
	u = qu.top().second.first;
	v = qu.top().second.second;
	qu.pop();
	if (!forest.isSameSet(u, v)) {
	  forest.unionSet(u, v);
	  adj[u].push_back({v, e});
      adj[v].push_back({u, e});
	}
  }

  depth.resize(N, -1);
  parents.resize(N, vii(MAXJ+1));

  queue<int> q;
  parents[0][0] = {-1, -1};
  depth[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (auto i : adj[f]) {
      if (depth[i.first] != -1) continue;
      parents[i.first][0] = {f, i.second};
      depth[i.first] = depth[f]+1;
      for (int j=1; (1<<j)<=depth[i.first]; j++) {
        parents[i.first][j] = {parents[parents[i.first][j-1].first][j-1].first, max(parents[i.first][j-1].second, parents[parents[i.first][j-1].first][j-1].second)};
      }
      q.push(i.first);
    }
  }

  while (Q--) {
    cin >> a >> b;
    cout << LCA(a-1, b-1) << "\n";
  }

  return 0;
}