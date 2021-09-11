#include <bits/stdc++.h>

using namespace std;

int main() {
	int p;
	cin >> p;
	while (p) {
		cout << "Printing order for " << p << " pages:\n";
		if (p%4 == 1) {
			cout << "Sheet 1, front: Blank, 1\n";
			if (p > 1) {
				cout << "Sheet 1, back : 2, Blank\n";
				cout << "Sheet 2, front: Blank, 3\n";
				int one = 5, two = p, three = 4, four = p-1, sheet = 2;
				while (three < two) {
					cout << "Sheet " << sheet << ", back : " << three << ", " << two << "\n";
					sheet++;
					three += 2;
					two -= 2;
					if (three > two) break;
					cout << "Sheet " << sheet << ", front: " << four << ", " << one << "\n";
					four -= 2;
					one += 2;
				}
			}
		} else if (p%4 == 2) {
			cout << "Sheet 1, front: Blank, 1\n";
			cout << "Sheet 1, back : 2, Blank\n";
			int one = 3, two = p-1, three = 4, four = p, sheet = 2;
			while (one < four) {
				cout << "Sheet " << sheet << ", front: " << four << ", " << one << "\n";
				cout << "Sheet " << sheet << ", back : " << three << ", " << two << "\n";
				three += 2;
				two -= 2;
				four -= 2;
				one += 2;
				sheet++;
			}
		} else if (p%4 == 3) {
			cout << "Sheet 1, front: Blank, 1\n";
			cout << "Sheet 1, back : 2, " << p << "\n";
			int one = 3, two = p-2, three = 4, four = p-1, sheet = 2;
			while (one < four) {
				cout << "Sheet " << sheet << ", front: " << four << ", " << one << "\n";
				cout << "Sheet " << sheet << ", back : " << three << ", " << two << "\n";
				three += 2;
				two -= 2;
				four -= 2;
				one += 2;
				sheet++;
			}
		}  else if (p%4 == 0) {
			int one = 1, two = p-1, three = 2, four = p, sheet = 1;
			while (one < four) {
				cout << "Sheet " << sheet << ", front: " << four << ", " << one << "\n";
				cout << "Sheet " << sheet << ", back : " << three << ", " << two << "\n";
				three += 2;
				two -= 2;
				four -= 2;
				one += 2;
				sheet++;
			}
		}
		
		cin >> p;
	}
	
	return 0;
}