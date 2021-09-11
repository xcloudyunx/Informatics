#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

struct Node {
	int left;
	int main;
	int right;
};

class SegmentTree {
private:
	vi A;
	vector<Node> st;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	Node build(int p, int L, int R) {
		if (L == R) return st[p] = {1, 1, 1};
		int M = (L+R)/2;
		Node p1 = build(left(p), L, M);
		Node p2 = build(right(p), M+1, R);
		if (A[M] == A[M+1]) {
			if (A[L] == A[M] && A[M+1] == A[R]) st[p] = {p1.main+p2.main, p1.main+p2.main, p1.main+p2.main};
			else if (A[L] == A[M]) st[p] = {p1.main+p2.left, p1.main+p2.left, p2.right};
			else if (A[M+1] == A[R]) st[p] = {p1.left, p1.right+p2.main, p1.right+p2.main};
			else st[p] = {p1.left, max({p1.main, p1.right+p2.left, p2.main}), p2.right};
		} else st[p] = {p1.left, max(p1.main, p2.main), p2.right};
		//cout << L << " " << R << ": " << st[p].left << " " << st[p].main << " " << st[p].right << endl;
		return st[p];
	}
	Node queryRange(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return {-1, -1, -1};
		if (L >= i && R <= j) return st[p];
		int M = (L+R)/2;
		Node p1 = queryRange(left(p), L, M, i, j);
		Node p2 = queryRange(right(p), M+1, R, i, j);
		if (p1.main == -1) return p2;
		if (p2.main == -1) return p1;
		if (A[M] == A[M+1]) {
			if (A[L] == A[M] && A[M+1] == A[R]) return {p1.main+p2.main, p1.main+p2.main, p1.main+p2.main};
			else if (A[L] == A[M]) return {p1.main+p2.left, p1.main+p2.left, p2.right};
			else if (A[M+1] == A[R]) return {p1.left, p1.right+p2.main, p1.right+p2.main};
			else return {p1.left, max({p1.main, p1.right+p2.left, p2.main}), p2.right};
		} else return {p1.left, max(p1.main, p2.main), p2.right};
	}

public:
	SegmentTree(vi _A) {
		A = _A;
		n = A.size();
		st.resize(4*n, {0, 0, 0});
		build(1, 0, n-1);
	}
	int query(int i, int j) { return queryRange(1, 0, n-1, i, j).main; }
};

int main() {
	int n, q, i, j;
	cin >> n;
	
	while (n) {
		cin >> q;
		vi a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		
		SegmentTree st(a);
		
		while (q--) {
			cin >> i >> j;
			cout << st.query(i-1, j-1) << "\n";
		}
		
		cin >> n;
	}
	
	return 0;
}



https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2176
UVa 11235 - Frequent Values * (range maximum query)