#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, B, SG, SB, x;
	cin >> N;
	
	while (N--) {
		cin >> B >> SG >> SB;
		
		multiset<int> green;
		queue<int> tgreen;
		multiset<int> blue;
		queue<int> tblue;
		
		while (SG--) {
			cin >> x;
			green.insert(x);
		}
		while (SB--) {
			cin >> x;
			blue.insert(x);
		}
		
		while (!green.empty() && !blue.empty()) {
			for (int i=0; i<B; i++) {
				if (!green.empty() && !blue.empty()) {
					if (*green.rbegin() > *blue.rbegin()) {
						tgreen.push(*green.rbegin()-*blue.rbegin());
					} else if (*green.rbegin() < *blue.rbegin()) {
						tblue.push(*blue.rbegin()-*green.rbegin());
					}
					green.erase(prev(green.end()));
					blue.erase(prev(blue.end()));
				} else {
					break;
				}
			}
			while (!tgreen.empty()) {
				green.insert(tgreen.front());
				tgreen.pop();
			}
			while (!tblue.empty()) {
				blue.insert(tblue.front());
				tblue.pop();
			}
		}
		
		if (green.empty() && blue.empty()) {
			cout << "green and blue died\n";
		} else if (blue.empty()) {
			cout << "green wins\n";
			for (auto it=green.rbegin(); it!=green.rend(); it++) {
				cout << *it << "\n";
			}
		} else if (green.empty()) {
			cout << "blue wins\n";
			for (auto it=blue.rbegin(); it!=blue.rend(); it++) {
				cout << *it << "\n";
			}
		}
		if (N != 0) cout << "\n";
	}
	
	return 0;
}