#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	int total = 0;
	for (int i=0; i<n; i++) {
		char input[16];
		cin.getline(input, sizeof(input));
		int p, d; stringstream(input) >> p >> d;
		if (d < p) {
			total += p-d;
		}
	}
	cout << total;
	
	return 0;
}