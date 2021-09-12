#include <iostream>
#include <sstream>

using namespace std;

int main() {
	char input[400];
	cin.getline(input, sizeof(input));
	stringstream ss(input);
	int total = 0;
	int maximum = 0;
	int minimum = 101;
	int x;
	while (ss >> x) {
		maximum = max(maximum, x);
		minimum = min(minimum, x);
		total += x;
	}
	cout << minimum << " " << maximum << " " << total/100;
	
	return 0;
}