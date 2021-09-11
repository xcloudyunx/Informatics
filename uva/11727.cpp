#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	vector<int> s(3);
	
	cin >> T;
	
	for (int i=1; i<=T; i++) {
		cin >> s.at(0) >> s.at(1) >> s.at(2);
		sort(s.begin(), s.end());
		cout << "Case " << i << ": " << s.at(1) << "\n";
	}
	
	return 0;
}