#include <iostream>

using namespace std;

int main() {
	int K, N;
	cin >> K;
	cin >> N;
	
	int total = 0;
	
	for (int i=1; i<N; i++) {
		total += i;
		cout << i << endl;
	}
	cout << K-total;
}