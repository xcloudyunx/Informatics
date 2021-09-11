#include <iostream>
#include <vector>

using namespace std;

int main() {
	int A, T;
	cin >> A >> T;
	
	vector<bool>  arrived(2000000000, false);
	
	int people = 0;
	while (A != 0) {
		if (A == 1) {
			people++;
			arrived.at(T) = true;
		} else {
			if (arrived.at(T)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		cin >> A >> T;
	}
	cout << people;
	
	return 0;
}