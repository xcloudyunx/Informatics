#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, m, gold;
	bool broken;
	cin >> n >> m;
	while (n && m) {
		vi dragons(n);
		for (int i=0; i<n; i++) cin >> dragons[i];
		vi knights(m);
		for (int i=0; i<m; i++) cin >> knights[i];
		sort(dragons.begin(), dragons.end());
		sort(knights.begin(), knights.end());
		
		broken = false;
		gold = 0;
		for (int i=0, k=0; i<n; i++) {
			while (k < m && knights[k] < dragons[i]) k++;
			if (k == m) { broken = true; break; }
			gold += knights[k++];
		}
		
		if (broken) cout << "Loowater is doomed!\n";
		else cout << gold << "\n";
		
		cin >> n >> m;
	}
	
	return 0;
}