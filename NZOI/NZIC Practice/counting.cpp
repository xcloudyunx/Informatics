#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> x;
	vector<int> repeats;
	for (int i=0; i<n; i++) {
		int y;
		cin >> y;
		if (find(x.begin(), x.end(), y) != x.end()) {
			if (find(repeats.begin(), repeats.end(), y) == repeats.end()) {
				repeats.push_back(y);
			}
		}
		x.push_back(y);
	}
	sort(repeats.begin(), repeats.end());
	for (int i : repeats) {
		cout << i << endl;
	}
	
	return 0;
}