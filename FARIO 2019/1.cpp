#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> h(n);
	
	for (int i=0; i<n; i++) cin >> h.at(i);
	
	vector<int> adjP(n, -1);
	vector<int> adjB(n, -1);
	
	bool found1, found2;
	int c;
	
	for (int i=0; i<n; i++) {
		found1 = found2 = false;
		c = 1;
		
		while (true) {
			if (i+c < n) {
				if (h.at(i+c) > h.at(i)) {
					adjP.at(i) = i+c;
					break;
				}
			} else if (found1) {
				break;
			} else {
				found2 = true;
			}
			
			if (i-c >= 0) {
				if (h.at(i-c) > h.at(i)) {
					adjP.at(i) = i-c;
					break;
				}
			} else if (found2) {
				break;
			} else {
				found1 = true;
			}
			
			c++;
		}
		
		found1 = found2 = true;
		c = 1;
		
		while (true) {
			if (i+c < n) {
				if (h.at(i+c) < h.at(i)) {
					adjB.at(i) = i+c;
					break;
				}
			} else if (!found1) {
				break;
			} else {
				found2 = false;
			}
			
			if (i-c >= 0) {
				if (h.at(i-c) < h.at(i)) {
					adjB.at(i) = i-c;
					break;
				}
			} else if (!found2) {
				break;
			} else {
				found1 = false;
			}
			
			c++;
		}
	}
	
	for (int i=0; i<n; i++) {
		vector<int> possible;
		c = adjP.at(i);
		for (int j=0; j<k; j++) {
			if (c != -1) {
				possible.push_back(c);
				c = adjP.at(c);
			} else {
				break;
			}
		}
		
		found1 = false;
		
		for (auto j : possible) {
			c = adjB.at(j);
			for (int l=0; l<k; l++) {
				if (c == i) {
					found1 = true;
					break;
				} else if (c != -1) {
					c = adjB.at(c);
				} else {
					break;
				}
			}
			if (found1) {
				break;
			}
		}
		if (found1) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	
	/*for (auto i : adjP) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : adjB) {
		cout << i << " ";
	}
	cout << endl;*/
	
	return 0;
}