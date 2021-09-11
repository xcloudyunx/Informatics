#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, a, b;
	string s, x;
	bool pal;
	unordered_set<char> punc = {'.', ',', '!', '?', ' ', '(', ')'};
	cin >> T;
	cin.ignore();
	for (int TC=1; TC<=T; TC++) {
		getline(cin, s);
		x = "";
		for (auto i : s) if (punc.find(i) == punc.end()) x.push_back(i);
		a = 0;
		b = x.size()-1;
		pal = true;
		while (a < b) {
			if (x.at(a) != x.at(b)) {
				pal = false;
				break;
			}
			a++;
			b--;
		}
		cout << "Case #" << TC << ":\n";
		if (pal) {
			for (int i=1; i<=100; i++) {
				if (i*i > x.size()) break;
				if (i*i == x.size()) {
					a = i;
					break;
				}
			}
			if (a*a == x.size()) {
				if (a > 1) {
					for (int i=0; i<x.size()/2+1; i++) {
						if (x.at(i) != x.at((a*i)%(a*a-1))) {
							pal = false;
							break;
						}
					}
				}
				if (pal) {
					cout << a << "\n";
					continue;
				}
			}
		}
		cout << "No magic :(\n";
	}
	
	return 0;
}