#include <bits/stdc++.h>

using namespace std;

int main() {
	int S, B, L, R;
	cin >> S >> B;
	
	while (S && B) {
		vector< pair<int, int> > soldiers(S+1);
		for (int i=0; i<=S; i++) {
			soldiers.at(i) = make_pair(i-1, i+1);
		}
		while (B--) {
			cin >> L >> R;
			if (soldiers.at(L).first > 0) {
				soldiers.at(soldiers.at(L).first).second = soldiers.at(R).second;
				cout << soldiers.at(L).first << " ";
			} else {
				cout << "* ";
			}
			if (soldiers.at(R).second < S+1) {
				soldiers.at(soldiers.at(R).second).first = soldiers.at(L).first;
				cout << soldiers.at(R).second << "\n";
			} else {
				cout << "*\n";
			}
		}
		cout << "-\n";
		cin >> S >> B;
	}
	
	return 0;
}