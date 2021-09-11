#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int n, m, s, e, x;
bool yes;

void backtrack(int pos, int current, int used, vii &pieces) {
	if (yes) return;
	if (pos == n && current == e) yes = true;
	else {
		for (int i=0; i<m; i++) {
			if (!(used & (1<<i))) {
				if (pieces[i].first == current) backtrack(pos+1, pieces[i].second, used|(1<<i), pieces);
				else if (pieces[i].second == current) backtrack(pos+1, pieces[i].first, used|(1<<i), pieces);
			}
		}
	}
}

int main() {
	cin >> n;
	while (n) {
		cin >> m >> x >> s >> e >> x;
		vii pieces(m);
		for (int i=0; i<m; i++) cin >> pieces[i].first >> pieces[i].second;
		yes = false;
		backtrack(0, s, 0, pieces);
		if (yes) cout << "YES\n";
		else cout << "NO\n";
		
		cin >> n;
	}
	
	return 0;
}