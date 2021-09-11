#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define LSB(s) (s&(-s))

class SegmentTree {
private:
	vi st;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	int build(int p, int L, int R, vi &A) {
		if (L == R) return st[p] = (A[L] == 0) ? 0 : A[L]/abs(A[L]);
		int M = (L+R)/2;
		int p1 = build(left(p), L, M, A);
		int p2 = build(right(p), M+1, R, A);
		return st[p] = p1*p2;
	}
	int update(int p, int L, int R, int i, int value) {
		if (i > R || i < L) return st[p];
		if (L == R) return st[p] = (value == 0) ? 0 : value/abs(value);
		int M = (L+R)/2;
		int p1 = update(left(p), L, M, i, value);
		int p2 = update(right(p), M+1, R, i, value);
		return st[p] = p1*p2;
	}
	int queryRange(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return 2;
		if (L >= i && R <= j) return st[p];
		int M = (L+R)/2;
		int p1 = queryRange(left(p), L, M, i, j);
		int p2 = queryRange(right(p), M+1, R, i, j);
		if (p1 == 2) return p2;
		if (p2 == 2) return p1;
		return p1*p2;
	}
public:
	SegmentTree(vi &A) {
		n = A.size();
		st.assign(4*n, 0);
		build(1, 0, n-1, A);
	}
	void update(int i, int v) { update(1, 0, n-1, i, v); }
	int query(int i, int j) { return queryRange(1, 0, n-1, i, j); }
};

int main() {
	int N, K, I, V;
	char c;
	while (cin >> N >> K) {
		vi X(N);
		for (int i=0; i<N; i++) cin >> X[i];
		
		SegmentTree st(X);
		
		while (K--) {
			cin >> c >> I >> V;
			if (c == 'C') st.update(I-1, V);
			else if (c == 'P') {
				int x = st.query(I-1, V-1);
				cout << ((x == 0) ? "0" : ((x == 1) ? "+" : "-"));
			}
		}
		
		cout << "\n";
	}
	
	return 0;
}