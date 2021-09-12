#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int P;
	cin >> P;
	
	vector<int> lengths;
	
	int length = 0;
	while (lengths.size() < P) {
		int x = 0;
		int y = sqrt(length*length - x*x);
		while (x <= length) {
			do {
				lengths.push_back(x*x + y*y);
				y--;
			} while (x*x + y*y > (length-1)*(length-1) && y >= 0);
			x++;
			y = sqrt(length*length - x*x);
		}
		length++;
	}
	
	sort(lengths.begin(), lengths.end());
	
	cout << lengths.at(P-1);
	
	return 0;
}