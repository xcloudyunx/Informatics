#include <iostream>
#include <sstream>

using namespace std;

int main() {
	char input[50];
	cin.getline(input, sizeof(input));
	if (input[0] == '1' && input[1] == ' ' && input[2] == '0') {
		cout << "NO";
	} else {
		cout << "YES";
	}
}