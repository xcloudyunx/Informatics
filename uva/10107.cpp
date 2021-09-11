#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> num;
	int x;
	while (cin >> x) {
		num.push_back(x);
		if (num.size()%2 == 1) {
			nth_element(num.begin(), num.begin()+num.size()/2, num.end());
			cout << num.at(num.size()/2) << "\n";
		} else {
			nth_element(num.begin(), num.begin()+num.size()/2-1, num.end());
			x = num.at(num.size()/2-1);
			nth_element(num.begin(), num.begin()+num.size()/2, num.end());
			
			cout << (x+num.at(num.size()/2))/2 << "\n";
		}
	}
	
	return 0;
}