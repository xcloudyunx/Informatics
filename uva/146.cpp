#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	while (s != "#") {
		if (next_permutation(s.begin(), s.end())) {
			cout << s << "\n";
		} else {
			cout << "No Successor\n";
		}
		
		cin >> s;
	}
	
	return 0;
}