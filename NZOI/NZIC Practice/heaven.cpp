#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	char input[50];
	cin.getline(input, sizeof(input));
	int A, B, C, D;
	stringstream(input) >> A >> B >> C >> D;
	
	int j = N / (A+B);
	int m = N / (C+D);
	j *= 2;
	m *= 2;
	
	if (N % (A+B) != 0) {
		if (N % (A+B) > A) {
			j++;
		}
		j++;
	}
	if (N % (C+D) != 0) {
		if (N % (C+D) > C) {
			m++;
		}
		m++;
	}
	
	cout << m-j;
	
	return 0;
}