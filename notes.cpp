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
	void unionSet(int i, int j) {
		i = findSet(i), j = findSet(j);
		if (i != j) {
			if (rank[i] > rank[j]) swap(i, j);
			p[j] = i;
			if (rank[i] == rank[j]) rank[j]++;
		}
	}
}



class SegmentTree {
private:
	vi st, lazy;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	int build(int p, int L, int R, vi& A) {
		if (L == R) return st[p] == A[L];
		int M = L+(R-L)/2;
		int p1 = build(left(p), L, M, A);
		int p2 = build(right(p), M+1, R, A);
		return st[p] = max(p1, p2);
	}
	void checkLazy(int p, int L, int R) {
		if (lazy[p] != 0) {
			st[p] += lazy[p];
			if (L != R) {
				lazy[left(p)] += lazy[p];
				lazy[right(p)] += lazy[p];
			}
			lazy[p] = 0;
		}
	}
	int updateRange(int p, int L, int R, int i, int j, int delta) {
		checkLazy(p, L, R);
		if (i > R || j < L) return st[p];
		if (L >= i && R <= j) {
			if (L != R) {
				lazy[left(p)] += delta;
				lazy[right(p)] += delta;
			}
			return st[p] += delta;
		}
		int M = L+(R-L)/2;
		int p1 = updateRange(left(p), L, M, i, j, delta);
		int p2 = updateRange(right(p), M+1, R, i, j, delta);
		return st[p] = max(p1, p2);
	}
	int queryRange(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		checkLazy(p, L, R);
		if (L >= i && R <= j) return st[p];
		int M = L+(R-L)/2;
		int p1 = queryRange(left(p), L, M, i, j);
		int p2 = queryRange(right(p), M+1, R, i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return max(p1, p2);
	}
public:
	SegmentTree(vi &A) {
		n = A.size();
		st.assign(4*n, 0);
		lazy.assign(4*n, 0);
		build(1, 0, n-1, A);
	}
	void update(int i, int j, int d) { updateRange(1, 0, n-1, i, j, d); }
	int query(int i, int j) { return queryRange(1, 0, n-1, i, j); }
}



#define LSB(S) (S&(-S))
class FenwickTree {
private: vi ft;
public:
	FenwickTree(int n) { ft.resize(n+1, 0); }
	int query(int b) {
		int sum = 0;
		for (; b; b-=LSB(b)) sum += ft[b];
		return sum;
	}
	int query(int a, int b) { return query(b)-query(a); }
	void adjust(int k, int v) { for (; k<ft.size(); k+=LSB(k)) ft[k] += v; }
}


int main() {
	
	
	return 0;
}