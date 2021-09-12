#include <iostream>

using namespace std;

int main() {
	int N, O;
	cin >> N;
	cin >> O;
	
	float average = O / (N-1.0);
	int average1 = average;
	
	if (average == average1) {
		cout << O+average1-1 << " " << O+average1;
	}
	else {
		cout << O+average1 << " " << O+average1;
	}
}