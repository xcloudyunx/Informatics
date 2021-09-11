#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, D, L, H, Q, P;
	string M, output;
	cin >> T;
	while (T--) {
		cin >> D;
		vector< pair< pair<int, int>, string> > cars(D);
		for(int i=0; i<D; i++) cin >> cars[i].second >> cars[i].first.first >> cars[i].first.second;
		cin >> Q;
		while (Q--) {
			output = "";
			cin >> P;
			for (auto i : cars) {
				if (i.first.first <= P && P <= i.first.second) {
					if (output != "") { output = ""; break; }
					output = i.second;
				}
			}
			if (output == "") cout << "UNDETERMINED\n";
			else cout << output << "\n";
		}
		if (T) cout << "\n";
	}
	
	return 0;
}