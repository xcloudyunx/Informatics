#include <iostream>
#include <sstream>

using namespace std;

int main() {
	char input[100];
	cin.getline(input, sizeof(input));
	int n, s; stringstream(input) >> n >> s;
	int cards[n];
	int position;
	for (int i=0; i<n; i++) {
		cin >> cards[i];
		if (cards[i] == s) {
			position = i;
		}
	}
	cout << position;
	
	return 0;
}