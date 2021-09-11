#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int Q, low, high, mid, clow, start, end;
	bool broken;
	string S, SS;
	cin >> S >> Q;
	unordered_map<char, vi> m;
	for (int i=0; i<S.size(); i++) {
		if (m.find(S[i]) == m.end()) m[S[i]] = {i};
		else m[S[i]].push_back(i);
	}
	
	while (Q--) {
		cin >> SS;
		clow = -1;
		broken = false;
		for (int i=0; i<SS.size(); i++) {
			low = -1; high = m[SS[i]].size(); //low always impossible
			while (high-low > 1) {
				mid = (low+high)/2;
				if (m[SS[i]][mid] <= clow) low = mid;
				else high = mid;
			}
			if (low == m[SS[i]].size()-1) { broken = true; break; }
			clow = m[SS[i]][high];
			if (i == 0) start = clow;
			if (i == SS.size()-1) end = clow;
		}
		if (broken) cout << "Not matched\n";
		else cout << "Matched " << start << " " << end << "\n";
	}
	
	return 0;
}