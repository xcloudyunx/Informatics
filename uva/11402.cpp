#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

class SegmentTree {
private:
	vi st, lazy;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	int build(int p, int L, int R, string &A) {
		if (L == R) return st[p] = A[L]-'0';
		int M = (L+R)/2;
		int p1 = build(left(p), L, M, A);
		int p2 = build(right(p), M+1, R, A);
		return st[p] = p1+p2;
	}
	void checkLazy(int p, int L, int R) {
		if (lazy[p] != 0) {
			if (lazy[p] == 1) st[p] = R-L+1;
			else if (lazy[p] == 2) st[p] = 0;
			else if (lazy[p] == 3) st[p] = R-L+1-st[p];
			if (L != R) {
				if (lazy[p] == 3) {
					if (lazy[left(p)] == 3) lazy[left(p)] = 0;
					else if (lazy[left(p)] == 2) lazy[left(p)] = 1;
					else if (lazy[left(p)] == 1) lazy[left(p)] = 2;
					else lazy[left(p)] = 3;
					if (lazy[right(p)] == 3) lazy[right(p)] = 0;
					else if (lazy[right(p)] == 2) lazy[right(p)] = 1;
					else if (lazy[right(p)] == 1) lazy[right(p)] = 2;
					else lazy[right(p)] = 3;
				} else {
					lazy[left(p)] = lazy[p];
					lazy[right(p)] = lazy[p];
				}
			}
			lazy[p] = 0;
		}
	}
	int updateRange(int p, int L, int R, int i, int j, int type) { //type 1 is F(buc), 2 is E(bar), 3 is I(swap)
		checkLazy(p, L, R);
		if (i > R || j < L) return st[p];
		if (L >= i && R <= j) {
			if (L != R) {
				if (type == 3) {
					if (lazy[left(p)] == 3) lazy[left(p)] = 0;
					else if (lazy[left(p)] == 2) lazy[left(p)] = 1;
					else if (lazy[left(p)] == 1) lazy[left(p)] = 2;
					else lazy[left(p)] = 3;
					if (lazy[right(p)] == 3) lazy[right(p)] = 0;
					else if (lazy[right(p)] == 2) lazy[right(p)] = 1;
					else if (lazy[right(p)] == 1) lazy[right(p)] = 2;
					else lazy[right(p)] = 3;
				} else {
					lazy[left(p)] = type;
					lazy[right(p)] = type;
				}
			}
			if (type == 1) return st[p] = R-L+1;
			else if (type == 2) return st[p] = 0;
			else if (type == 3) return st[p] = R-L+1-st[p];
		}
		int M = (L+R)/2;
		int p1 = updateRange(left(p), L, M, i, j, type);
		int p2 = updateRange(right(p), M+1, R, i, j, type);
		return st[p] = p1+p2;
	}
	int queryRange(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return 0;
		checkLazy(p, L, R);
		if (L >= i && R <= j) return st[p];
		int M = (L+R)/2;
		int p1 = queryRange(left(p), L, M, i, j);
		int p2 = queryRange(right(p), M+1, R, i, j);
		return p1+p2;
	}
	
public:
	SegmentTree(string &A) {
		n = A.size();
		st.resize(4*n, 0);
		lazy.resize(4*n, 0);
		build(1, 0, n-1, A);
	}
	void update(int i, int j, int t) { updateRange(1, 0, n-1, i, j, t); }
	int query(int i, int j) { return queryRange(1, 0, n-1, i, j); }
};

int main() {
	int T, M, t, Q, a, b, q;
	char c;
	string s, pirates;
	cin >> T;
	
	for (int TC=1; TC<=T; TC++) {
		pirates = "";
		cin >> M;
		while (M--) {
			cin >> t >> s;
			while (t--) pirates += s;
		}
		
		SegmentTree st(pirates);
		
		cin >> Q;
		q = 1;
		cout << "Case " << TC << ":\n";
		while (Q--) {
			cin >> c >> a >> b;
			if (c == 'F') st.update(a, b, 1);
			else if (c == 'E') st.update(a, b, 2);
			else if (c == 'I') st.update(a, b, 3);
			else if (c == 'S') cout << "Q" << q++ << ": " << st.query(a, b) << "\n";
		}
	}
	
	return 0;
}