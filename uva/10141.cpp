#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p, r, cr, t = 1;
	float d, cd;
	string s, cs;
	
	cin >> n >> p;
	while (n || p) {
		cin.ignore();
		while (n--) {
			getline(cin, s);
		}
		cr = 0;
		d = FLT_MAX;
		for (int i=0; i<p; i++) {
			getline(cin, s);
			cin >> d >> r;
			if (r > cr || (r == cr && d < cd)) {
				cr = r;
				cd = d;
				cs = s;
			}
			cin.ignore();
			while (r--) {
				getline(cin, s);
			}
		}
		cout << "RFP #" << t << "\n" << cs << "\n\n";
		t++;
		cin >> n >> p;
	}
	
	return 0;
}