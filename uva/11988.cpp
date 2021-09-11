#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while (cin >> s) {
		list<char> l;
		auto it = l.begin();
		for (auto i : s) {
			if (i == '[') {
				it = l.begin();
			} else if (i == ']') {
				it = l.end();
			} else {
				l.insert(it, i);
			}
		}
		for (auto i : l) {
			cout << i;
		}
		cout << "\n";
	}
	
	return 0;
}