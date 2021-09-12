#include <iostream>
#include <sstream>

using namespace std;

int main() {
	char input[25];
	cin.getline(input, sizeof(input));
	int votes[9];
	stringstream ss(input);
	for (int i=0; i<9; i++) {
		ss >> votes[i];
	}
	
	int pet = 0;
	int vote = -1;
	for (int i=0; i<9; i++) {
		if (votes[i] > vote) {
			vote = votes[i];
			pet = i+1;
		}
	}
	
	cout << "Pet " << pet;
	
	return 0;
}