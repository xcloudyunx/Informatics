#include <iostream>
#include <sstream>

using namespace std;

int main() {
	char input[5];
	char* total[2880];
	
	cin.getline(input, sizeof(input));
	int A; stringstream(input) >> A;
	
	int As[2880];
	for (int i=0; i < 2880; i++) {
		As[i] = -1;
	}
	
	for (int i=0; i < A; i++) {
		cin.getline(input, sizeof(input));
		int x; stringstream(input) >> x;
		As[x] = 1;
		total[x] = "A";
	}
	
	cin.getline(input, sizeof(input));
	int B; stringstream(input) >> B;
	
	int Bs[2880];
	for (int i=0; i < 2880; i++) {
		Bs[i] = -1;
	}
	
	for (int i=0; i < B; i++) {
		cin.getline(input, sizeof(input));
		int x; stringstream(input) >> x;
		Bs[x] = 1;
		total[x] = "B";
	}
	
	int halfPoints = 0;
	for (int i=0; i < 1440; i++) {
		if (As[i] != -1) {
			halfPoints++;
		}
		if (Bs[i] != -1) {
			halfPoints++;
		}
	}
	cout << halfPoints << endl;
	
	char* previousWinning = "C";
	int turnAround = 0;
	int totalA = 0;
	int totalB = 0;
	for (int i=0; i<2880; i++) {
		if (total[i] == "A") {
			totalA++;
		} else if (total[i] == "B") {
			totalB++;
		}
		if (totalA > totalB && previousWinning == "B") {
			turnAround++;
		} else if (totalB > totalA && previousWinning == "A") {
			turnAround++;
		}
		if (totalA > totalB) {
			previousWinning = "A";
		} else if (totalB > totalA) {
			previousWinning = "B";
		}
	}
	cout << turnAround << endl;
}