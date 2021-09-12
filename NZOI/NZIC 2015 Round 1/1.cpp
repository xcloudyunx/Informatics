#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	
	if (N/2 < M) {
		cout << "No";
	} else {
		cout << "Yes";
	}
	
	return 0;
}