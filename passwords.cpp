#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;
	
	for (int j=1; j<=C; j++) {
		int A;
		cin >> A;
		cin.ignore();
		
		vector<string> passwords(A);
		
		for (int i=0; i<A; i++) {
			string tmp;
			getline(cin, tmp);
			tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
			passwords.at(i) = tmp;
		}
		
		int L;
		cin >> L;
		
		cout << "Customer " << j << endl;
		while (L--) {
			int x, y, z;
			char X, Y;
			cin >> x >> y >> z >> X >> Y;
			if (passwords.at(x-1).at(y-1) == X && passwords.at(x-1).at(z-1) == Y) {
				cout << "correct\n";
			} else {
				cout << "error\n";
			}
		}
	}
	
	return 0;
}