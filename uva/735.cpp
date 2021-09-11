#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int cs, p;
	cin >> cs;
	while (cs > 0) {
		p = 0;
		set< tuple<int, int, int> > c;
		for (int i=0; i<=60; i++) {
			if ((i > 20 && i != 50 && ((i%2 != 0 || i/2 > 20) && (i%3 != 0 || i/3 > 20))) || i > cs) continue;
			for (int j=0; j<=60; j++) {
				if ((j > 20 && j != 50 && ((j%2 != 0 || j/2 > 20) && (j%3 != 0 || j/3 > 20))) || i+j > cs) continue;
				for (int k=0; k<=60; k++) {
					if ((k > 20 && k != 50 && ((k%2 != 0 || k/2 > 20) && (k%3 != 0 || k/3 > 20))) || i+j+k > cs) continue;
					if (i+j+k == cs) {
						p++;
						c.insert(make_tuple(min({i, j, k}), i+j+k-min({i, j, k})-max({i, j, k}), max({i, j, k})));
					}
				}
			}
		}
		
		if (p == 0) cout << "THE SCORE OF " << cs << " CANNOT BE MADE WITH THREE DARTS.\n";
		else cout << "NUMBER OF COMBINATIONS THAT SCORES " << cs << " IS " << c.size() << ".\nNUMBER OF PERMUTATIONS THAT SCORES " << cs << " IS " << p << ".\n";
		cout << "**********************************************************************\n";
		
		cin >> cs;
	}
	cout << "END OF OUTPUT\n";
	
	return 0;
}