#include <bits/stdc++.h>

using namespace std;

int main() {
	struct {
		bool operator()(char a, char b) const {
			if (tolower(a) != tolower(b)) return tolower(a) < tolower(b);
			return a < b;
		}
	} customSort;
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		sort(s.begin(), s.end(), customSort);
		do {
			cout << s << "\n";
		} while (next_permutation(s.begin(), s.end(), customSort));
	}
	
	return 0;
}