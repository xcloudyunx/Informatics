#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	bool broken;
	while (cin >> n) {
		if (n == 1) {
			cin >> n;
			cout << "Jolly\n";
		} else {
			vector<bool> diff(n, false);
			vector<int> num(2);
			cin >> num.at(0) >> num.at(1);
			if (abs(num.at(0)-num.at(1)) > 0 && abs(num.at(0)-num.at(1)) < n) {
				diff.at(abs(num.at(0)-num.at(1))) = true;
			}
			
			for (int i=2; i<n; i++) {
				cin >> num.at(i%2);
				if (abs(num.at(0)-num.at(1)) > 0 && abs(num.at(0)-num.at(1)) < n) {
					diff.at(abs(num.at(0)-num.at(1))) = true;
				}
			}
			
			broken = false;
			
			for (int i=1; i<n; i++) {
				if (!diff.at(i)) {
					cout << "Not jolly\n";
					broken = true;
					break;
				}
			}
			
			if (!broken) {
				cout << "Jolly\n";
			}
		}
	}
	
	return 0;
}