#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, total;
	string s;
	cin >> T;
	cin.ignore();
	cin.ignore();
	
	while (T--) {
		map<string, int> m;
		total = 0;
		getline(cin, s);
		while (s != "") {
			total++;
			if (m.find(s) == m.end()) {
				m.insert(make_pair(s, 1));
			} else {
				m.at(s)++;
			}
			getline(cin, s);
		}
		for (auto i : m) {
			cout << i.first;
			printf(" %.4f\n", (i.second*100.0f)/total);
		}
		if (T) {
			cout << "\n";
		}
	}
	
	return 0;
}