#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	
	sort(begin(a), end(a));
	sort(begin(b), end(b));
	
	if (a == b) {
		cout << "yes";
	} else {
		cout << "no";
	}
	
	return 0;
}