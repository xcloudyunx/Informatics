#include <bits/stdc++.h>

using namespace std;

int main() {
	char current;
	cin >> current;
	
	int N;
	cin >> N;
	
	vector<char> past;
	past.push_back(current);
	int number = 1;
	
	for (int i=0; i<N; i++) {
		char z1, z2;
		cin >> z1 >> z2;
		
		if (z2 == current) {
			current = z1;
			if (find(past.begin(), past.end(), current) == past.end()) {
				number++;
				past.push_back(current);
			}
		}
	}
	
	cout << current << endl << number << endl;
	
	return 0;
}