#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, x;
	long long total;
	cin >> n;
	
	while (n) {
		multiset<int> bills;
		total = 0;
		
		while (n--) {
			cin >> k;
			while (k--) {
				cin >> x;
				bills.insert(x);
			}
			total += *bills.rbegin()-*bills.begin();
			bills.erase(bills.begin());
			bills.erase(prev(bills.end()));
		}
		
		cout << total << "\n";
		
		cin >> n;
	}
	
	return 0;
}