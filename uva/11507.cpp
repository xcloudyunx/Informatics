#include <bits/stdc++.h>

using namespace std;

int main() {
	int L;
	string d, cd;
	cin >> L;
	
	while (L) {
		cd = "+x";
		while (--L) {
			cin >> d;
			if (cd == "+x") {
				if (d != "No") {
					cd = d;
				}
			} else if (cd == "-x") {
				if (d == "+y") {
					cd = "-y";
				} else if (d == "-y") {
					cd = "+y";
				} else if (d == "+z") {
					cd = "-z";
				} else if (d == "-z") {
					cd = "+z";
				}
			} else if (cd == "+y") {
				if (d == "+y") {
					cd = "-x";
				} else if (d == "-y") {
					cd = "+x";
				}
			} else if (cd == "-y") {
				if (d == "+y") {
					cd = "+x";
				} else if (d == "-y") {
					cd = "-x";
				}
			} else if (cd == "+z") {
				if (d == "+z") {
					cd = "-x";
				} else if (d == "-z") {
					cd = "+x";
				}
			} else if (cd == "-z") {
				if (d == "+z") {
					cd = "+x";
				} else if (d == "-z") {
					cd = "-x";
				}
			}
		}
		cout << cd << "\n";
		
		cin >> L;
	}
	
	return 0;
}